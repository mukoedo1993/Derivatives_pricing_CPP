log: 


(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter7/exercise7_1/Ver1$ make clean
rm *.o output
rm: cannot remove '*.o': No such file or directory
rm: cannot remove 'output': No such file or directory
make: *** [Makefile:68: clean] Error 1
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter7/exercise7_1/Ver1$ make
g++ -c AntiThetic.cpp
g++ -c Arrays.cpp
g++ -c ConvergenceTable.cpp
g++ -c ExoticBSEngine.cpp
g++    -c -o ExoticEngine.o ExoticEngine.cpp
g++ -c MCStatistics.cpp
g++ -c Normals.cpp
g++ -c Parameters.cpp
g++ -c ParkMiller.cpp 
g++ -c PathDependent.cpp
g++ -c PathDependentGeometricAsian.cpp
g++ -c PayOff3.cpp
g++ -c PayOffBridge.cpp
g++ -c Random2.cpp
g++ -c EquityFXMain.cpp
g++ AntiThetic.o Arrays.o ConvergenceTable.o ExoticBSEngine.o ExoticEngine.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PathDependent.o PathDependentGeometricAsian.o PayOff3.o PayOffBridge.o Random2.o EquityFXMain.o -o output
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter7/exercise7_1/Ver1$ ./output

Enter expiry
12

Strike
100

Enter spot
150

ENter vol
0.03

r
0.2

d
0.1
Number of dates
6

Number of paths
10000

For the Asian call price the results are
18.8477 2 
18.5473 4 
18.4247 8 
18.3587 16 
18.3325 32 
18.324 64 
18.3075 128 
18.3061 256 
18.3046 512 
18.3075 1024 
18.303 2048 
18.3058 4096 
18.3066 8192 
18.3066 10000 
1.3
(base) zcw@mukoedo1993:~/finance_local_clone/Derivatives_pricing_CPP/Chapter7/exercise7_1/Ver1$ 

