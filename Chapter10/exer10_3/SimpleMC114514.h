#ifndef SIMPLEMC114514_H
#define SIMPLEMC114514_H
#include<cmath>
#include"Random1.h"
using namespace std;
double SimpleMonteCarlo1(double Expiry,
                        double Strike,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths);

#endif