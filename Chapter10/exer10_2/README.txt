exercise10_2:
Q: Our class cannot handle a double digital as it needs two strikes. Work out a solution that will 
handle options with multiple parameters.


I decompose it into two digital options, and make the result the min of both two.


(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_2$ make
g++ -c PayOff3.cpp
g++ -c PayOffBridge.cpp
g++ -c PayOffFactory.cpp
g++ -c PayOffRegistration.cpp
g++ -c PayOffStraddle.cpp
g++ -c PayOffDoubleDigital.cpp
g++ -c PayFactoryMain.cpp
g++ PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o PayOffStraddle.o PayOffDoubleDigital.o PayFactoryMain.o -o output
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_2$ ./output
Enter strike
12

pay-off name
digital1
Enter strike2
14

pay-off name2
digital2

Spot: 
17
The final result is: 0
1.2
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_2$ ./output
Enter strike
12

pay-off name
dig
Enter strike2
13

pay-off name2
digital2
terminate called after throwing an instance of 'std::invalid_argument'
  what():  outside of the boundary!
1.3
Aborted (core dumped)
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_2$ 1.3
1.3: command not found
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_2$ 
