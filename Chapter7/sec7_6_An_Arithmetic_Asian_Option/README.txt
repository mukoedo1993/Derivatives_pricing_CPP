Note that our option only ever returns one cash-flow so the maximum number of cash-flows is 1.
It only ever generates cash-flows at the delivery time so the PossibleCashFLowTimes is straightforward too. 

We just need to slightly change PathDependentAsian::CashFlow to get the PathDependentGeometricAsian's version.
But we need to slightly change it for knock-out options.



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
