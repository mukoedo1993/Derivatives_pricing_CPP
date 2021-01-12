void testingStochasticProcesses4(){

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

	Real v0=0.12, kappa=1.2, theta=0.08, sigma=0.05, rho=-0.6;
	Real lambda=0.25, nu=0.0, delta=0.30;


	boost::shared_ptr<BatesProcess> batesProcess(new BatesProcess(rdHandle,rqHandle,spotHandle,v0,
		kappa,theta,sigma,rho,lambda,nu,delta, HestonProcess::PartialTruncation));


	BigInteger seed=12324;
	MersenneTwisterUniformRng	unifMt(seed);
	BoxMullerGaussianRng<MersenneTwisterUniformRng> bmGauss(unifMt);

	Time dt=0.10,t=0.0;
	Array dw(4),x(2);
	// x is the 2-dimensional process	
	x[0]=spotQuote->value();
	x[1]=v0;
	Size numVals=10;

	for(Size j=1;j<=numVals;++j){
		dw[0]=bmGauss.next().value;
		dw[1]=bmGauss.next().value;
		dw[2]=bmGauss.next().value;
		dw[3]=bmGauss.next().value;

		x=batesProcess->evolve(t,x,dt,dw);
		std::cout << "Time: " << t+dt << ", S(t): " <<  x[0] << ", V(t): " << x[1] << std::endl;
		t+=dt;
	}

}