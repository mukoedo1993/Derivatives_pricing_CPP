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
   
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
    if (this != &original)
    {
        if(original.ThePayOffPtr&&ThePayOffPtr)
     {   
         *ThePayOffPtr=*(original.ThePayOffPtr);
     }
     else
     {
         throw std::invalid_argument("You are trying to or/and from assign an unique_ptr which is managing a nullptr");
     }
    }
    
    return *this;
}