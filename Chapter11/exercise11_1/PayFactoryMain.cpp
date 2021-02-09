/*
Uses
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffFactory1.cpp
    PayOffRegistration.cpp
*/

#include"PayOff3.h"
#include"PayOffConstructible.h"
#include"PayOffBridge.h"
#include"PayOffFactory1.h"
#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;

int main()
{
    double Strike;
    string name;

    cout <<"Enter strike\n";
    cin >> Strike;

    cout<<"\npay-off name\n";
    cin >> name;

    PayOff* PayOffPtr =
        PayOffFactory1::Instance().CreatePayOff(name,Strike);

    if(PayOffPtr!=nullptr)
    {
        double Spot;
        cout<<"\nSpot\n";
        cin >> Spot;

        cout << "\n" <<PayOffPtr->operator()(Spot)<<'\n';
        delete PayOffPtr;
        PayOffPtr=nullptr;

    }
    double tmp;
    cin >>tmp;
    
    
}