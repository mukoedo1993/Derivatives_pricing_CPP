#include"PayOffBridge.h"
#include<stdexcept>
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
   delete ThePayOffPtr;
   ThePayOffPtr=nullptr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
  if (this != &original)
    {
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }

    
    return *this;
}