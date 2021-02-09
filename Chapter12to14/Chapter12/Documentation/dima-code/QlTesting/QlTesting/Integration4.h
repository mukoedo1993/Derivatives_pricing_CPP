
// Author: Dimitri Reiswich
#include <boost/math/distributions.hpp>

Real callFunc(Real spot, Real strike,
			  Rate r, Volatility vol, Time tau, Real x){

	Real mean=log(spot)+(r-0.5*vol*vol)*tau;
	Real stdDev=vol*sqrt(tau);

	boost::math::lognormal_distribution<> d(mean,stdDev);
	return (x-strike)*pdf(d,x)*exp(-r*tau);
}


void testIntegration4(){

	Real spot=100.0;
	Rate r=0.03;
	Time tau=0.5;
	Volatility vol=0.20;
	Real strike=110.0;

	Real a=strike, b=strike*10.0; 

	boost::function<Real (Real)> ptrF;
	ptrF=boost::bind(&callFunc,spot,strike,r,vol,tau,_1);

	Real absAcc=0.00001;
	Size maxEval=1000;
	SimpsonIntegral	numInt(absAcc,maxEval);
	
	std::cout << "Call Value: " << numInt(ptrF,a,b) << std::endl;
}