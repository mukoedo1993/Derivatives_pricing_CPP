

output: Random1.o SimpleMCMain2.o SimpleMC.o PayOff1.o
	g++ Random1.o SimpleMCMain2.o SimpleMC.o PayOff1.o -o output

Random1.o: Random1.cpp Random1.h
	g++ -c Random1.cpp

SimpleMC.o: SimpleMC.cpp SimpleMC.h
	g++ -c SimpleMC.cpp 

PayOff1.o: PayOff1.cpp PayOff1.h
	g++ -c PayOff1.cpp

SimpleMain2.o: SimpleMCMain2.cpp SimpleMC.h
	g++ -c SimpleMCMain2.cpp

clean: 
	rm *.o output
