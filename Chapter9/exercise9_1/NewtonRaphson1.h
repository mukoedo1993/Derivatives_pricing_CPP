
#include<cmath>
#include<stdexcept>
#include<iostream>
template<class T, double (T::*Value)(double)const,
                  double (T::*Derivative)(double)const>
                  double NewtonRaphson(double Target,
                                       double Start,
                                       double Tolerance,
                                       const T& TheObject)
{
    double y = (TheObject.*Value)(Start);
    double x = Start;
    unsigned times=0;
    
    while(abs(y-Target)>Tolerance)
    {
        
        if(times>10000U)
        throw std::out_of_range("error!The program was run More the maximum number of time.");
       double d = (TheObject.*Derivative)(x);
        x+= (Target-y)/d;
        y = (TheObject.*Value)(x);
        times++;
         
    }
    return x;
}
