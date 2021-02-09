
// Author: Dimitri Reiswich
#include<vector>

void testingInterpolations4(){
	
	std::vector<Real> xVec(5), yVec(xVec.size());

	xVec[0]=0.0; yVec[0]=std::exp(0.0);
	xVec[1]=1.0; yVec[1]=std::exp(1.0);
	xVec[2]=2.0; yVec[2]=std::exp(2.0);
	xVec[3]=3.0; yVec[3]=std::exp(3.0);
	xVec[4]=4.0; yVec[4]=std::exp(4.0);

	LinearInterpolation linInt(xVec.begin(), xVec.end(), yVec.begin());
 
	std::cout << "Exp at 0.5 original " << linInt(0.5) << std::endl;
	yVec[1]=std::exp(5.0);
	std::cout << "Exp at 0.5 resetted not updated:" << linInt(0.5) << std::endl;
	linInt.update();
	std::cout << "Exp at 0.5 updated:" << linInt(0.5) << std::endl;
}