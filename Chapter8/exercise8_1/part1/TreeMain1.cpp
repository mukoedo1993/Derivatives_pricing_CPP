/*
requires:
    Arrays.cpp
    BinomialTree.cpp
    BlackScholesFormulas.cpp
    Normals.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffForward.cpp
    TreeAmerican.cpp
    TreeEuropean.cpp
    TreeProducts.cpp
*/
#include"BinomialTree.h"
#include"TreeAmerican.h"
#include"TreeEuropean.h"
#include "BlackScholesFormulas.h"
#include"PayOffForward.h"
#include"TreeBarrier.h"
#include<iostream>
#include<cmath>
using std::cin; using std::cout;
int main()
{
    double Expiry;
    double Strike;
    double Barrier;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long Steps;

    cout <<"\nEnter expiry\n";
    cin >> Expiry;

    cout<<"\nStrike\n";
    cin>>Strike;

    cout<<"\nSpot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout<<"\nr\n";
    cin >> r;

    cout<<"\nd\n";
    cin >> d;

    cout<<"\nNumber of steps\n";
    cin >> Steps;

    cout<<"\nValue of Barrier: \n";
    cin>>Barrier;

    PayOffCall thePayOff(Strike);

    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    TreeEuropean europeanOption(Expiry, thePayOff);
    TreeAmerican americanOption(Expiry, thePayOff);
    TreeBarrier  barrierOption(Expiry,thePayOff,Barrier);

    SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, Steps,
                                Expiry);

    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    double barrierPrice = theTree.GetThePrice(barrierOption);
    cout<<"euro price"<<euroPrice<<"\namer price"
                    <<americanPrice
                    <<"\nbarrier price: "<<barrierPrice
                    <<'\n';

    double BSPrice = BlackScholesCall(Spot, Strike,r,d, Vol,Expiry);
    cout<<"BS formula euro price"<<BSPrice<<'\n';


    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry, forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);
    cout<<"forward price by tree"<<forwardPrice<<'\n';

    double actualForwardPrice =
        exp(-r*Expiry)*(Spot*exp((r-d)*Expiry)-Strike);

    cout <<"forward price "<<actualForwardPrice <<"\n";


    Steps++;//now redo the trees with one more step
    SimpleBinomialTree theNewTree(Spot, rParam,dParam,Vol,Steps,Expiry);

    double euroNewPrice = 
    theNewTree.GetThePrice(europeanOption);

    double americanNewPrice =
      theNewTree.GetThePrice(americanOption);
   
   double barrierNewPrice =
      theNewTree.GetThePrice(barrierOption);
   

    cout<<"euro new price"<<euroNewPrice
    <<"amer new price"<<americanNewPrice 
    <<"barrier new price"
    <<barrierNewPrice<<'\n';
    
    double forwardNewPrice = theNewTree.GetThePrice(forward);

    double averageEuro = 0.5*(euroPrice + euroNewPrice);
    double averageAmer = 0.5*(americanPrice +americanNewPrice);
    double averageForward = 0.5*(forwardPrice +forwardNewPrice);

    cout<<"euro av price"<<averageEuro<<"amer av price"
    << averageAmer<<'\n';

    cout<<"av forward"<<averageForward<<'\n';

    double tmp;
    cin>>tmp;

    return 0;
}

/*
*
*To illustrate certain aspects of tree pricing, we price the European call, the American
* call and the forward. We then reprice them using one extra step. The reason we do this
* is that often pricing on trees gives rise to a zig-zag behavior as nodes go above and below
* the money. The average of the price for two successive steps is therefore often a lot more
* accurate than a single price. We give the comparison Black-Scholes price for the European option
* as an assessment of accuracy. The code for the Black-Scholes price is in BlackScholesFormula.h
* and BlackScholesFormula.cpp; 
*
*
*/

/*
* A standard way of improving the accuracy of American option pricing is to use the European price
* as a control. As we know the true price of the European and we know the tree price also, we
*can assume that the American option has the same amount of error as the European and adjust its price accordingly....
*
*
*/


/*
* We also give the price of a forward. Note that if we had required the discounted discretized process
* to be a martingale, then the forward would be priced absolutely correctly; 
*
*
*/