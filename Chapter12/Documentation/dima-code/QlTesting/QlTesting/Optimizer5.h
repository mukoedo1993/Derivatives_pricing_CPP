
// Author: Dimitri Reiswich
void testOptimizer2(){
	// setup of market parameters
	Real spot=98.51;
	Volatility vol=0.134;
	Real K1=87.0, K2=96.0, K3=103.0, K4=110.0;	
	Rate rd=0.002, rf=0.01;
	Integer phi=1;
	Time tau=0.6;
	// calculate Black Scholes prices
	Real C1=blackScholesPrice(spot,K1,rd,rf,vol,tau,phi);
	Real C2=blackScholesPrice(spot,K2,rd,rf,vol,tau,phi);
	Real C3=blackScholesPrice(spot,K3,rd,rf,vol,tau,phi);
	Real C4=blackScholesPrice(spot,K4,rd,rf,vol,tau,phi);

	CallProblemFunction optFunc(rd, rf, tau, phi,K1, K2, K3, K4, C1, C2, C3, C4);

	Size maxIterations=1000;
	Size minStatIterations=100;
	Real rootEpsilon=1e-5;
	Real functionEpsilon=1e-5;
	Real gradientNormEpsilon=1e-5;
	
	EndCriteria myEndCrit(maxIterations,minStatIterations, rootEpsilon,
		functionEpsilon, gradientNormEpsilon);

	Array startVal(2); startVal[0]=80.0; startVal[1]=0.20;
	NoConstraint constraint;
	Problem myProb(optFunc, constraint, startVal);
	LevenbergMarquardt solver;
	EndCriteria::Type solvedCrit=solver.minimize(myProb,myEndCrit);

	std::cout << "Criteria :"<< solvedCrit << std::endl;
	std::cout << "Root :" << myProb.currentValue() << std::endl;
	std::cout << "Min Function Value :"	<< myProb.functionValue() << std::endl;
}