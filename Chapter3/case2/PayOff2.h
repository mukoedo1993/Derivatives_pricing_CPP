#ifndef PAYOFF2_H
#define pAYOFF2_H

class PayOff{
    public: 
    PayOff(){}
    virtual double operator()(double Spot)const=0;
    virtual ~PayOff(){}
};

class PayOffCall:public PayOff
{

public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot)const override;
    virtual ~PayOffCall(){}

private:
    double Strike;
};


class PayOffPut: public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot)const override;
    virtual ~PayOffPut(){}
    private:
    double Strike;
};



#endif
