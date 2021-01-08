#include "ExoticBSEngine.h"
#include <cmath>

void ExoticBSEngine::GetOnePath(MJArray& SpotValues) 
{

    TheGenerator->GetGaussians(Variates);

    double CurrentLogSpot = LogSpot;

    for (unsigned long j=0; j < NumberOfTimes; j++)
    {
        CurrentLogSpot += Drifts[j];
        CurrentLogSpot += StandardDeviations[j]*Variates[j];
        SpotValues[j] = exp(CurrentLogSpot);
    }

    return;
}

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
                                    const Parameters& R_,
                                    const Parameters& D_,
                                    const Parameters& Vol_,
                                    const Wrapper<RandomBase>& TheGenerator_,
                                    double Spot_)
                                    :
                                    ExoticEngine(TheProduct_,R_),
                                    TheGenerator(TheGenerator_)
{
    MJArray Times(TheProduct_->GetLookAtTimes());
    NumberOfTimes = Times.size();

    TheGenerator->ResetDimensionality(NumberOfTimes);

    Drifts.resize(NumberOfTimes);
    StandardDeviations.resize(NumberOfTimes);

    double Variance = Vol_.IntegralSquare(0,Times[0]);

    Drifts[0] = R_.Integral(0.0,Times[0]) - D_.Integral(0.0,Times[0]) - 0.5 * Variance;
    StandardDeviations[0] = sqrt(Variance);

    for (unsigned long j=1; j < NumberOfTimes; ++j)
    {   
        double thisVariance = Vol_.IntegralSquare(Times[j-1],Times[j]);
        Drifts[j] = R_.Integral(Times[j-1],Times[j]) - D_.Integral(Times[j-1],Times[j]) 
                    - 0.5 * thisVariance;
        StandardDeviations[j] = sqrt(thisVariance);
    }

    LogSpot = log(Spot_);                                   
    Variates.resize(NumberOfTimes);
}

/*
* The integrals and square-roots are the same for every path and so can be
* precomputed. The constructor therefore gets the times from the product, and uses them
* to compute the integrals of the drifts and the standard deviations which are stored
* as data members.
*/

  /*
        * The integrals and square-roots are the same for every path and so can 
        * be precomputed. THe constructor therefore gets the times from the product,
        * and uses them to compute the integrals of the drifts and the standard deviations
        * which are stored as data members. Note that the class does not bother to store the
        * times as it is only the constructor which needs to know what they are. In any case, the product
        * is passed up to the base class and it could be retrieved if needed.
        */

/*
* As we have done a lot of precomputation in the constructor, the routine to actually generate
* a path is fairly simple. We simply get the variates from the generator and loop through
* the times. For each time, we add the integrated drift to the log, and then add the product of
* the random number and the standard deviation. To and then add the product of calls to log and exp,
* we keep track of the log of spot at all times, and convert into spot values as necessary.
* We thus have NumberOfTimes calls to exp each path and no calls to log. 
*/

/*
* For certain products such as a geometric Asian option this might well be faster as it would
*only involve one exponentiation instead of many. The main downside would be that for certain
* processes, such as a normal process or displaced diffusion, one might end up having to take 
* unnecessary logs.
*/
