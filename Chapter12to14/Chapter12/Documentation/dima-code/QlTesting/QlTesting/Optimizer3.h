
// Author: Dimitri Reiswich


void testOptimizer1(){

	Size maxIterations=1000;
	Size minStatIterations=100;
	Real rootEpsilon=1e-8;
	Real functionEpsilon=1e-9;
	Real gradientNormEpsilon=1e-5;
	
	EndCriteria myEndCrit(	maxIterations,
							minStatIterations,
							rootEpsilon,
							functionEpsilon,
							gradientNormEpsilon);

	RosenBrockFunction myFunc;
	NoConstraint constraint;

	Problem myProb1(myFunc, constraint, Array(2,0.1));
	Problem myProb2(myFunc, constraint, Array(2,0.1));
	
	Simplex solver1(0.1);
	ConjugateGradient solver2;

	EndCriteria::Type solvedCrit1=solver1.minimize(myProb1,myEndCrit);
	EndCriteria::Type solvedCrit2=solver2.minimize(myProb2,myEndCrit);

	std::cout << "Criteria Simplex:"<< solvedCrit1 << std::endl;
	std::cout << "Root Simplex:"<< myProb1.currentValue() << std::endl;
	std::cout << "Min F Value Simplex:"<< myProb1.functionValue() << std::endl;
	std::cout << "Criteria CG:"<< solvedCrit2 << std::endl;
	std::cout << "Root CG:"<< myProb2.currentValue() << std::endl;
	std::cout << "Min F Value CG:"<< myProb2.functionValue() << std::endl;

}