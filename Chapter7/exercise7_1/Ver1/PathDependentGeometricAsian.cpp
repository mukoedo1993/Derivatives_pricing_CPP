#include"PathDependentGeometricAsian.h"
#include<cmath>
#include<iostream>
PathDependentGeometricAsian::PathDependentGeometricAsian(const MJArray&
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

unsigned long PathDependentGeometricAsian::MaxNumberOfCashFlows() const
{
    return 1UL;
}

MJArray PathDependentGeometricAsian::PossibleCashFlowTimes()const {
    MJArray tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
    
    }

unsigned long PathDependentGeometricAsian::CashFlows(const MJArray&
                                            SpotValues,
                                std::vector<CashFlow>& GeneratedFlows)const {
   
    double log_sum=0;
   for(unsigned long i=0;i<SpotValues.size();++i)
    log_sum+= log(SpotValues[i]);
   
    double mean = exp(log_sum/static_cast<double>(SpotValues.size()));

    GeneratedFlows[0].TimeIndex = 0UL;

    GeneratedFlows[0].Amount = ThePayOff(mean);

    return 1UL;
    
    }


    PathDependent* PathDependentGeometricAsian::clone()const {
    return new PathDependentGeometricAsian(*this);
    
    }