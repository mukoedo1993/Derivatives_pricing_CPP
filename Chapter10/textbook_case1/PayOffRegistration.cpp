#include"PayOffConstructible.h"

namespace
{
    PayOffHelper<PayOffCall>RegisterCall("call");
    
    PayOffHelper<PayOffPut>RegisterPut("put");

}

/*
As global variables, they are initialized at the start of the program. This initialization 
carries out the registration as required. Note that we have put a namespace command around
the declaration. This means that the variables are in an unnamed namespace and so are invisible to
the rest of the program. So the variables are both global and invisible. 


Why do we want them invisible?
Their purpose is purely to perform the registration , and once that has been done we have no
further use for them so it is best to put them out of sight and out of templation's reach.

*/