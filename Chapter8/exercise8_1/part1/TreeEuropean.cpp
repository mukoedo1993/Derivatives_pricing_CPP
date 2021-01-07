#include"TreeEuropean.h"
#include<algorithm>
using std::max;
/*
* The implementations of the methods are very simple-- all the pay-offs are
* subcontracted to the PayOffBridge class in any case. For the European option
* at a interior node, the rule for computing the PreFinalValue is very simple: just
* return the discounted future value that was input. For the American option, it is only
* slightly harder; we take the maximum with the intrinsic value.
*

*/
TreeEuropean::TreeEuropean(double FinalTime, 
                           const PayOffBridge& ThePayOff_)
                        :TreeProduct(FinalTime),
                        ThePayOff(ThePayOff_)
{

}

double TreeEuropean::FinalPayOff(double Spot)const
{
    return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double,double,double DiscountedFutureValue)const
{
    return DiscountedFutureValue;
}

TreeProduct* TreeEuropean::clone() const {
        return new TreeEuropean(*this);
}