//edited by mukoedo1993:
//Notice that, rather than used a naked pointer in the original file in
//SimpleMCMain4.cpp, here I use a unique_ptr.

/*
requires
        PayOff2.cpp
        Random1.cpp
        SimpleMC2.cpp
*/
#include"SimpleMC2.h"
#include<iostream>
#include<memory>
using namespace std;

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

    cout<<"\nEnter strike\n";
    cin>>Strike;

    cout<<"\nEnter spot\n";
    cin>>Spot;

    cout<<"\nEnter Vol\n";
    cin>>Vol;

    cout<<"\nr\n";
    cin>>r;

    cout<<"\nNumber of paths\n";
    cin>>NumberOfPaths;

    unsigned long optionType;
    cout<<"ENter 0 for call, otherwise put ";
    cin>>optionType;

    std::unique_ptr<PayOff> thePayOffPtr;

    if(optionType==0)
    thePayOffPtr= std::move(std::make_unique<PayOffCall>(Strike));
    else
    thePayOffPtr=std::move(std::make_unique<PayOffPut>(Strike));

    double result = SimpleMonteCarlo2(*thePayOffPtr,
                                     Expiry,
                                     Spot,
                                     Vol,
                                     r,
                                     NumberOfPaths);
    
    cout<<"\nthe price is "<<result<<"\n";
    double tmp;
    cin>>tmp;

    return 0;
}