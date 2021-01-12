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
class PayOffFactory
{
public:
    using CreatePayOffFunction=
     std::function<PayOff*(double)> ;
    static PayOffFactory& Instance();
    void RegisterPayOff(const std::string&, const CreatePayOffFunction&);
    PayOff* CreatePayOff(const std::string& PayOffId, double Strike);
    ~PayOffFactory(){}

private:
    std::unordered_map<std::string, CreatePayOffFunction>
            TheCreatorFunctions;

    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator=
                (const PayOffFactory&) {return *this;}
};

#endif

/*

*
*/