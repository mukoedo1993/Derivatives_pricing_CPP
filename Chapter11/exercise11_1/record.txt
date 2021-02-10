Q: Implement the factory from Chapter 10 using the monostate pattern instead of singleton
pattern.

log:
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter11/textbook_case$ make
g++ -c PayOff3.cpp
g++ -c PayOffBridge.cpp
g++ -c PayOffFactory1.cpp
g++ -c PayOffRegistration.cpp
g++ -c PayFactoryMain.cpp
g++ PayOff3.o PayOffBridge.o PayOffFactory1.o PayOffRegistration.o PayFactoryMain.o -o output
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter11/textbook_case$ ./output
Enter strike
12

pay-off name
3
3 is an unknown payoff
3.2
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter11/textbook_case$ ./output
Enter strike
12

pay-off name
put

Spot
7

5
1.4
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter11/textbook_case$ 
