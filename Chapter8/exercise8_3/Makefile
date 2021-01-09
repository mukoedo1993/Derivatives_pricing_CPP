output: Arrays.o TrinomialTree.o BlackScholesFormulas.o Normals.o Parameters.o PayOff3.o PayOffBridge.o PayOffForward.o TreeAmerican.o TreeEuropean.o TreeProducts.o TreeMain2.o 
	g++ Arrays.o TrinomialTree.o BlackScholesFormulas.o Normals.o Parameters.o PayOff3.o PayOffBridge.o PayOffForward.o TreeAmerican.o TreeEuropean.o TreeProducts.o TreeMain2.o -o output

Arrays.o: Arrays.cpp Arrays.h
	g++ -c Arrays.cpp

TrinomialTree.o: TrinomialTree.cpp TrinomialTree.h TreeProducts.h Parameters.h Arrays.h
	g++ -c TrinomialTree.cpp

BlackScholesFormulas.o: BlackScholesFormulas.cpp BlackScholesFormulas.h
	g++ -c BlackScholesFormulas.cpp

Normals.o: Normals.cpp Normals.h
	g++ -c Normals.cpp

Parameters.o: Parameters.cpp Parameters.h
	g++ -c Parameters.cpp

PayOff3.o: PayOff3.cpp PayOff3.h
	g++ -c PayOff3.cpp

PayOffBridge.o: PayOffBridge.cpp PayOffBridge.h
	g++ -c PayOffBridge.cpp

PayOffForward.o: PayOffForward.cpp PayOffForward.h PayOff3.h
	g++ -c PayOffForward.cpp

TreeAmerican.o: TreeAmerican.cpp TreeAmerican.h TreeProducts.h PayOffBridge.h
	g++ -c TreeAmerican.cpp

TreeEuropean.o: TreeEuropean.cpp TreeEuropean.h TreeProducts.h PayOffBridge.h
	g++ -c TreeEuropean.cpp

TreeProducts.o: TreeProducts.cpp TreeProducts.h
	g++ -c TreeProducts.cpp

TreeMain2.o: TreeMain2.cpp TrinomialTree.h TreeAmerican.h TreeEuropean.h BlackScholesFormulas.h PayOffForward.h
	g++ -c TreeMain2.cpp
clean: 
	rm *.o output
