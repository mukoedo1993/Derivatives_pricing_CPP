#include"SimpleMC.h"
#include"Random1.h"

#include<cmath>

double SimpleMonteCarlo2(const PayOff& thePayOff,
                        double Expiry,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths)
{
    double variance=Vol*Vol*Expiry;
    double rootVariance=sqrt(variance);
    double itoCorrection= -0.5*variance;

    double movedSpot =Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;

    for(unsigned long i=0;i<NumberOfPaths;i++)
    {
        double thisGaussian= GetOneGaussianBySTL();
        thisSpot=movedSpot*exp(rootVariance*thisGaussian);
        double thisPayOff= thePayOff(thisSpot);//call operator
        runningSum+=thisPayOff;
    }

    double mean=runningSum/NumberOfPaths;
    mean*=exp(-r*Expiry);
    return mean;
}