#ifndef TREE_EUROPEAN_H
#define TREE_EUROPEAN_H

#include"TreeProducts.h"
#include"PayOffBridge.h"

class TreeEuropean: public TreeProduct 
{
public:
    TreeEuropean(double FinalTime,
                const PayOffBridge& ThePayOff_);
    
    virtual TreeProduct* clone()const override;
    virtual double FinalPayOff(double Spot)const override;
    virtual double PreFinalValue(double Spot,
                                double Time,
                                double DiscountedFutureValue)
                                const override;

    virtual ~TreeEuropean(){}

private:
    PayOffBridge ThePayOff;
};


#endif