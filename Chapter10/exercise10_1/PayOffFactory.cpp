#if defined(_MSC_VER)
#pragma warning(disable : 4786)
#endif
#include"PayOffFactory.h"
#include<iostream>
using std::string;
using std::unordered_map;
using std::cin; 
using std::cout;
using std::endl;

void PayOffFactory::RegisterPayOff(const string& PayOffId,
                                    const CreatePayOffFunction& CreatorFunction)
{
    if(!TheCreatorFunctions.count(PayOffId))
    TheCreatorFunctions[PayOffId]=CreatorFunction;
}


PayOff* PayOffFactory::CreatePayOff(const string& PayOffId,
                                    double Strike)
{
  unordered_map<string,CreatePayOffFunction>::const_iterator
                                        i = TheCreatorFunctions.find(PayOffId);

    if(i == TheCreatorFunctions.cend())
    {
        cout << PayOffId
        <<" is an unknown payoff" <<endl;
        return nullptr;
    }
    return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}



