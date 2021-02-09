
// Author: Dimitri Reiswich

void testingFactory2(){

	Real spot=100.0, strike=110.0;
	Rate rd=0.03, rf=0.01;
	Volatility vol=0.20;
	Time mat=1.0;
	MyOption::Type type(MyOption::Call);

	MyOption optionMade=MakeMyOption()
			.withType(type)
			.withMat(mat)
			.withSpot(spot)
			.withForRate(rf)
			.withStrike(strike)
			.withVol(vol)
			.withDomRate(rd);

	std::cout << "Mat Made:"    << optionMade.getMat() << std::endl;
	std::cout << "Spot Made:"	<< optionMade.getSpot() << std::endl;
	std::cout << "Strike Made:"	<< optionMade.getStrike() << std::endl;

}