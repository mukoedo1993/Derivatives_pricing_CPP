/*
Uses
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffFactory.cpp
    PayOffRegistration.cpp
    Random1.cpp
*/

/**Exercise 10_3: **/

#include"PayOff3.h"
#include"PayOffConstructible.h"
#include"PayOffBridge.h"
#include"SimpleMC114514.h"
#include"PayOffFactory.h"
#include"Random1.h"
#include<string>
#include<iostream>
#include<cmath>
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
        PayOffFactory::Instance().CreatePayOff(name,Strike);


/*
double SimpleMonteCarlo1(double Expiry,
                        double Strike,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths)
*/
    if(PayOffPtr!=nullptr)
    {
        double Spot;
        cout<<"\nSpot\n";
        cin >> Spot;
 
        double Expiry;
        cout<<"\nExpiry\n";
        cin >> Expiry;

        double Vol;
        cout<<"\nVol\n";
        cin >> Vol;

        double r;
        cout<<"\nr\n";
        cin >> r;   

        unsigned long Num;
        cout<<"\nNumber Of Paths: \n";
        cin>>Num;

        cout << "\n" <<PayOffPtr->operator()(SimpleMonteCarlo1(Expiry,Strike,Spot,Vol,r,Num))<<'\n';
        delete PayOffPtr;
        PayOffPtr=nullptr;

    }
    double tmp;
    cin >>tmp;
    
    
}