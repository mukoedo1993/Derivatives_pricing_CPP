
// Author: Dimitri Reiswich


void testSolver2(){

// setup of market parameters
	Real spot=100.0,strike=110.0; 
	Rate rd=0.002, rf=0.01, tau=0.5;
	Integer phi=1;
	Real vol=0.1423;
	// calculate corresponding Black Scholes price
	Real price=blackScholesPrice(spot,strike,rd,rf,vol,tau,phi);

	BlackScholesClass solvProblem(spot,strike,rd,rf,tau,phi,price);

	Newton mySolv;
	Real accuracy=0.00001, guess=0.10;
	Real step=0.001;
	// solve the problem
	Real res=mySolv.solve(solvProblem,accuracy,guess,step);

	std::cout << "Input Volatility:" << vol << std::endl;
	std::cout << "Implied Volatility:" << res << std::endl;
}