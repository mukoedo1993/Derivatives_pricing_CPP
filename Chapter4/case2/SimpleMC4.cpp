#include"SimpleMC4.h"
#include"Random1.h"
#include<cmath>

//the basic math functions should be in namespace std
//but aren't in VCP66
double SimpleMonteCarlo4(const VanillaOption& TheOption,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths)
{
    double Expiry = TheOption.GetExpiry();

    double variance = Vol*Vol*Expiry;
    double rootVariance=sqrt(variance);
    double itoCorrection=-0.5*variance;

    double movedSpot = Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;

    for(unsigned long i=0;i<NumberOfPaths;i++)
    {
        double thisGaussian= GetOneGaussianBySTL();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        runningSum+=thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}