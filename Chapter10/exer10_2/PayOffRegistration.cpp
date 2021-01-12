#include"PayOffConstructible.h"

namespace
{
    PayOffHelper<PayOffCall>RegisterCall("call");
    
    PayOffHelper<PayOffPut>RegisterPut("put");

    PayOffHelper<PayOffStraddle>RegisterStraddle("straddle");

    PayOffHelper<PayOffDoubleDigital1>Registerdigital1("digital1");

    PayOffHelper<PayOffDoubleDigital2>Registerdigital2("digital2");
}

