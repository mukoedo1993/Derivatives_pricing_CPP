//To be continued....
#ifndef VANILLA_2_H
#define VANILLA_2_H

#include"PayOff3.h"
#include<memory>
class VanillaOption
{
public: 
       VanillaOption()=delete;
       VanillaOption(const PayOff& ThePayOff_, double Expiry_);
       VanillaOption(const VanillaOption& original);
       VanillaOption(VanillaOption&& original);
       VanillaOption& operator=(const VanillaOption& original);
       VanillaOption& operator=( VanillaOption&& original);
       ~VanillaOption();

       double GetExpiry() const;
       double OptionPayOff(double Spot)const;

private:
        double Expiry;
        std::shared_ptr<PayOff> ThePayOffPtr;
        //It is okay to not set the ThePayOffPtr as const,
};

#endif