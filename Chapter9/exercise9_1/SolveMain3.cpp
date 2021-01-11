/*
Needs
    BlackScholesFormulas.cpp
    BSCallTwo.cpp
    Normals.cpp
*/

#include"NewtonRaphson1.h"
#include<cmath>
#include<iostream>
#include"BSCallTwo.h"
#include"BlackScholesFormulas.h"
using std::cin; using std::cout;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;

    cout <<"\nEnter expiry\n";
    cin >> Expiry;

    cout<<"\nStrike\n";
    cin >> Strike;

    cout<<"\nEnter spot\n";
    cin >> Spot;

    cout<<"\nEnter price\n";
    cin >> Price;

    cout<<"\nr\n";
    cin >> r;
    
    cout<< "\nd\n";
    cin >> d;

    double start;

    cout<<"\nstart guess\n";
    cin>>start;


    double tolerance;

    cout<<"\nTolerance\n";
    cin>> tolerance;

    BSCallTwo theCall(r,d,Expiry, Spot, Strike);
    
    double vol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price,
    &BSCallTwo::Vega>(Price,start,tolerance,theCall);

    double PriceTwo = 
    BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout<< "\n vol "<<vol<<" \nprice two:" <<PriceTwo <<'\n';

    double tmp;
    cin >> tmp;
}

