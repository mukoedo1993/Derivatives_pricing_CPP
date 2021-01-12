#include "PayOff3.h"
#include <algorithm>
using std::max;
#ifndef PAYOFFSTRADDLE_H
#define PAYOFFSTRADDLE_H


class PayOffStraddle : public PayOff
{
public:

    PayOffStraddle(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffStraddle(){}
    virtual unique_ptr<PayOff> clone() const override;

private:

    double Strike;

};



#endif