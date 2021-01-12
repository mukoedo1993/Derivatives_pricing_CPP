
// Author: Dimitri Reiswich
#include <boost/assign.hpp>
using namespace boost::assign; // bring 'operator+=()' into scope

void testHandle1(){

	boost::shared_ptr<SimpleYield> yield(new SimpleYield(0.04));
	RelinkableHandle<SimpleYield> yieldHandle(yield);
	Time mat=10.0;
	SimpleDiscountFactor2 myDf(yieldHandle,mat);

	std::cout << "Initial Discount:" << myDf.getDiscount() << std::endl;
	yield->setYield(0.06);
	std::cout << "Discount after yield update:" << myDf.getDiscount() << std::endl;
	boost::shared_ptr<SimpleYield> yieldNew(new SimpleYield(0.01));
	yieldHandle.linkTo(yieldNew);
	std::cout << "Discount after relinking:" << myDf.getDiscount() << std::endl;
}