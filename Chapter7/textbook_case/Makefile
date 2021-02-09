# uses source files
#   AntiThetic.cpp
#   Arrays.cpp
#   ConvergenceTable.cpp
#   ExoticBSEngine.cpp
#   ExtoticEngine.cpp
#   MCStatistics.cpp
#   Normals.cpp
#   Parameters.cpp
#   ParkMiller.cpp
#   PathDependent.cpp
#   PathDependentAsian.cpp
#   PayOff3.cpp
#   PayOffBridge.cpp
#   Random2.cpp


output: AntiThetic.o Arrays.o ConvergenceTable.o ExoticBSEngine.o ExoticEngine.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PathDependent.o PathDependentAsian.o PayOff3.o PayOffBridge.o Random2.o EquityFXMain.o
	g++ AntiThetic.o Arrays.o ConvergenceTable.o ExoticBSEngine.o ExoticEngine.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PathDependent.o PathDependentAsian.o PayOff3.o PayOffBridge.o Random2.o EquityFXMain.o -o output

AntiThetic.o: AntiThetic.cpp AntiThetic.h 
	g++ -c AntiThetic.cpp

Arrays.o: Arrays.cpp Arrays.h
	g++ -c Arrays.cpp

ConvergenceTable.o: ConvergenceTable.cpp ConvergenceTable.h
	g++ -c ConvergenceTable.cpp

ExtoticEngine.o: ExoticEngine.cpp ExoticEngine.h
	g++ -c ExoticEngine.cpp

ExoticBSEngine.o: ExoticBSEngine.cpp ExoticBSEngine.h
	g++ -c ExoticBSEngine.cpp



PathDependent.o: PathDependent.cpp PathDependent.h
	g++ -c PathDependent.cpp

PathDependentAsian.o: PathDependentAsian.cpp PathDependentAsian.h
	g++ -c PathDependentAsian.cpp

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

EquityFXMain.o: EquityFXMain.cpp ParkMiller.h MCStatistics.h ConvergenceTable.h AntiThetic.h PathDependentAsian.h ExoticBSEngine.h
	g++ -c EquityFXMain.cpp
clean: 
	rm *.o output


#include"ParkMiller.h"
#include<iostream>

#include"MCStatistics.h"
#include"ConvergenceTable.h"
#include"AntiThetic.h"
#include"PathDependentAsian.h"
#include"ExoticBSEngine.h"