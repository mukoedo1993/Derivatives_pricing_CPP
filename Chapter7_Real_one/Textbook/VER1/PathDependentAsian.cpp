#include"PathDependentAsian.h"

PathDependentAsian::PathDependentAsian(const MJArray&
                                        LookAtTimes_,
                                        double DeliveryTime_,
                                        const PayOffBridge&ThePayOff_)
                                        :
                                        PathDependent(LookAtTimes_),
                                        DeliveryTime(DeliveryTime_),
                                        ThePayOff(ThePayOff_),
                                        NumberOfTimes(LookAtTimes_.size())
{

}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const
{
    return 1UL;
}

MJArray PathDependentAsian::PossibleCashFlowTimes()const {
    MJArray tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
    
    }

unsigned long PathDependentAsian::CashFlows(const MJArray&
                                            SpotValues,
                                std::vector<CashFlow>& GeneratedFlows)const {
   
    double sum = SpotValues.sum();
    double mean = sum/NumberOfTimes;

    GeneratedFlows[0].TimeIndex = 0UL;

    GeneratedFlows[0].Amount = ThePayOff(mean);

    return 1UL;
    
    }


    PathDependent* PathDependentAsian::clone()const {
    return new PathDependentAsian(*this);
    
    }