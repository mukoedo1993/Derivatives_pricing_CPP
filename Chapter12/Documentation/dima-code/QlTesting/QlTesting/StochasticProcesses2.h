
void testingStochasticProcesses2(){

	Real x0=0.0311;
	Real x;
	Real theta=0.015;
	Real kappa=0.5;
	Real vol=0.02;

	BigInteger seed=12324;
	MersenneTwisterUniformRng	unifMt(seed);
	BoxMullerGaussianRng<MersenneTwisterUniformRng> bmGauss(unifMt);

	boost::shared_ptr<OrnsteinUhlenbeckProcess> shortRateProces(
		new OrnsteinUhlenbeckProcess(kappa,vol,x0,theta));

	Time dt=0.5,t=0.0;
	Real dw;

	Real mean=0.0,var=0.0;
	Size numVals=10000;

	for(Size j=1;j<=numVals;++j){
		dw=bmGauss.next().value;

		x=shortRateProces->evolve(t,x0,dt,dw);
		mean+=x;
		var+=x*x;
	}

	Real analyticMean=std::exp(-kappa*dt)*x0+theta*(1-std::exp(-kappa*dt));
	Real analyticVar=vol*vol*(0.5/kappa)*(1-std::exp(-2*kappa*dt));
	Real estimatedMean=mean/numVals;
	Real estimatedVar=var/numVals-estimatedMean*estimatedMean;

	std::cout << "Analytical Mean:"		<< analyticMean << std::endl;
	std::cout << "Estimated Mean:"		<< estimatedMean << std::endl;
	std::cout << "Analytical Variance:" << analyticVar << std::endl;
	std::cout << "Estimated Variance:"	<< estimatedVar << std::endl;

}