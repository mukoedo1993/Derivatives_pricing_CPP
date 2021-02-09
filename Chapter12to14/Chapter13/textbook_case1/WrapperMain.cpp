//
//      requires PayOff3.cpp
#include<iostream>
#include"wrapper2.h"
#include"PayOff3.h"
using std::cin;
using std::cout;
int main()
{
    double S;
    double K1,K2,K3;

    cout<<" spot\n";
    cin >> S;

    cout<<" strike1\n";
    cin >> K1;

    cout<< " strike2\n";
    cin >> K2;

    PayOffCall one(K1);
    PayOffPut two(K2);

    std::shared_ptr<PayOff> p =one.clone();
   

    {
        std::shared_ptr<PayOff> q =two.clone();
        

        cout<<"four :";
        cout<< (*p)(S)
        <<" five :"
        <<(*q)(S)<<"\n";

        p=q;
    }

    cout<<"four: "<<(*p)(S)<<"\n";

    double tmp;
    cin >>tmp;

}
