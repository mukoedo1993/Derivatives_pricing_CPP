Run
g++ PayOff3.cpp PayOff3.h Random1.cpp Random1.h SimpleMC4.cpp SimpleMC4.h Vanilla2.cpp Vanilla2.h VanillaMain2.cpp
on the ubuntu terminal in this directory.


Compared to case1, in case2, we used to shared_ptr to dereference the class used rather than a reference. 
It helped us to enhance our code's robustness.

Here, I used this method, in case 2, to develop an interface to price several put and call options.
