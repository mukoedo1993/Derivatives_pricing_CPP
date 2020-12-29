output: PayOff3.o PayOffBridge.o Random1.o SimpleMC5.o Vanilla3.o VanillaMain3.o
	g++ PayOff3.o PayOffBridge.o Random1.o SimpleMC5.o Vanilla3.o VanillaMain3.o -o output

VanillaMain3.o: VanillaMain3.cpp SimpleMC5.h Vanilla3.h
	g++ -c VanillaMain3.cpp

Vanilla3.o: Vanilla3.cpp Vanilla3.h
	g++ -c Vanilla3.cpp

SimpleMC5.o: SimpleMC5.cpp SimpleMC5.h Random1.h
	g++ -c SimpleMC5.cpp

Random1.o: Random1.cpp Random1.h
	g++ -c Random1.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h PayOff3.h
	g++ -c PayOffBridge.cpp

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

clean:
	rm *.o

#case 3 in chap.4
#Mark S. Joshi's  C++ Design Patterns and Derivatives Pricing second edition