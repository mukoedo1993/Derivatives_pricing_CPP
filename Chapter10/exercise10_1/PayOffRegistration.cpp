#include"PayOffConstructible.h"

namespace
{
    PayOffHelper<PayOffCall>RegisterCall("call");
    
    PayOffHelper<PayOffPut>RegisterPut("put");

    PayOffHelper<PayOffStraddle>RegisterStraddle("straddle");
}