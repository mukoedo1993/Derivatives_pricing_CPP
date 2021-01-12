#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H

#include"PayOff3.h"
#if defined(_MSC_VER)
#pragma warning (disable :4786)
#endif

#include<unordered_map>
#include<string>
#include<iostream>
#include<functional>
/*

*/
class PayOffFactory1
{
public:
    using CreatePayOffFunction=
     std::function<PayOff*(double)> ;
    static PayOffFactory1& Instance();
    void RegisterPayOff(const std::string&, const CreatePayOffFunction&);
    PayOff* CreatePayOff(const std::string& PayOffId, double Strike);
    ~PayOffFactory1(){
        delete &TheCreatorFunctions();
         
    }
    
    static std::unordered_map<std::string, CreatePayOffFunction>&
            TheCreatorFunctions()
              {
                  static std::unordered_map<std::string, CreatePayOffFunction>* rslt
                  =new std::unordered_map<std::string, CreatePayOffFunction>();
                 return *rslt;
            }
private:


    PayOffFactory1(){}
    PayOffFactory1(const PayOffFactory1&){}
    PayOffFactory1& operator=
                (const PayOffFactory1&) {return *this;}
};


#endif

/*
*
*
*/