#include"PathDependentKnockOut1.h"
#include<cmath>
#include<iostream>
PathDependentKnockOut1::PathDependentKnockOut1(const MJArray&
                                        LookAtTimes_,
                                        double DeliveryTime_,
                                        const PayOffBridge&ThePayOff_,
                                        double Barrier_,
                                        double Rebate_)
                                        :
                                        PathDependent(LookAtTimes_),
                                        DeliveryTime(DeliveryTime_),
                                        ThePayOff(ThePayOff_),
                                        NumberOfTimes(LookAtTimes_.size()),
                                        Barrier(Barrier_),
                                        Rebate(Rebate_)
{

}

unsigned long PathDependentKnockOut1::MaxNumberOfCashFlows() const
{
    return NumberOfTimes;
}

MJArray PathDependentKnockOut1::PossibleCashFlowTimes()const {
   
    MJArray tmp=PathDependent::GetLookAtTimes();
  return tmp;
    
    }

unsigned long PathDependentKnockOut1::CashFlows(const MJArray&
                                            SpotValues,
                                std::vector<CashFlow>& GeneratedFlows)const {
 
   for( unsigned long i=0;i<NumberOfTimes;++i)
   {
     
    
     if(SpotValues[i]<=Barrier)
      {
  
           GeneratedFlows[i].Amount = Rebate;
           return i+1;
      }
   }
    GeneratedFlows[NumberOfTimes-1].Amount = ThePayOff(SpotValues[NumberOfTimes-1]);
    return NumberOfTimes;
    
    }


    PathDependent* PathDependentKnockOut1::clone()const {
    return new PathDependentKnockOut1(*this);
    
    }