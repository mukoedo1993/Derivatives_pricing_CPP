#include"SimpleMC114514.h"
double SimpleMonteCarlo1(double Expiry,
                        double Strike,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths)
{
    double variance=Vol*Vol*Expiry;
    double rootVariance=sqrt(variance);
    double itoCorrection=-0.5*variance;

    

    double movedSpot=Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;

    for(unsigned long i=0;i<NumberOfPaths;i++){
        double thisGaussian=GetOneGaussianBySystem();
        thisSpot=movedSpot*exp(rootVariance*thisGaussian);
        runningSum+=thisSpot;
    }
    double mean=runningSum/NumberOfPaths;
    mean*=exp(-r*Expiry);
    return mean;
                        
}