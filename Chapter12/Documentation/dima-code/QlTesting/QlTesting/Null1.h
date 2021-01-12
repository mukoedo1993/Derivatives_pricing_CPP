
// Author: Dimitri Reiswich


#include <boost/limits.hpp>

void testingNull1(){

	Real a=12.4;
	Null<Real> null;

	bool aIsNull=(a==null);
	Real aMax=(std::numeric_limits<float>::max)();
	bool aMaxIsNull=(aMax==null);

	std::cout << "aIsNull: "		<< aIsNull << std::endl;
	std::cout << "aMax: "			<< aMax << std::endl;
	std::cout << "aMaxIsNull: "		<< aMaxIsNull << std::endl;

}