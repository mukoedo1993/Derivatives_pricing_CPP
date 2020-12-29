#ifndef VANILLA_3_H
#define VANILLA_3_H
#include"PayOffBridge.h"

class VanillaOption{

public:
        VanillaOption(const PayOffBridge&
                      ThePayOff_, double Expiry);
        VanillaOption(const VanillaOption& orig);
        VanillaOption(VanillaOption&& orig);
        VanillaOption& operator=(const VanillaOption&orig);
        VanillaOption& operator=( VanillaOption&&orig);
        double OptionPayOff(double Spot)const;
        double GetExpiry()const;

private:
        double Expiry;
        PayOffBridge ThePayOff;
};

#endif