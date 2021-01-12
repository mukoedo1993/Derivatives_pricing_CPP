#include"PayOffDoubleDigital.h"
PayOffDoubleDigital1::PayOffDoubleDigital1(double Strike_) : Strike(Strike_)
{
}

double PayOffDoubleDigital1::operator () (double Spot) const
{
    return Spot>=Strike?1.0:0.0;
}

unique_ptr<PayOff> PayOffDoubleDigital1::clone() const
{
    return std::make_unique<PayOffDoubleDigital1>(*this);
}


PayOffDoubleDigital2::PayOffDoubleDigital2(double Strike_) : Strike(Strike_)
{
}

double PayOffDoubleDigital2::operator () (double Spot) const
{
    return Spot>Strike?0.0:1.0;
}

unique_ptr<PayOff> PayOffDoubleDigital2::clone() const
{
    return std::make_unique<PayOffDoubleDigital2>(*this);
}