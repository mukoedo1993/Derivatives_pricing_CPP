#ifndef PATH_DEPENDENT_H
#define PATH_DEPENDENT_H
#include "Arrays.h"
#include <vector>

class CashFlow
{
public:

    double Amount;
    unsigned long TimeIndex;
    
    CashFlow(unsigned long TimeIndex_=0UL, double Amount_=0.0) 
                : TimeIndex(TimeIndex_),
                  Amount(Amount_){}
 

};

class PathDependent
{
public:

    PathDependent(const MJArray& LookAtTimes);

    const MJArray& GetLookAtTimes() const;

    virtual unsigned long MaxNumberOfCashFlows() const=0;
    virtual MJArray PossibleCashFlowTimes() const=0;
    virtual unsigned long CashFlows(const MJArray& SpotValues, 
                                    std::vector<CashFlow>& GeneratedFlows) const=0;
    virtual PathDependent* clone() const=0;

    virtual ~PathDependent(){}

private:

    MJArray LookAtTimes;

};

#endif