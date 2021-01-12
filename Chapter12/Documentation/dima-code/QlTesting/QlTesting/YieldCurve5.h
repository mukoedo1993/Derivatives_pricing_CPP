
// Author: Dimitri Reiswich
void testingYields3(){
    
std::vector<boost::shared_ptr<RateHelper>> instruments;

// ++++++++++++++++++++ 1M USD Libor ++++++++++++++++++++++++++++++++++++++++
// Quote and Handle setup
	boost::shared_ptr<Quote> libor1m(new SimpleQuote(0.0024375));
	Handle<Quote> libor1mHandle(libor1m);
	//index
	boost::shared_ptr<IborIndex> libor1mIndex(new  USDLibor(Period(1,Months)));
	// initialize rate helper
	boost::shared_ptr<RateHelper> rateHelper1m(new 
			DepositRateHelper(libor1mHandle,libor1mIndex));
	instruments.push_back(rateHelper1m);
// ++++++++++++++++++++ 12X15 FRA ++++++++++++++++++++++++++++++++++++++++
	boost::shared_ptr<Quote> fra12x15m(new SimpleQuote(0.01267));
	Handle<Quote> fra12x15mHandle(fra12x15m);

	boost::shared_ptr<IborIndex> libor3mIndex(new USDLibor(Period(3,Months)));
	// initialize rate helper
	boost::shared_ptr<RateHelper> rateHelper12x15m(new 
			FraRateHelper(fra12x15mHandle,Period(12,Months), libor3mIndex));
	instruments.push_back(rateHelper12x15m);	
// ++++++++++++++++++++ 2Y USD ISDA Fix Swap ++++++++++++++++++++++++++++++++++++++++
// Quote and Handle setup
	boost::shared_ptr<Quote> swap2y(new SimpleQuote(0.01226));
	Handle<Quote> swap2yHandle(swap2y);
	//index
	boost::shared_ptr<SwapIndex> swap2yIndex(new UsdLiborSwapIsdaFixAm(Period(2,Years)));
	// initialize rate helper
	boost::shared_ptr<RateHelper> rateHelper2y(new 
			SwapRateHelper(swap2yHandle,swap2yIndex));
	instruments.push_back(rateHelper2y);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}