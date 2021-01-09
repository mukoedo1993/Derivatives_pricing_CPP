/*
Rather than give a template function here, thanks for C++11, we could use 
a template function here.
*/

#ifndef BISECTION_H
#define BISECTION_H
#include<cmath>
#include<functional>

double Bisection(double Target,
double Low,
double High,
double Tolerance,
std::function<double(double)> TheFunction)
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
#endif
/*
We only present a header file, since for template code we cannot precompile in a source file
-- we do not know the type of the object T. The function is quite simple. We specify that it
* is templatized via the template<class T> at the top. 
*/