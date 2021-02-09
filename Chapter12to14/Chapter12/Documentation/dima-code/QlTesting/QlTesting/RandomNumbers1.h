
// Author: Dimitri Reiswich

void testingRandomNumbers1(){

	BigInteger seed=SeedGenerator::instance().get();
	std::cout << "Seed 1: " << seed << std::endl;

	MersenneTwisterUniformRng	unifMt(seed);
	LecuyerUniformRng unifLec(seed);
	KnuthUniformRng unifKnuth(seed);
  

	std::cout << "Mersenne Twister Un:" << unifMt.next().value << std::endl;
	std::cout << "Lecuyer Un:" << unifLec.next().value << std::endl;
	std::cout << "Knut Un:" << unifKnuth.next().value << std::endl;

	seed=SeedGenerator::instance().get();
	std::cout << "--------------------------" << std::endl;
	std::cout << "Seed 2: " << seed << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "Mersenne Twister Un:" << unifMt.next().value << std::endl;
	std::cout << "Lecuyer Un:" << unifLec.next().value << std::endl;
	std::cout << "Knut Un:" << unifKnuth.next().value << std::endl;

}
