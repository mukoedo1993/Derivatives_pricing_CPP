output: PayOff3.o PayOffBridge.o PayOffFactory1.o PayOffRegistration.o PayFactoryMain.o
	g++ PayOff3.o PayOffBridge.o PayOffFactory1.o PayOffRegistration.o PayFactoryMain.o -o output

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h PayOff3.h
	g++ -c PayOffBridge.cpp

PayOffFactory1.o: PayOffFactory1.cpp PayOffFactory1.h
	g++ -c PayOffFactory1.cpp

PayOffRegistration.o: PayOffRegistration.cpp PayOffConstructible.h
	g++ -c PayOffRegistration.cpp

PayFactoryMain.o: PayFactoryMain.cpp PayOff3.h PayOffConstructible.h PayOffBridge.h PayOffFactory1.h
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