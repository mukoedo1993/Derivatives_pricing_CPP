output: BlackScholesFormulas.o BSCallClass.o Normals.o SolveMain1.o Bisection.o
	g++ BlackScholesFormulas.o BSCallClass.o Normals.o SolveMain1.o Bisection.o -o output

BSCallClass.o: BSCallClass.cpp BSCallClass.h
	g++ -c BSCallClass.cpp

BlackScholesFormulas.o: BlackScholesFormulas.cpp BlackScholesFormulas.h Normals.h
	g++ -c BlackScholesFormulas.cpp

Normals.o: Normals.cpp Normals.h
	g++ -c Normals.cpp

SolveMain1.o: SolveMain1.cpp BSCallClass.h BlackScholesFormulas.h
	g++ -c SolveMain1.cpp

Bisection.o: Bisection.cpp Bisection.h
	g++ -c Bisection.cpp

clean:
	rm *.o output