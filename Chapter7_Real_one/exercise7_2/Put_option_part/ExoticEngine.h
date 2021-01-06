# ifndef EXOTIC_ENGINE_H
# define EXOTIC_ENGINE_H
#include"Wrapper.h"
#include"Parameters.h"
#include"PathDependent.h"
#include"MCStatistics.h"
#include<vector>

class ExoticEngine{
public:
    ExoticEngine(const Wrapper<PathDependent>&
                TheProduct_, const Parameters& r_);
    /*
    *The constructor stores the inputs, computes the discount factors necessary,
    * and makes sure the cash-flows vector is of the correct size. The DoSimulation
    * method loops through all the paths, calling GetOnePath to get the array of spot
    * value and then passes them into DoOnePath to get the value for the set of spot values.
    * This value is then dumped into the statistics gatherer.
    * DoOnePath is only slightly more complicated. The array of spot values is passed into
    * the product to get the cash-flows. These cash-flows are then looped over and discounted
    * appropriately. This discounting is simplified by using the precomputated discount factors.
    * 
    * We have now set up the structure for pricing path-dependent exotic derivatives but
    * we still have to actually define the classes which will do the path generation and
    * define the products.
    * 
    */
    

    virtual void GetOnePath(MJArray& SpotValues)=0;
//The implicit assumption that the array passed into GetOnePath is of the
//correct size. 
    void DoSimulation(StatisticsMC& TheGatherer,
                     unsigned long NumberOfPaths);

    virtual ~ExoticEngine(){}
    double DoOnePath(const MJArray& SpotValues)const;

private:
    Wrapper<PathDependent> TheProduct;

    Parameters r;
    /*
    *We store our interest rates here so we could delegate computation of integrals to
    *the Parameters class, and not have to worry about them here.
    */

    MJArray Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
    /*
    *We might want to change values even in a const variable. 
    */

};




#endif