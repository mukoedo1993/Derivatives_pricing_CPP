
// Author: Dimitri Reiswich
void testSolver1(){

	// setup of market parameters
	Real spot=100.0,strike=110.0; 
	Rate rd=0.002, rf=0.01, tau=0.5;
	Integer phi=1;
	Real vol=0.1423;

	// calculate corresponding Black Scholes price
	Real price=blackScholesPrice(spot,strike,rd,rf,vol,tau,phi);
	// setup a solver
	Bisection mySolv1; Brent mySolv2; Ridder mySolv3;
	Real accuracy=0.00001, guess=0.25;
	Real min=0.0, max=1.0;
	// setup a boost function
	boost::function<Real (Volatility)> myVolFunc;
	// bind the boost function to all market parameters, keep vol as variant
	myVolFunc=boost::bind(&impliedVolProblem,spot,strike,rd,rf,_1,tau,phi,price);
	// solve the problem
	Real res1=mySolv1.solve(myVolFunc,accuracy,guess,min,max);
	Real res2=mySolv2.solve(myVolFunc,accuracy,guess,min,max);
	Real res3=mySolv3.solve(myVolFunc,accuracy,guess,min,max);

	std::cout << "Input Volatility:" << vol << std::endl;
	std::cout << "Implied Volatility Bisection:" << res1 << std::endl;
	std::cout << "Implied Volatility Brent:" << res2 << std::endl;
	std::cout << "Implied Volatility Ridder:" << res3 << std::endl;

}