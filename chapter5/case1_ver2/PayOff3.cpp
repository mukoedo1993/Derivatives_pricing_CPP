#include"PayOff3.h"
#include<algorithm>
#include<memory>
PayOff::~PayOff(){}
PayOffCall::PayOffCall(double Strike_):Strike(Strike_)
{

}

double PayOffCall::operator()(double Spot)const
{
    return std::max(Spot-Strike,0.0);
}


PayOffCall::~PayOffCall(){}
PayOffPut::PayOffPut(double Strike_):Strike(Strike_)
{

}
double PayOffPut::operator()(double Spot)const
{
    return std::max(Strike-Spot,0.0);
}


PayOffPut::~PayOffPut(){}