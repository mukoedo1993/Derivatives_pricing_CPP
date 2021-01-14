#include"PayOff1.h"
#include<algorithm>
#include<stdexcept>
PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
:Strike(Strike_),TheOptionsType(TheOptionsType_)
{
   
}
double PayOff::operator()(double spot)const
{
    switch(TheOptionsType)
    {
        case call:
        return std::max<double>(spot-Strike,0.0);
        case put:
        return std::max<double>(Strike-spot,0.0);

        default:
        throw std::invalid_argument("unknown option type found.");
    }
    return 0.0;
}


