
// Author: Dimitri Reiswich
void testingSwaps1(){

	boost::shared_ptr<YieldTermStructure> curvePtr=getZeroYieldCurve();
	Handle<YieldTermStructure> curve(curvePtr);

	Date refDate=curve->referenceDate();

	UsdLiborSwapIsdaFixAm isdaSwap(Period(3,Years),curve);
	
	boost::shared_ptr<VanillaSwap> mySwap=isdaSwap.underlyingSwap(refDate);
	mySwap->setPricingEngine(boost::shared_ptr<PricingEngine>(
							new DiscountingSwapEngine(curve)));

	std::cout << "Fair Rate:" << mySwap->fairRate() << std::endl;
	std::cout << "NPV Floating:" << mySwap->fixedLegNPV() << std::endl;
	std::cout << "NPV Fix:" << mySwap->floatingLegNPV() << std::endl;
	std::cout << "Type:" << mySwap->type() << std::endl;
	std::cout << "Nominal:" << mySwap->nominal() << std::endl;
	std::cout << "-----------------" << std::endl;
	Schedule fixedSchedule=mySwap->fixedSchedule();
	std::vector<Date> dates=fixedSchedule.dates();
	BOOST_FOREACH(Date d, dates) std::cout << "Fixed Leg Dates:" << d << std::endl;
	std::cout << "-----------------" << std::endl;
	Schedule floatSchedule=mySwap->floatingSchedule();
	dates=floatSchedule.dates();
	BOOST_FOREACH(Date d, dates) std::cout << "Floating Leg Dates:" << d << std::endl;
}