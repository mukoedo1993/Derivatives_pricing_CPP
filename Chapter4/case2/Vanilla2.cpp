#include"Vanilla2.h"
#include<memory>
VanillaOption::VanillaOption(const PayOff&
                            ThePayOff_, double Expiry_)
                            :Expiry(Expiry_),ThePayOffPtr(ThePayOff_.clone())                                               
{

}

double VanillaOption::GetExpiry()const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot)const {
    return (*ThePayOffPtr)(Spot);
}   

VanillaOption::VanillaOption(const VanillaOption& original)
:Expiry(original.Expiry),ThePayOffPtr(original.ThePayOffPtr){
  
}

VanillaOption::VanillaOption(VanillaOption&& original)
:Expiry(original.Expiry),ThePayOffPtr(std::move(original.ThePayOffPtr)){

}

VanillaOption& VanillaOption::
                    operator=(const VanillaOption& original)
{
    if(this != &original)
    {
        Expiry = original.Expiry;
        ThePayOffPtr=original.ThePayOffPtr;
    }
    return *this;
}

 VanillaOption& VanillaOption::operator=( VanillaOption&& original)
 {
     if(this != &original)
    {
        Expiry = original.Expiry;
        ThePayOffPtr=std::move(original.ThePayOffPtr);
    }
    return *this;
 }

VanillaOption::~VanillaOption()
{
    
}