void testingStochasticProcesses1(){

	Date refDate=Date(27,Sep,2009);
	Rate riskFreeRate=0.0321;
	Rate dividendRate=0.0128;
	Real spot=52.0;
	Rate vol=0.2144;
	Calendar cal=TARGET();
	DayCounter dc=ActualActual();

	boost::shared_ptr<YieldTermStructure> rdStruct(new FlatForward(refDate,riskFreeRate,dc));
	boost::shared_ptr<YieldTermStructure> rqStruct(new FlatForward(refDate,dividendRate,dc));
	Handle<YieldTermStructure> rdHandle(rdStruct);
	Handle<YieldTermStructure> rqHandle(rqStruct);

	boost::shared_ptr<SimpleQuote> spotQuote(new SimpleQuote(spot));
	Handle<Quote> spotHandle(spotQuote);

	boost::shared_ptr<BlackVolTermStructure> volQuote(new BlackConstantVol(refDate, cal, vol, dc));
	Handle<BlackVolTermStructure> volHandle(volQuote);

	boost::shared_ptr<BlackScholesMertonProcess> bsmProcess(
                 new BlackScholesMertonProcess(spotHandle,rqHandle, rdHandle,volHandle));

	BigInteger seed=12324;
	MersenneTwisterUniformRng	unifMt(seed);
	BoxMullerGaussianRng<MersenneTwisterUniformRng> bmGauss(unifMt);

	Time dt=0.10,t=0.0;
	Real x=spotQuote->value();
	Real dw;
	Size numVals=10;
	
	std::cout << "Risk neutral drift: " << bsmProcess->drift(t+dt,x) << std::endl; 
	std::cout << "Diffusion: " << bsmProcess->diffusion(t+dt,x) << std::endl; 
	std::cout << "----------------------" << std::endl;

	for(Size j=1;j<=numVals;++j){
		dw=bmGauss.next().value;
		x=bsmProcess->evolve(t,x,dt,dw);
		std::cout << "Time: " << t+dt << ", S_t: " <<  x << std::endl;
		t+=dt;
	}
}