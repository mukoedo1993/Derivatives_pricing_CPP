output: MCstatistics.o Parameters.o PayOff3.o PayOffBridge.o Random1.o SimpleMC7.o Vanilla3.o StatsMain1.o
	g++ MCstatistics.o Parameters.o PayOff3.o PayOffBridge.o Random1.o SimpleMC7.o Vanilla3.o StatsMain1.o -o output

MCstatistics.o: MCstatistics.cpp StatisticsMC.h 
	g++ -c MCstatistics.cpp

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

Vanilla3.o: Vanilla3.cpp Vanilla3.h
	g++ -c Vanilla3.cpp

StatsMain1.o: StatsMain1.cpp Vanilla3.h SimpleMC7.h StatisticsMC.h
	g++ -c StatsMain1.cpp
clean:
	rm *.o output

