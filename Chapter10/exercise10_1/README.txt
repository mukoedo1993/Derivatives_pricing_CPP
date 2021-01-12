Question: Write a straddle class and register it with the factory.


...
Options, Futures, and other derivatives(9th ed.)(author: John C.Hull) Page 267


...
One particular combination is a straddle, which involves buying a European call and put 
with the same strike price and expiration date. 




Log:

(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exercise10_1$ make clean
rm *.o output
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exercise10_1$ make
g++ -c PayOff3.cpp
g++ -c PayOffBridge.cpp
g++ -c PayOffFactory.cpp
g++ -c PayOffRegistration.cpp
g++ -c PayOffStraddle.cpp
g++ -c PayFactoryMain.cpp
g++ PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o PayOffStraddle.o PayFactoryMain.o -o output
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exercise10_1$ ./output
Enter strike
12

pay-off name
straddle

Spot
8

4
1.3
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exercise10_1$ ./output
Enter strike
12

pay-off name
straddle

Spot
27

15
1.4
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exercise10_1$ 
