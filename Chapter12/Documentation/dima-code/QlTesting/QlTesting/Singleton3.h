
// Author: Dimitri Reiswich

#include <boost/foreach.hpp>
#include "Singleton1.h"

void addVariable();

void testingSingleton2(){
	
	try{

	addVariable();

	double myDbl2=4.144,myDbl3=3.122;
	std::string myStr1("myStr1"),myStr2("myStr2");
	std::vector<int> myVec1(6,2),myVec2(10,1),myVec3(2,2),myVec4(4,1);

	ObjectRepository::instance().addObject("dbl2",myDbl2);
	ObjectRepository::instance().addObject("dbl3",myDbl3);


	ObjectRepository::instance().addObject("str1",myStr1);
	ObjectRepository::instance().addObject("str2",myStr2);

	ObjectRepository::instance().addObject("vec1",myVec1);
	ObjectRepository::instance().addObject("vec2",myVec2);
	ObjectRepository::instance().addObject("vec3",myVec3);
	ObjectRepository::instance().addObject("vec4",myVec4);

	std::cout << "Number Objects:" << ObjectRepository::instance().numberObjects() << std::endl;
	std::cout << "Number Doubles:" << ObjectRepository::instance().getObjectCount<double>() << std::endl;
	std::cout << "Number Strings:" << ObjectRepository::instance().getObjectCount<std::string>() << std::endl;
	std::cout << "Number Vectors:" << ObjectRepository::instance().getObjectCount<std::vector<int>>() << std::endl;
	std::cout << "-------------------------------" << std::endl;

	std::string myDblId("dbl1");
	ObjectRepository::Error err;

	boost::optional<double> myDblGet =ObjectRepository::instance().getObject<double>(myDblId,err);

	std::cout << "Object exits?: " << ObjectRepository::instance().objectExists(myDblId)<<std::endl;
	std::cout << "getObject double return: "<< myDblGet << std::endl;
	std::cout << "dereferenced double return: "<< *myDblGet << std::endl;
	std::cout << "Error: " << err<< std::endl;
	std::cout << "-------------------------------" << std::endl;

	ObjectRepository::instance().deleteObject(myDblId);
	myDblGet=ObjectRepository::instance().getObject<double>(myDblId,err);
	std::cout << "Object exits?: " << ObjectRepository::instance().objectExists(myDblId)<<std::endl;
	std::cout << "getObject after delete return: "<< myDblGet << std::endl;
	std::cout << "Error: " << err<< std::endl;
	std::cout << "-------------------------------" << std::endl;
	
	
	double myDbl1=2.123;
	// reverse deleting
	ObjectRepository::instance().addObject(myDblId,myDbl1);

	// try to get string from double
	boost::optional<std::string> wrongTypeGet
						=ObjectRepository::instance().getObject<std::string>(myDblId,err);

	std::cout << "getObject wrong type return: " << wrongTypeGet << std::endl;
	std::cout << "Error: " << err << std::endl;
	std::cout << "-------------------------------" << std::endl;

	// try to look for wrong id
	boost::optional<double> wrongDblType=ObjectRepository::instance().getObject<double>("myDblFalse",err);

	std::cout << "getObject wrong id return: "<< wrongDblType << std::endl;
	std::cout << "Error: " << err << std::endl;
	std::cout << "-------------------------------" << std::endl;


	boost::optional<std::vector<int>> myVecGet=
				ObjectRepository::instance().getObject<std::vector<int>>("vec1",err);

	std::cout << "getObject vector return: " << myVecGet << std::endl;
	std::cout << "Error: " << err << std::endl;

	BOOST_FOREACH(int x,*myVecGet) std::cout << x << std::endl;



	} catch (std::exception& e) {
        std::cout << e.what() << std::endl;

	} catch (...) {
        std::cout << "unknown error" << std::endl;
    }


}

void addVariable(){
	double myDbl1=2.123;
	ObjectRepository::instance().addObject("dbl1",myDbl1);
}
