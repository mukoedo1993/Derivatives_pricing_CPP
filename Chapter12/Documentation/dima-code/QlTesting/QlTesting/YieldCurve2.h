
// Author: Dimitri Reiswich

void testingYields1(){

	DayCounter dc=ActualActual();
	InterestRate myRate(0.0341, dc, Simple, Annual);

	std::cout << "Rate: " << myRate << std::endl;
	Date d1(10,Sep,2009), d2=d1+3*Months;

	Real compFact=myRate.compoundFactor(d1,d2);
	std::cout << "Compound Factor:" << compFact << std::endl;
	std::cout << "Discount Factor:" << myRate.discountFactor(d1,d2) << std::endl;
	std::cout << "Equivalent Rate:" << myRate.equivalentRate(d1,d2,
			dc,Continuous,Semiannual) << std::endl;

	Real implRate=InterestRate::impliedRate(compFact,d1,d2,dc,Simple,Annual);
	std::cout << "Implied Rate from Comp Fact:" << implRate << std::endl;

}