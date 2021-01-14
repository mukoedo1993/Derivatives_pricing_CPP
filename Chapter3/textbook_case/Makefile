

output: Random1.o SimpleMCMain5.o SimpleMC2.o PayOff2.o DoubleDigital.o
	g++ Random1.o SimpleMCMain5.o SimpleMC2.o PayOff2.o DoubleDigital.o -o output

DoubleDigital.o: DoubleDigital.cpp DoubleDigital.h
	g++ -c DoubleDigital.cpp

Random1.o: Random1.cpp Random1.h
	g++ -c Random1.cpp

SimpleMC2.o: SimpleMC2.cpp SimpleMC2.h
	g++ -c SimpleMC2.cpp 

PayOff2.o: PayOff2.cpp PayOff2.h
	g++ -c PayOff2.cpp

SimpleMain5.o: SimpleMCMain5.cpp SimpleMC.h DoubleDigital.h
	g++ -c SimpleMCMain5.cpp

clean: 
	rm *.o output
