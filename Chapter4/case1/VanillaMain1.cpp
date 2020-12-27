/*
requires DoubleDigital.cpp
         PayOff2.cpp
         Random1.cpp
         SimpleMC3.cpp
*/

#include"SimpleMC3.h"
#include"DoubleDigital.h"
#include<iostream>
using namespace std;
#include"Vanilla1.h"

int main()
{
    double Expiry;
    double Low,Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout<<"\nEnter expiry\n";
    cin>>Expiry;

    cout<<"\nEnter low barrier\n";
    cin>>Low;

    cout<<"\nEnter up barrier\n";
    cin>>Up;

    cout<<"\nEnter spot\n";
    cin>>Spot;

    cout<<"\nEnter vol\n";
    cin>>Vol;

    cout<<"\nr\n";
    cin>>r;

    cout<<"\nNumber of paths\n";
    cin>>NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low,Up);
    VanillaOption theOption(thePayOff, Expiry);

    double result = SimpleMonteCarlo3(theOption,
                                     Spot,
                                     Vol,
                                     r,
                                     NumberOfPaths);

    cout<<"\nthe price is \n"<<result<<"\n";

    char char_end;
    char_end=getchar();


}
/*
g++ DoubleDigital.cpp DoubleDigital.h PayOff2.cpp PayOff2.h Random1.cpp Random1.h SimpleMC3.cpp SimpleMC3.h Vanilla1.cpp Vanilla1.h VanillaMain1.cpp
*/