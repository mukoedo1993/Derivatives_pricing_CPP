#include"PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& original):
ThePayOffPtr(original.ThePayOffPtr)
{}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff):
ThePayOffPtr(innerPayOff.clone())
{
   
}

PayOffBridge::PayOffBridge(PayOffBridge&& original):
ThePayOffPtr(std::move(original.ThePayOffPtr))
{
   
}

PayOffBridge::~PayOffBridge()=default;

PayOffBridge& PayOffBridge::operator=
                            (const PayOffBridge& original)
{
   if(this!=&original)
   {
       ThePayOffPtr.reset();
       ThePayOffPtr=original.ThePayOffPtr;
   }
   return *this;
}


PayOffBridge& PayOffBridge::operator=(PayOffBridge&& original)
{
     if(this!=&original)
   {
       ThePayOffPtr.reset();
       ThePayOffPtr=std::move(original.ThePayOffPtr);
   }
   return *this;
}