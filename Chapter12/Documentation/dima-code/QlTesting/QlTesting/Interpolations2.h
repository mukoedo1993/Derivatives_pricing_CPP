
// Author: Dimitri Reiswich
#include<map>

void testingInterpolations2(){
	
	std::vector<Real> strikeVec(5), volVec(strikeVec.size());

	strikeVec[0]=70.0; volVec[0]=0.241;
	strikeVec[1]=80.0; volVec[1]=0.224;
	strikeVec[2]=90.0; volVec[2]=0.201;
	strikeVec[3]=100.0; volVec[3]=0.211;
	strikeVec[4]=110.0; volVec[4]=0.226;

	CubicNaturalSpline  natCubInt(strikeVec.begin(),strikeVec.end(),
								volVec.begin());
 
	std::cout << "Vol at 70.0  " << natCubInt(70.0) << std::endl;
	std::cout << "Vol at 75.0  " << natCubInt(75.0) << std::endl;
	std::cout << "Vol at 79.0  " << natCubInt(79.0) << std::endl;
}