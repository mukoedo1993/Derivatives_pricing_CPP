
// Author: Dimitri Reiswich



void testCopulas1(){

	GaussianCopula gaussCop(0.7);
	GumbelCopula gumbCop(1.7);   
	Real x=0.7,y=0.2;

	std::cout << "Gauss Copula:"  << gaussCop(x,y) << std::endl;
	std::cout << "Gumbel Copula:" << gumbCop(x,y) << std::endl;
}