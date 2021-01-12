
// Author: Dimitri Reiswich
void testingVolatilityObjects1(){

	Time tau=0.45,st=std::sqrt(tau);

	std::vector<Rate> strikes(6);
	strikes[0]=78.0;	strikes[1]=88.0;	strikes[2]=98.0;
	strikes[3]=108.0;	strikes[4]=118.0;	strikes[5]=128.0;

	boost::shared_ptr<Quote> q1(new SimpleQuote(0.2406*st)); Handle<Quote> h1(q1);
	boost::shared_ptr<Quote> q2(new SimpleQuote(0.2213*st)); Handle<Quote> h2(q2);
	boost::shared_ptr<Quote> q3(new SimpleQuote(0.2102*st)); Handle<Quote> h3(q3);
	boost::shared_ptr<Quote> q4(new SimpleQuote(0.2156*st)); Handle<Quote> h4(q4);
	boost::shared_ptr<Quote> q5(new SimpleQuote(0.2299*st)); Handle<Quote> h5(q5);
	boost::shared_ptr<Quote> q6(new SimpleQuote(0.2501*st)); Handle<Quote> h6(q6);

	std::vector<Handle<Quote>> volVec(strikes.size());
	volVec[0]=h1; volVec[1]=h2; volVec[2]=h3; volVec[3]=h4;	volVec[4]=h5;	volVec[5]=h6;

	InterpolatedSmileSection<Cubic> smileSect(tau,strikes,volVec,h3);
	
	Real K1=88.0, K2=93.0;

	std::cout << "Min strike:" << smileSect.minStrike() << std::endl;
	std::cout << "Max strike:" << smileSect.maxStrike() << std::endl;
	std::cout << "Atm vol:" << smileSect.atmLevel() << std::endl;
	std::cout << "Volatility at K1:" << smileSect.volatility(K1) << std::endl;
	std::cout << "Variance at K1:" << smileSect.variance(K1) << std::endl;
	std::cout << "Volatility at K2:" << smileSect.volatility(K2) << std::endl;
	std::cout << "Variance at K2:" << smileSect.variance(K2) << std::endl;
}