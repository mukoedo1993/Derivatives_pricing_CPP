#ifndef PATH_DEPENDENT_ASIAN_H
#define PATH_DEPENDENT_ASIAN_H

#include"PathDependent.h"
#include"PayOffBridge.h"

class PathDependentGeometricAsian : public PathDependent
{
public:
    PathDependentGeometricAsian(const MJArray& LookAtTimes_,
                       double DeliveryTime_,
                       const PayOffBridge& ThePayOff_);

    unsigned long MaxNumberOfCashFlows()const override;
    MJArray PossibleCashFlowTimes() const override;
     virtual unsigned long CashFlows(const MJArray& SpotValues,
                                    std::vector<CashFlow>&
                                    GeneratedFlows)const override;
    virtual ~PathDependentGeometricAsian(){}
    virtual PathDependent* clone()const override;

private:
    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned long NumberOfTimes;
};

/*
* The methods defined are just ones required by the base class. We pass in the averaging
* times as an array and we provide a separate delivery time to allow for the possibility
*that the pay-off occurs at some time after the last averaging date. 
*/

#endif