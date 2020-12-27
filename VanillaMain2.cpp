/*
requires PayOff3.cpp
Random1.cpp
SimpleMC4.cpp
Vanilla2.cpp
*/

#include"SimpleMC4.h"
#include<iostream>
#include"Vanilla2.h"
using std::cin;using std::cout;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout<<"\nEnter expiry\n";
    cin>>Expiry;

    cout<<"\nStrike\n";
    cin>>Strike;

    cout<<"\nEnter spot\n";
    cin>>Spot;

    cout<<"\nEnter vol\n";
    cin>>Vol;

    cout<<"\nr\n";
    cin>>r;

    cout<<"\nNumber of paths\n";
    cin>>NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff,Expiry);

    double result= SimpleMonteCarlo4(theOption,
                                     Spot,
                                     Vol,
                                     r,
                                     NumberOfPaths);
    
    cout<<"\nthe call price is \n"<<result<<"\n";

    VanillaOption secondOption(theOption);

    result = SimpleMonteCarlo4(secondOption,
                                Spot,
                                Vol,
                                r,
                                NumberOfPaths);

    cout<<"\nthe call price is \n"<<result<<"\n";

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff , Expiry);
    theOption = thirdOption;

    result = SimpleMonteCarlo4(theOption,
                               Spot,
                               Vol,
                               r,
                               NumberOfPaths);

    cout<<"\nthe put price is "<<result<<"\n";

    char c;
    c=getchar();
    VanillaOption fourthOption(std::move(thirdOption));

    theOption = fourthOption;

    result = SimpleMonteCarlo4(theOption,
                               Spot,
                               Vol,
                               r,
                               NumberOfPaths);

    cout<<"\nthe put price is "<<result<<"\n";
}
//g++ PayOff3.cpp PayOff3.h Random1.cpp Random1.h SimpleMC4.cpp SimpleMC4.h Vanilla2.cpp Vanilla2.h