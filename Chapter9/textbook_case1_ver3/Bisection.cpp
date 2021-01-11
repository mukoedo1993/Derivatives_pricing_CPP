#include"Bisection.h"

double Bisection(double Target,
double Low,
double High,
double Tolerance,
const std::function<double(double)>& TheFunction)
{
    double x=0.5*(Low+High);
    double y = TheFunction(x);


    do{
        if(y<Target)
            Low = x;
        if(y>Target)
            High = x;
        
        x = 0.5*(Low+High);

        y = TheFunction(x);
    }
    while
    ((abs(y-Target)>Tolerance));

    return x;

}