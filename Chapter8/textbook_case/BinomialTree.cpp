#include"BinomialTree.h"
#include"Arrays.h"
#include<cmath>

SimpleBinomialTree::SimpleBinomialTree(double Spot_,
                    const Parameters& r_,
                    const Parameters& d_,
                    double Volatility_,
                    unsigned long Steps_,
                    double Time_)
                    :Spot(Spot_),
                    r(r_),
                    d(d_),
                    Volatility(Volatility_),
                    Steps(Steps_),
                    Time(Time_),
                    Discounts(Steps),
                    TreeBuilt(false)
{

}

void SimpleBinomialTree::BuildTree()
{
    TreeBuilt = true;
    TheTree.resize(Steps+1);

    double InitialLogSpot = log(Spot);

    for(unsigned long i = 0; i <=Steps; ++i)
    {
        TheTree[i].resize(i+1);

        double thisTime = (i*Time)/Steps;

        double movedLogSpot = 
                InitialLogSpot + r.Integral(0.0,thisTime)
                                -d.Integral(0.0,thisTime);

        movedLogSpot -=
                    0.5*Volatility*Volatility*thisTime;
        
        double sd = Volatility*sqrt(Time/Steps);

        for(long j=-static_cast<long>(i),k=0;
            j<static_cast<long>(i);j=j+2,k++)
                TheTree[i][k].first = exp(movedLogSpot+ j*sd);

    }
    
    for(unsigned long l=0;l<Steps;l++)
    {
        Discounts[l] = 
        exp(-r.Integral(l*Time/Steps,(l+1)*Time/Steps));
    }
}


double SimpleBinomialTree::GetThePrice(const TreeProduct& TheProduct)
{

    if(!TreeBuilt)
        BuildTree();

    if(TheProduct.GetFinalTime()!=Time)
      throw("mismatched product in SimpleBinomialTree");


/*
* Note that as we are dealing with points in the tree corresponding to down 
* moves we count using a long. This long has to be compared to the unsigned long i
* for the termination condition. We therefore have to be careful; if we simply compare these
* numbers a likely effect is that the routine will conclude that -1 is bigger than 1. Why? The
* compiler will implicitly convert the long into a large unsigned long. Clearly this is 
*not the desired effect so we convert the unsigned long into a long before the comparison.
*/
    for( long j=-static_cast<long>(Steps),k=0;
       j<=static_cast<long>(Steps);j=j+2,k++)
       TheTree[Steps][k].second = 
        TheProduct.FinalPayOff(TheTree[Steps][k].first);

    for(unsigned long i=1; i<=Steps; i++)
    {
        unsigned long index = Steps-i;
        double ThisTime = index*Time/Steps;

        for(long j=-static_cast<long>(index),k=0;
        j<=static_cast<long>(index);j=j+2,k++)
        {
            double Spot = TheTree[index][k].first;

            double futureDiscountedValue = 0.5*Discounts[index]*
            (TheTree[index+1][k].second +
            TheTree[index+1][k+1].second);

            TheTree[index][k].second =
            TheProduct.PreFinalValue(Spot,ThisTime,
                                    futureDiscountedValue);

    
        }
    }

    return TheTree[0][0].second;
}
