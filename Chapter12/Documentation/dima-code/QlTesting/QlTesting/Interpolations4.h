
// Author: Dimitri Reiswich


void testingInterpolations3(){


	std::vector<Real> strikeVec(5), volVec(strikeVec.size());

	strikeVec[0]=70.0; volVec[0]=0.241;
	strikeVec[1]=80.0; volVec[1]=0.224;
	strikeVec[2]=90.0; volVec[2]=0.201;
	strikeVec[3]=100.0; volVec[3]=0.211;
	strikeVec[4]=110.0; volVec[4]=0.226;

	CubicNaturalSpline  natCubInt(strikeVec.begin(),strikeVec.end(),
								volVec.begin());
	
	CubicInterpolation natCubIntManual(strikeVec.begin(),strikeVec.end(),volVec.begin(),
                                    CubicInterpolation::Spline, false,
                                    CubicInterpolation::SecondDerivative, 0.0,
                                    CubicInterpolation::SecondDerivative, 0.0);

	std::cout << "Nat Cub: " << natCubInt(75.0) << std::endl;
	std::cout << "Nat Cub Manual: " << natCubIntManual(75.0) << std::endl;

 

}