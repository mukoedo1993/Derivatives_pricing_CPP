#include"SimpleMC8.h"
#include"cmath"
#include"Arrays.h"

using namespace std;

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                        double Spot,
                        const Parameters& Vol,
                        const Parameters&r,
                        unsigned long NumberOfPaths,
                        StatisticsMC& gatherer,
                        RandomBase& generator
                        )
{
    generator.ResetDimensionality(1);

    double Expiry =TheOption.GetExpiry();

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
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff*discounting);
    }

    return;
}