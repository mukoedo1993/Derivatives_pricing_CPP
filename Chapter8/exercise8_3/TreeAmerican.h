/*
*We provide below two concrete implementations of tree products:
* the European option and the American option.
*
* As we specify the pay-off using the PayOffBridge class, we do not
* need to write separate classes for calls and puts.
*
*/

#ifndef TREE_AMERICAN_H
#define TREE_AMERICAN_H

#include"TreeProducts.h"
#include"PayOffBridge.h"

class TreeAmerican: public TreeProduct 
{
public:
    TreeAmerican(double FinalTime,
                const PayOffBridge& ThePayOff_);
    
    virtual TreeProduct* clone()const override;
    virtual double FinalPayOff(double Spot)const override;
    virtual double PreFinalValue(double Spot,
                                double Time,
                                double DiscountedFutureValue)
                                const override;

    virtual ~TreeAmerican(){}

private:
    PayOffBridge ThePayOff;
};


#endif