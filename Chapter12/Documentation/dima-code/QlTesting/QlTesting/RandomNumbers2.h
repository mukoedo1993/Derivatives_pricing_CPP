
// Author: Dimitri Reiswich

void testingRandomNumbers2(){

	BigInteger seed=12324;
	MersenneTwisterUniformRng	unifMt(seed);
	BoxMullerGaussianRng<MersenneTwisterUniformRng> bmGauss(unifMt);

	std::cout << bmGauss.next().value << std::endl;
	std::cout << bmGauss.next().value << std::endl;
	std::cout << bmGauss.next().value << std::endl;
	std::cout << bmGauss.next().value << std::endl;
	std::cout << bmGauss.next().value << std::endl;

}