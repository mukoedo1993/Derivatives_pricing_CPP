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
const std::function<double(double)>& TheFunction);

#endif
/*
We only present a header file, since for template code we cannot precompile in a source file
-- we do not know the type of the object T. The function is quite simple. We specify that it
* is templatized via the template<class T> at the top. 
*/