output: Arrays.o BinomialTree.o BlackScholesFormulas.o Normals.o Parameters.o PayOff3.o PayOffBridge.o PayOffForward.o TreeAmerican.o TreeEuropean.o TreeBarrier.o TreeProducts.o TreeMain1.o 
	g++ Arrays.o BinomialTree.o BlackScholesFormulas.o Normals.o Parameters.o PayOff3.o PayOffBridge.o PayOffForward.o TreeAmerican.o TreeEuropean.o TreeBarrier.o TreeProducts.o TreeMain1.o -o output

Arrays.o: Arrays.cpp Arrays.h
	g++ -c Arrays.cpp

BinomialTree.o: BinomialTree.cpp BinomialTree.h TreeProducts.h Parameters.h Arrays.h
	g++ -c BinomialTree.cpp

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

TreeBarrier.o: TreeBarrier.cpp TreeBarrier.h TreeProducts.h PayOffBridge.h
	g++ -c TreeBarrier.cpp

TreeProducts.o: TreeProducts.cpp TreeProducts.h
	g++ -c TreeProducts.cpp

TreeMain1.o: TreeMain1.cpp BinomialTree.h TreeAmerican.h TreeEuropean.h BlackScholesFormulas.h PayOffForward.h
	g++ -c TreeMain1.cpp

clean: 
	rm *.o output
