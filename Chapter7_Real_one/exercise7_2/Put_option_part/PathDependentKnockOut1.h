#ifndef PATH_DEPENDENT_ASIAN_H
#define PATH_DEPENDENT_ASIAN_H

#include"PathDependent.h"
#include"PayOffBridge.h"

class PathDependentKnockOut1 : public PathDependent
{
public:
    PathDependentKnockOut1(const MJArray& LookAtTimes_,
                       double DeliveryTime_,
                       const PayOffBridge& ThePayOff_,
                       double Barrier_,
                       double Rebate_);

    unsigned long MaxNumberOfCashFlows()const override;
    MJArray PossibleCashFlowTimes() const override;
     virtual unsigned long CashFlows(const MJArray& SpotValues,
                                    std::vector<CashFlow>&
                                    GeneratedFlows)const override;
    virtual ~PathDependentKnockOut1(){}
    virtual PathDependent* clone()const override;

private:
    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned long NumberOfTimes;
    double Barrier;
    double Rebate;
};

/*
* The methods defined are just ones required by the base class. We pass in the averaging
* times as an array and we provide a separate delivery time to allow for the possibility
*that the pay-off occurs at some time after the last averaging date. 
*/

#endif