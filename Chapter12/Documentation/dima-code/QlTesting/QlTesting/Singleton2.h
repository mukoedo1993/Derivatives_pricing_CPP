
// Author: Dimitri Reiswich

#include <boost/foreach.hpp>
#include "Singleton1.h"

void addVariable();

void testingSingleton1(){
	
	addVariable();

	std::string myStr1("myStr1");
	std::vector<int> myVec1(6,2);

	ObjectRepository::instance().addObject("str1",myStr1);
	ObjectRepository::instance().addObject("vec1",myVec1);
	
	std::string myDblId("dbl1");

	ObjectRepository::Error myErr;

	boost::optional<double> myDblGet=ObjectRepository::instance().getObject<double>(myDblId,myErr);

	std::cout << "Object exits?: " << ObjectRepository::instance().objectExists(myDblId)<<std::endl;
	std::cout << "getObject double return: "<< myDblGet << std::endl;
	std::cout << "dereferenced double return: "<< *myDblGet << std::endl;
	std::cout << "Error: " << myErr << std::endl;
	std::cout << "-------------------------------" << std::endl;

	boost::optional<std::vector<int>> myVecGet=
				ObjectRepository::instance().getObject<std::vector<int>>("vec1");

	std::cout << "getObject vector return: " << myVecGet << std::endl;

	BOOST_FOREACH(int x,*myVecGet) std::cout << x << std::endl;

}

void addVariable(){
	double myDbl1=2.123;
	ObjectRepository::instance().addObject("dbl1",myDbl1);
}
