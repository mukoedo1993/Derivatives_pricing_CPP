
// Author: Dimitri Reiswich
void testingYields5(){
    
	std::vector<boost::shared_ptr<RateHelper>> instruments=getRateHelperVector();

	Calendar calendar = TARGET();
	Date today(11,Sep,2009);
	Settings::instance().evaluationDate() = today;
         
	Natural settlementDays = 2;
    Date settlement = calendar.advance(today,settlementDays,Days);

	std::cout << "Settlement Date:" << settlement << std::endl;
	
	DayCounter dc=Actual360();
	boost::shared_ptr<YieldTermStructure> yieldCurve;
  
	yieldCurve = boost::shared_ptr<YieldTermStructure>(new
				PiecewiseYieldCurve<ZeroYield,Linear>(settlementDays,calendar,instruments, dc));
	
	Date d1=settlement+1*Years,d2=d1+3*Months;

	std::cout << "Zero 3M: "	<< yieldCurve->zeroRate(settlement+3*Months,dc,Simple) << std::endl;
	std::cout << "Zero 6M: "	<< yieldCurve->zeroRate(settlement+6*Months,dc,Simple) << std::endl;
	std::cout << "Zero 9M: "	<< yieldCurve->zeroRate(settlement+9*Months,dc,Simple) << std::endl;
	std::cout << "12x15 Fwd: "	<< yieldCurve->forwardRate(d1,d2,dc,Simple)			   << std::endl;
	std::cout << "15x18 Fwd: "	<< yieldCurve->forwardRate(d2,d2+3*Months,dc,Simple)   << std::endl;


	Handle<YieldTermStructure> ycHandle(yieldCurve);
	boost::shared_ptr<IborIndex> libor3m(new USDLibor(Period(3,Months),ycHandle));

	boost::shared_ptr<SwapIndex> swap3yIndex(new UsdLiborSwapIsdaFixAm(Period(3,Years)));

    VanillaSwap swap =    MakeVanillaSwap(Period(8,Years),libor3m)
						  .withEffectiveDate(settlement)
						  .withFixedLegConvention(swap3yIndex->fixedLegConvention())
						  .withFixedLegTenor(swap3yIndex->fixedLegTenor());

 	std::cout << "8Y Swap:" << swap.fairRate() << std::endl;

}