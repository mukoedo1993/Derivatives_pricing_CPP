

output: Random1.o SimpleMCMain1.o
	g++ Random1.o SimpleMCMain1.o -o output

Random1.o: Random1.cpp Random1.h
	g++ -c Random1.cpp

SimpleMain1.o: SimpleMCMain1.cpp
	g++ -c SimpleMCMain1.o

clean: 
	rm *.o output
