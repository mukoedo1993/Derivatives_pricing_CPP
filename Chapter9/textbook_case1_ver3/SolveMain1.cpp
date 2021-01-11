
/*
Needs
    BlackScholesFormulas.cpp
    BSCallClass.cpp
    Normals.cpp
    Bisection.cpp
*/

#include"Bisection.h"
#include<cmath>
#include<iostream>
#include"BSCallClass.h"
#include"BlackScholesFormulas.h"

using std::cin;
using std::cout;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;

    cout<<"\nEnter expiry\n";
    cin>> Expiry;

    cout<<"\nStrike\n";
    cin >> Strike;
    cout<<"\nEnter spot\n";
    cin >> Spot;

    cout<<"\nEnter price\n";
    cin>> Price;

    cout<<"\nr\n";
    cin >> r;

    cout<<"\nd\n";
    cin >>d;

    double low,high;

    cout<<"\nlower guess\n";
    cin >> low;

    cout << "\nhigher guess\n";
    cin >> high;

    double tolerance;

    cout<<"\nTolerance\n";
    cin >> tolerance;

    BSCall theCall(r,d,Expiry, Spot,Strike);

    double vol =
            Bisection(Price, low, high, tolerance, theCall);

    double PriceTwo = 
            BlackScholesCall(Spot,Strike, r,d,vol,Expiry);

    cout<<"\n vol"<<vol<<" pricetwo "
    <<PriceTwo <<'\n';

    double tmp;
    cin >> tmp;

    return 0;


}
/*
* As usual, we input all the necessary parameters. We then put them together to
* create a BSCall object. We then call the Bisection function to find the volatility. 
* Note that we have not put Bisection<BSCall>. The computer deduces the type of the template
* argument from the fact that our final argument in the function call is theCall. We only
* have to specify the template argument when the compiler does not have a sufficient amount
* of other information to deduce it.
*/
/*
*Our function finishes by getting the price via the Black-Scholes function for the implied volatility
* that was found. Uf everything is working correctly then this will give the original price
* inputted. 
*/