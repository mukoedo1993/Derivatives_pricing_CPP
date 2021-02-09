#include "PayOff3.h"
#include <algorithm>
using std::max;
PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator () (double Spot) const
{
    return max(Spot-Strike,0.0);
}

shared_ptr<PayOff> PayOffCall::clone() const
{
    return std::make_unique<PayOffCall>(*this);
}


double PayOffPut::operator () (double Spot) const
{
    return max(Strike-Spot,0.0);
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

shared_ptr<PayOff> PayOffPut::clone() const
{
    return std::make_unique<PayOffPut>(*this);
}