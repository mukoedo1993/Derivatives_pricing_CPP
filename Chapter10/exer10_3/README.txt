Q: Integrate the factory with a Monte Carlo routine.

(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_3$ make
g++ -c PayOff3.cpp
g++ -c PayOffBridge.cpp
g++ -c PayOffFactory.cpp
g++ -c PayOffRegistration.cpp
g++ -c Random1.cpp
g++ -c SimpleMC114514.cpp
g++ -c PayFactoryMain.cpp
g++ PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o Random1.o SimpleMC114514.o PayFactoryMain.o -o output
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_3$ ./output
Enter strike
12

pay-off name
call

Spot
100

Expiry
12

Vol
0.02

r
0.3

Number Of Paths: 
10000

84.6351
1.3
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_3$ ./output
Enter strike
12

pay-off name
put

Spot
100

Expiry
12

Vol
0

r
0

Number Of Paths: 
20

0
1.2
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter10/exer10_3$ ./output
Enter strike
12

pay-off name
put

Spot
8

Expiry
10

Vol
0.001

r
0.01 

Number Of Paths: 
1000

3.99267
