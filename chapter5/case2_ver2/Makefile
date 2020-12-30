output: MCStatistics.o Parameters.o PayOff3.o PayOffBridge.o Random1.o SimpleMC7.o Vanilla3.o StatsMain1.o ConvergenceTable.o
	g++ MCStatistics.o Parameters.o PayOff3.o PayOffBridge.o Random1.o SimpleMC7.o Vanilla3.o StatsMain1.o ConvergenceTable.o -o output

MCStatistics.o: MCStatistics.cpp MCStatistics.h 
	g++ -c MCStatistics.cpp

Parameters.o: Parameters.cpp Parameters.h
	g++ -c Parameters.cpp

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h
	g++ -c PayOffBridge.cpp

Random1.o: Random1.cpp Random1.h
	g++ -c Random1.cpp

SimpleMC7.o: SimpleMC7.cpp SimpleMC7.h
	g++ -c SimpleMC7.cpp

Vanilla3.o: Vanilla3.cpp Vanilla3.h PayOffBridge.h
	g++ -c Vanilla3.cpp

StatsMain1.o: StatsMain1.cpp Vanilla3.h SimpleMC7.h MCStatistics.h ConvergenceTable.h
	g++ -c StatsMain1.cpp

ConvergenceTable.o: ConvergenceTable.cpp MCStatistics.h Wrapper.h
	g++ -c ConvergenceTable.cpp

clean:
	rm *.o output


# ConvergenceTable.cpp
 #       MCstatistics.cpp
 #       Parameters.cpp,
 #       PayOff3.cpp, 
 #       PayOffBridge.cpp,
 #       Random1.cpp, 
 #       SimpleMC7.cpp 
 #       Vanilla3.cpp
 # g++ ConvergenceTable.cpp MCstatistics.cpp Parameters.cpp PayOff3.cpp PayOffBridge.cpp Random1.cpp SimpleMC7.cpp Vanilla3.cpp StatsMain2.cpp Wrapper.cpp