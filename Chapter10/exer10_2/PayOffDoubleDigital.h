#include "PayOff3.h"
#include <algorithm>
#include<iostream>
using std::max;
#ifndef PAYOFFDOUBLEDIGITAL_H
#define PAYOFFDOUBLEDIGITAL_H


class PayOffDoubleDigital1 : public PayOff
{
public:

    PayOffDoubleDigital1(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffDoubleDigital1(){}
    virtual unique_ptr<PayOff> clone() const override;

private:

    double Strike;

};


class PayOffDoubleDigital2 : public PayOff
{
public:

    PayOffDoubleDigital2(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffDoubleDigital2(){}
    virtual unique_ptr<PayOff> clone() const override;

private:

    double Strike;

};



#endif