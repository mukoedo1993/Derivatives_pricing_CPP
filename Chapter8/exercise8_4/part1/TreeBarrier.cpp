#include"TreeBarrier.h"
#include<algorithm>
using std::max;
//knock-in call-style options
TreeBarrier::TreeBarrier(double FinalTime,
                            const PayOffBridge& ThePayOff_,
                            double Barrier_)
                    : TreeProduct(FinalTime),
                    ThePayOff(ThePayOff_),Barrier(Barrier_)
{

}

TreeProduct* TreeBarrier::clone()const {
    return new TreeBarrier(*this);
    
    }

double TreeBarrier::FinalPayOff(double Spot)const {
    return (Spot>=Barrier?1.0:0.0);
    
    
    }

double TreeBarrier::PreFinalValue(double Spot,
                                double,
                                double DiscountedFutureValue)const
{
    return max(DiscountedFutureValue,(Spot>=Barrier?1.0:0.0));                          
}