#ifndef PAYOFF3_H
#define PAYOFF3_H
#include<memory>
using std::unique_ptr;
class PayOff
{
public:

    PayOff(){};

    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){}
    virtual unique_ptr<PayOff> clone() const=0;

private:
    
};

class PayOffCall : public PayOff
{
public:

    PayOffCall(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffCall(){}
    virtual unique_ptr<PayOff> clone() const override;

private:

    double Strike;

};


class PayOffPut : public PayOff
{
public:

    PayOffPut(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffPut(){}
    virtual unique_ptr<PayOff> clone() const override;

private:

    double Strike;

};

#endif