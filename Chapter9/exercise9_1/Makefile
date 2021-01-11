output: BlackScholesFormulas.o BSCallTwo.o Normals.o SolveMain3.o
	g++ BlackScholesFormulas.o BSCallTwo.o Normals.o SolveMain3.o -o output

BlackScholesFormulas.o: BlackScholesFormulas.cpp BlackScholesFormulas.h Normals.h
	g++ -c BlackScholesFormulas.cpp

BSCallTwo.o: BSCallTwo.cpp BSCallTwo.h BlackScholesFormulas.h
	g++ -c BSCallTwo.cpp

Normals.o: Normals.cpp Normals.h 
	g++ -c Normals.cpp

SolveMain3.o: SolveMain3.cpp NewtonRaphson1.h BlackScholesFormulas.h BSCallTwo.h
	g++ -c SolveMain3.cpp

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