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
#   PathDependentKnockOut.cpp
#   PayOff3.cpp
#   PayOffBridge.cpp
#   Random2.cpp


output: AntiThetic.o Arrays.o ConvergenceTable.o ExoticBSEngine.o ExoticEngine.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PathDependent.o PathDependentKnockOut.o PayOff3.o PayOffBridge.o Random2.o EquityFXMain_ex_7_2.o
	g++ AntiThetic.o Arrays.o ConvergenceTable.o ExoticBSEngine.o ExoticEngine.o MCStatistics.o Normals.o Parameters.o ParkMiller.o PathDependent.o PathDependentKnockOut.o PayOff3.o PayOffBridge.o Random2.o EquityFXMain_ex_7_2.o -o output

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

PathDependentKnockOut.o: PathDependentKnockOut.cpp PathDependentKnockOut.h
	g++ -c PathDependentKnockOut.cpp

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

EquityFXMain_ex_7_2.o: EquityFXMain_ex_7_2.cpp ParkMiller.h MCStatistics.h ConvergenceTable.h AntiThetic.h PathDependentKnockOut.h ExoticBSEngine.h
	g++ -c EquityFXMain_ex_7_2.cpp
clean: 
	rm *.o output
