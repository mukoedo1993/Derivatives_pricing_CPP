
// Author: Dimitri Reiswich

void testingDesignPatterns2a(){

	boost::shared_ptr<SimpleYield> myYield(new SimpleYield(0.03));
	Date mat=Date::todaysDate()+12*Months;
	DayCounter dc=ActualActual();

	SimpleDiscountFactor1 myDf(myYield, mat,dc);
	
	std::cout << "Discount before yield update:" << myDf.getDiscount() << std::endl;
	myYield->setYield(0.01);
	std::cout << "Discount after yield update:" << myDf.getDiscount() << std::endl;
	Settings::instance().evaluationDate()=mat-1*Months;
	std::cout << "Discount after evaluation date update:" << myDf.getDiscount() << std::endl;

}