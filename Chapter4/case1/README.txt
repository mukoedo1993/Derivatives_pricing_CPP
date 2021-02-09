Run
g++ DoubleDigital.cpp DoubleDigital.h PayOff2.cpp PayOff2.h Random1.cpp Random1.h SimpleMC3.cpp SimpleMC3.h Vanilla1.cpp Vanilla1.h VanillaMain1.cpp
on the Ubuntu terminal on this directory.

Case1 gives us a way to price a double-digital option.

Weakness: The VanillaOption class stores a reference to a PayOff object which was defined outside the class. This means that if we
change that object then the pay-off of the vanilla option will change. The vanilla option will not exist as independent object in its 
own right but wilt constructed outside the class. 

In addition, if the PayOff object had been created using new as we did in the last chapter then it might be deleted before the option ceased 
to exist which would result in the vanilla option calling methods of a non-existent object which is bound to cause crashes.




















......................
in one's own right:
as a result of one's own claims, qualifications, or efforts, rather than an association with someone else.
