/*
Uses
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffFactory.cpp
    PayOffStraddle.cpp
    PayOffRegistration.cpp
*/

/****
//exercise 10_2: 
****/
#include"PayOff3.h"
#include"PayOffConstructible.h"
#include"PayOffBridge.h"
#include"PayOffFactory.h"
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

      double Strike2;
    string name2;

    cout <<"Enter strike2\n";
    cin >> Strike2;

    cout<<"\npay-off name2\n";
    cin >> name2;

 if(name!="digital1"||name2!="digital2")
 throw std::invalid_argument("outside of the boundary!");

double Spot;
 cout<<"\nSpot: \n";
 cin>> Spot;

    PayOff* PayOffPtr =
        PayOffFactory::Instance().CreatePayOff(name,Strike);
        double rslt1 =PayOffPtr->operator()(Spot);
         delete PayOffPtr;
         PayOffPtr=nullptr;
   PayOffPtr =
        PayOffFactory::Instance().CreatePayOff(name2,Strike2);
        double rslt2 = PayOffPtr->operator()(Spot);
        cout<<"The final result is: "<<std::min(rslt1,rslt2)<<'\n';
    
     
    double tmp;
    cin >>tmp;
    
    
}