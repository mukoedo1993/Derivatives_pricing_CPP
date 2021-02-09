
// Author: Dimitri Reiswich


void testingDesignPatterns2(){

	boost::shared_ptr<SimpleYield> myYield(new SimpleYield(0.03));
	Time mat=1.0;
	SimpleDiscountFactor myDf(myYield, mat);
	std::cout << "Discount before update:" << myDf.getDiscount() << std::endl;
	myYield->setYield(0.01);
	std::cout << "Discount after update:" << myDf.getDiscount() << std::endl;

}