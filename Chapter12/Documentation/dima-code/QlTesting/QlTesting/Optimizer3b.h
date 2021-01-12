
// Author: Dimitri Reiswich


void testOptimizer1(){

	Size maxIterations=1000;
	Size minStatIterations=100;
	Real rootEpsilon=1e-5;
	Real functionEpsilon=1e-5;
	Real gradientNormEpsilon=1e-5;
	
	EndCriteria myEndCrit(	maxIterations,
							minStatIterations,
							rootEpsilon,
							functionEpsilon,
							gradientNormEpsilon);

	RosenBrockFunction myFunc;
    NoConstraint constraint;

	Problem myProb0(myFunc, constraint, Array(2,2.1));
	LevenbergMarquardt solver0;
	EndCriteria::Type solvedCrit0=solver0.minimize(myProb0,myEndCrit);

	std::cout << "Criteria 0:"				<< solvedCrit0 << std::endl;
	std::cout << "Root 0:"					<< myProb0.currentValue() << std::endl;
	std::cout << "Min Function Value 0:"	<< myProb0.functionValue() << std::endl;

/*
	
	 Array coefficients(3, 1.0);
     OneDimensionalPolynomialDegreeN oneDimensionalPolynomialDegreeN(coefficients);
	 NoConstraint constraint;
     Array initialValues(1, 100.0);
     
	 Problem problem(oneDimensionalPolynomialDegreeN, constraint,
                            initialValues);
     LevenbergMarquardt optimizationMethod;
     EndCriteria endCriteria(1000, 100, 1e-5, 1e-5, 1e-5);
     optimizationMethod.minimize(problem, endCriteria);
	
	 std::cout << problem.currentValue() << std::endl;
	 std::cout << problem.functionValue() << std::endl;
*/
	       //Simplex optimizationMethod(0.1);
            //ConjugateGradient optimizationMethod;
            //SteepestDescent optimizationMethod;
     
	
	
	
	
	/*	RosenBrockFunction myFunc;
    NoConstraint constraint;
          
	Problem myProb0(myFunc, constraint, Array(2,0.1));
	Problem myProb1(myFunc, constraint, Array(2,0.1));
	Problem myProb2(myFunc, constraint, Array(2,0.1));
	Problem myProb3(myFunc, constraint, Array(2,0.1));*/

  //  LevenbergMarquardt solver0;
//	Simplex solver1(0.2);
//	ConjugateGradient solver2;
//	SteepestDescent solver3;

//	EndCriteria::Type solvedCrit0=solver0.minimize(myProb0,myEndCrit);
//	EndCriteria::Type solvedCrit1=solver1.minimize(myProb1,myEndCrit);
//	EndCriteria::Type solvedCrit2=solver2.minimize(myProb2,myEndCrit);
//	EndCriteria::Type solvedCrit3=solver3.minimize(myProb3,myEndCrit);

//	std::cout << "Criteria 0:"				<< solvedCrit0 << std::endl;
//	std::cout << "Root 0:"					<< myProb0.currentValue() << std::endl;
//	std::cout << "Min Function Value 0:"	<< myProb0.functionValue() << std::endl;


//	std::cout << "Criteria 1:" << solvedCrit1 << std::endl;
//	std::cout << "Root 1:" << myProb1.currentValue() << std::endl;
//	std::cout << "Min Function Value 1:" << myProb1.functionValue() << std::endl;

/*	std::cout << "Criteria 2:" << solvedCrit2 << std::endl;
	std::cout << "Criteria 3:" << solvedCrit3 << std::endl;
	std::cout << "Root 2:" << myProb2.currentValue() << std::endl;
	std::cout << "Min Function Value 2:" << myProb2.functionValue() << std::endl;
	std::cout << "Root 3:" << myProb3.currentValue() << std::endl;
	std::cout << "Min Function Value 3:" << myProb3.functionValue() << std::endl;
*/

//	Array x(2); x[0]=1.0; x[1]=1.0;


//	std::cout << myFunc.value(x) << std::endl;
//	std::cout << myFunc.values(x) << std::endl;

//	Problem(CostFunction& costFunction,
//			NoConstraint,
//		const Array& initialValue = Array())


}