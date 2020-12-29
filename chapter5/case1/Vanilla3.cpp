#include"Vanilla3.h"

VanillaOption::VanillaOption(const PayOffBridge&
                            ThePayOff_, double Expiry_)
                            :ThePayOff(ThePayOff_),Expiry(Expiry_)
{

}

VanillaOption::VanillaOption(const VanillaOption& orig)
:ThePayOff(orig.ThePayOff),Expiry(orig.Expiry)
{
    
}
        
VanillaOption::VanillaOption(VanillaOption&& orig)
:ThePayOff(std::move(orig.ThePayOff)),Expiry(orig.Expiry)
{

}
VanillaOption& VanillaOption::operator=(const VanillaOption&orig)
{
      if(this!=&orig)
      {
         ThePayOff=orig.ThePayOff;
         Expiry=orig.Expiry;
      }
      return *this;
}
VanillaOption& VanillaOption::operator=( VanillaOption&&orig)
{
   if(this!=&orig)
      {
         ThePayOff=std::move(orig.ThePayOff);
         Expiry=orig.Expiry;
      }
      return *this;

}
double VanillaOption::GetExpiry()const {

return Expiry;
}

double VanillaOption::OptionPayOff(double Spot)const {

   return ThePayOff(Spot);

}
