output: BlackScholesFormulas.o BSCallTwo.o Normals.o SolveMain2.o
	g++ BlackScholesFormulas.o BSCallTwo.o Normals.o SolveMain2.o -o output

BlackScholesFormulas.o: BlackScholesFormulas.cpp BlackScholesFormulas.h Normals.h
	g++ -c BlackScholesFormulas.cpp

BSCallTwo.o: BSCallTwo.cpp BSCallTwo.h BlackScholesFormulas.h
	g++ -c BSCallTwo.cpp

Normals.o: Normals.cpp Normals.h 
	g++ -c Normals.cpp

SolveMain2.o: SolveMain2.cpp NewtonRaphson.h BlackScholesFormulas.h BSCallTwo.h
	g++ -c SolveMain2.cpp

clean:
	rm *.o output


#/*
#Needs
#    BlackScholesFormulas.cpp
#    BSCallTwo.cpp
#    Normals.cpp
#*/
#include"NewtonRaphson.h"
#include<cmath>
#include<iostream>
#include"BSCallTwo.h"
#include"BlackScholesFormulas.h"