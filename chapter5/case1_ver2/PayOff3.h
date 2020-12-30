#ifndef PAYOFF3_H
#define PAYOFF3_H
#include<memory>
class PayOff
{
    public:
        PayOff(){}

        virtual double operator()(double Spot)const=0;
        virtual ~PayOff();
         virtual  std::shared_ptr<PayOff> clone()const=0;
       
        
};


class PayOffCall:public PayOff
{
    public:
    PayOffCall(double Strike_);

    double operator()(double Spot)const override;
    virtual ~PayOffCall();//In some compilers we cannot override return type.
     std::shared_ptr<PayOff> clone()const
     {
         return std::make_shared<PayOffCall>(*this);
     }
    private:
        double Strike;
};
 
class PayOffPut:public PayOff
{
    public:
    PayOffPut(double Strike_);

    virtual double operator()(double Spot)const override;
    virtual ~PayOffPut();
    std::shared_ptr<PayOff> clone()const
     {
         return std::make_shared<PayOffPut>(*this);
     }
    private:
            double Strike;
};

#endif