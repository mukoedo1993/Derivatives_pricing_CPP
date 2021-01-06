#include"ExoticEngine.h"
#include<cmath>

/*
*   The constructor stores the inputs, computes the discount factors necessary,
* and make sure the cash-flows vector is of the correct size. The DoSimulation method
* loops through all the paths, calling GetOnePath to get the array of spot value and then
* passes them into DoOnePath to get the value for that set of spot values. This value is then
* dumped into the statistics gatherer. 
* 
* DoOnePath is only slightly more complicated. The array of spot values is passed into the
* product to get the cash-flows. These cash-flows are then looped over and discounted appropriately.
* The discounting is simplified by using the precomputed discount factors. 
* We have now set up the structure for pricing path-dependent exotic derivatives but we still
*have to actually define the classes which will do the path generation and define the results.
*
*
*/


ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& TheProduct_,
                 const Parameters& r_)
                 :
                 TheProduct(TheProduct_),
                 r(r_),
                 Discounts(TheProduct_->PossibleCashFlowTimes())
{
    for (unsigned long i=0; i < Discounts.size(); i++)
        Discounts[i] = exp(-r.Integral(0.0, Discounts[i]));
     
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths)
{
    MJArray SpotValues(TheProduct->GetLookAtTimes().size());

    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
    double thisValue;
    
    for (unsigned long i =0; i < NumberOfPaths; ++i)
    {
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        TheGatherer.DumpOneResult(thisValue);
    }

    return;
}

double ExoticEngine::DoOnePath(const MJArray& SpotValues) const
{
    unsigned long NumberFlows = TheProduct->CashFlows(SpotValues,
                                                      TheseCashFlows);
    double Value=0.0;
    
    for (unsigned i =0; i < NumberFlows; ++i)
        Value += TheseCashFlows[i].Amount * Discounts[TheseCashFlows[i].TimeIndex];

    return Value;
}

