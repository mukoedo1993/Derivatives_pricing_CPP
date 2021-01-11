#ifndef SIMPLEMC8_H
#define SIMPLEMC8_H

#include"Vanilla3.h"
#include"Parameters.h"
#include"Random2.h"
#include"MCStatistics.h"
/*
*
*
*/

#include"SimpleMC8.h"
#include"cmath"
#include"Arrays.h"
#include<functional>
using namespace std;

template<class T, double(T::*Get)()const,
        double(T::*Option)(double)const>
void SimpleMonteCarlo6(const T& TheOption,
                        double Spot,
                        const Parameters& Vol,
                        const Parameters&r,
                        unsigned long NumberOfPaths,
                        StatisticsMC& gatherer,
                        RandomBase& generator
                        )
{
    generator.ResetDimensionality(1);

    double Expiry =std::mem_fn(Get)(TheOption);

    double variance = Vol.Integral(0,Expiry);

    double rootVariance = sqrt(variance);

    double itoCorrection = -0.5*variance;

    double movedSpot = Spot*exp(r.Integral(0,Expiry)
                                +itoCorrection);
    
    double thisSpot;

    double discounting = exp(-r.Integral(0,Expiry));

    MJArray VariateArray(1);

    for(unsigned long i=0;i<NumberOfPaths;++i)
    {
        generator.GetGaussians(VariateArray);
        thisSpot = movedSpot*exp(rootVariance*VariateArray[0]);
        double thisPayOff = std::mem_fn(Option)(TheOption,thisSpot);
        gatherer.DumpOneResult(thisPayOff*discounting);
    }

    return;
}



#endif