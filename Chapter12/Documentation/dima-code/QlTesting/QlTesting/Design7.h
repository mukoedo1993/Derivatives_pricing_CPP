
// Author: Dimitri Reiswich

void testingDesignPatterns3(){

	boost::shared_ptr<SimpleYield> myYield(new SimpleYield(0.03));
	Time mat=1.0;
	// construct observer of yield curve
	boost::shared_ptr<SimpleDiscountFactor> myDf(
		new SimpleDiscountFactor(myYield, mat));
	// construct observer of discount factor
	SimpleDiscountedCF myCf(myDf);

	std::cout << "Cash Flow before update:" << myCf.discountCashFlow(100.0) << std::endl;
	myYield->setYield(0.01);
	std::cout << "Cash Flow after update:" << myCf.discountCashFlow(100.0) << std::endl;

}