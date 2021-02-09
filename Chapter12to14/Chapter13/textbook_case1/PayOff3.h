#ifndef PAYOFF3_H
#define PAYOFF3_H
#include<memory>
using std::shared_ptr;
class PayOff
{
public:

    PayOff(){};

    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){}
    virtual shared_ptr<PayOff> clone() const=0;

private:
    
};

class PayOffCall : public PayOff
{
public:

    PayOffCall(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffCall(){}
    virtual shared_ptr<PayOff> clone() const override;

private:

    double Strike;

};


class PayOffPut : public PayOff
{
public:

    PayOffPut(double Strike_);

    virtual double operator()(double Spot) const override;
    virtual ~PayOffPut(){}
    virtual shared_ptr<PayOff> clone() const override;

private:

    double Strike;

};

#endif