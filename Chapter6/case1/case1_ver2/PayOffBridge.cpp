#include"PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
    ThePayOffPtr = innerPayOff.clone();
}

  
PayOffBridge::~PayOffBridge()
{
   
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
    if (this != &original)
    {
      ThePayOffPtr=std::move(const_cast<PayOffBridge&>(original).ThePayOffPtr);
        
    }
    
    return *this;
}