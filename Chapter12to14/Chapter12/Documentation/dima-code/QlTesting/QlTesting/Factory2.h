
// Author: Dimitri Reiswich

void testingFactory1(){

	Real spot=100.0, strike=110.0;
	Rate rd=0.03, rf=0.01;
	Volatility vol=0.20;
	Time mat=1.0;
	MyOption::Type type(MyOption::Call);
	
	MyOption option(mat,vol,type,spot,rf,rd,strike);

	std::cout << "Mat:"    << option.getMat() << std::endl;
	std::cout << "Spot:"   << option.getSpot() << std::endl;
	std::cout << "Strike:" << option.getStrike() << std::endl;

}