#ifndef PAYOFF_CONSTRUCTIBLE_H
#define PAYOFF_CONSTRUCTIBLE_H

#if defined(_MSC_VER)
#pragma warning(disable: 4786)
#endif


#include<iostream>
#include"PayOff3.h"
#include"PayOffStraddle.h"
#include"PayOffFactory.h"
#include<string>


template<class T>
class PayOffHelper
{
public:
    PayOffHelper(const std::string&);
    static PayOff* Create(double);
};

template<class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
    return new T(Strike);
}


template<class T>
PayOffHelper<T>::PayOffHelper(const std::string& id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}



#endif