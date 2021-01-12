output: PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o Random1.o SimpleMC114514.o PayFactoryMain.o
	g++ PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o Random1.o SimpleMC114514.o PayFactoryMain.o -o output

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h PayOff3.h
	g++ -c PayOffBridge.cpp

PayOffFactory.o: PayOffFactory.cpp PayOffFactory.h
	g++ -c PayOffFactory.cpp

PayOffRegistration.o: PayOffRegistration.cpp PayOffConstructible.h
	g++ -c PayOffRegistration.cpp

Random1.o: Random1.cpp Random1.h
	g++ -c Random1.cpp

SimpleMC114514.o: SimpleMC114514.cpp SimpleMC114514.h
	g++ -c SimpleMC114514.cpp

PayFactoryMain.o: PayFactoryMain.cpp PayOff3.h PayOffConstructible.h PayOffBridge.h PayOffFactory.h Random1.h
	g++ -c PayFactoryMain.cpp

clean: 
	rm *.o output

