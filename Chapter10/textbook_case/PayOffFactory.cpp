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
/*
* The helper class we define here has to do two things. It must define a constructor that
carries out the registration of the class defined by the template parameters, and it must define
a function which will carry out the creation so we have  something to use in the registration process!
*/

/*
The constructor takes in a string as an argument; this string will  be needed to identify the class being registered.
The constructor simply first calls Instance to get the address of the factory object, and then calls the RegisterPayOff method
of the factory to carry out the registration. 
Actually, it is a blank constructor.
*/

/*
The method Create defines the function used to create the pay-off object on demand.
Note that it is static as it should not be associated to any particular class object.
The function simply calls the constructor for objects of type T with argument Strike. 
Of course, there is sth slightly subtle here in that the specification of the template parameter, T, 
is making the choice of which object to construct. Note that we use new as we want the created object
to persist after the function is finished. One consequence of this is that the object will
have to be properly deleted at some point.
*/
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



