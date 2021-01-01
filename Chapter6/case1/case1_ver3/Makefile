output: AntiThetic.o Arrays.o ConvergenceTable.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PayOff3.o PayOffBridge.o Random2.o SimpleMC8.o Vanilla3.o RandomMain3.o
	g++ AntiThetic.o Arrays.o ConvergenceTable.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PayOff3.o PayOffBridge.o Random2.o SimpleMC8.o Vanilla3.o RandomMain3.o -o output

AntiThetic.o: AntiThetic.cpp AntiThetic.h 
	g++ -c AntiThetic.cpp

Arrays.o: Arrays.cpp Arrays.h
	g++ -c Arrays.cpp

ConvergenceTable.o: ConvergenceTable.cpp ConvergenceTable.h
	g++ -c ConvergenceTable.cpp

MCStatistics.o: MCStatistics.cpp MCStatistics.h
	g++ -c MCStatistics.cpp

Normals.o: Normals.cpp Normals.h
	g++ -c Normals.cpp

Parameters.o: Parameters.cpp Parameters.h
	g++ -c Parameters.cpp

ParkMiller.o: ParkMiller.cpp ParkMiller.h
	g++ -c ParkMiller.cpp 

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h PayOff3.h
	g++ -c PayOffBridge.cpp

Random2.o: Random2.cpp Random2.h
	g++ -c Random2.cpp

SimpleMC8.o: SimpleMC8.cpp SimpleMC8.h
	g++ -c SimpleMC8.cpp

Vanilla3.o: Vanilla3.cpp Vanilla3.h PayOffBridge.h
	g++ -c Vanilla3.cpp

RandomMain3.o: RandomMain3.cpp Parameters.h SimpleMC8.h ParkMiller.h Vanilla3.h MCStatistics.h ConvergenceTable.h AntiThetic.h
	g++ -c RandomMain3.cpp

clean: 
	rm *.o output

#include"SimpleMC8.h"
#include"ParkMiller.h"
#include<iostream>
#include"Vanilla3.h"
#include"MCStatistics.h"
#include"ConvergenceTable.h"
#include"AntiThetic.h"

