#ifndef TREE_BARRIER_H
#define TREE_BARRIER_H

#include"TreeProducts.h"
#include"PayOffBridge.h"
//knock-in call-style options (of Barrier option)
class TreeBarrier: public TreeProduct 
{
public:
    TreeBarrier(double FinalTime,
                const PayOffBridge& ThePayOff_,
                double Barrier_);
    
    virtual TreeProduct* clone()const override;
    virtual double FinalPayOff(double Spot)const override;
    virtual double PreFinalValue(double Spot,
                                double Time,
                                double DiscountedFutureValue)
                                const override;

    virtual ~TreeBarrier(){}

private:
    PayOffBridge ThePayOff;
    double Barrier;
};


#endif