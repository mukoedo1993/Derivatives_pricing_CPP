#include"PayOffStraddle.h"
PayOffStraddle::PayOffStraddle(double Strike_) : Strike(Strike_)
{
}

double PayOffStraddle::operator () (double Spot) const
{
    return max(Spot-Strike,Strike-Spot);
}

unique_ptr<PayOff> PayOffStraddle::clone() const
{
    return std::make_unique<PayOffStraddle>(*this);
}
