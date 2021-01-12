output: PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o PayOffStraddle.o PayFactoryMain.o
	g++ PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o PayOffStraddle.o PayFactoryMain.o -o output

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h PayOff3.h
	g++ -c PayOffBridge.cpp

PayOffFactory.o: PayOffFactory.cpp PayOffFactory.h
	g++ -c PayOffFactory.cpp

PayOffRegistration.o: PayOffRegistration.cpp PayOffConstructible.h
	g++ -c PayOffRegistration.cpp

PayOffStraddle.o: PayOffStraddle.cpp PayOffStraddle.h
	g++ -c PayOffStraddle.cpp

PayFactoryMain.o: PayFactoryMain.cpp PayOff3.h PayOffStraddle.h PayOffConstructible.h PayOffBridge.h PayOffFactory.h
	g++ -c PayFactoryMain.cpp

clean: 
	rm *.o output



#/*
#Uses
#    PayOff3.cpp
#    PayOffBridge.cpp
#    PayOffFactory.cpp
#    PayOffRegistration.cpp
#*/

#include"PayOff3.h"
#include"PayOffConstructible.h"
#include"PayOffBridge.h"
#include"PayOffFactory.h"
#include<string>
#include<iostream>