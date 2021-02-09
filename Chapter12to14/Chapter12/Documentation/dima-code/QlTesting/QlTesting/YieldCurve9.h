
// Author: Dimitri Reiswich

#include "YieldCurve6.h"

void testingYields4(){
    
	std::vector<boost::shared_ptr<RateHelper>> instruments=getRateHelperVector();

	Calendar calendar = TARGET();
	Date today(11,Sep,2009);
	Natural settlementDays = 2;
	Date settlement = calendar.advance(today,settlementDays,Days);

	std::cout << "Settlement Date:" << settlement << std::endl;
	
	DayCounter dc=Actual360();
	boost::shared_ptr<YieldTermStructure> yieldCurve;
  
	yieldCurve = boost::shared_ptr<YieldTermStructure>(new
				PiecewiseYieldCurve<ZeroYield,Linear>(settlement,instruments, dc));
	
	Date d1=settlement+1*Years,d2=d1+3*Months;

	std::cout << "Zero 3M: "	<< yieldCurve->zeroRate(settlement+3*Months,dc,Simple) << std::endl;
	std::cout << "Zero 6M: "	<< yieldCurve->zeroRate(settlement+6*Months,dc,Simple) << std::endl;
	std::cout << "Zero 9M: "	<< yieldCurve->zeroRate(settlement+9*Months,dc,Simple) << std::endl;
	std::cout << "12x15 Fwd: "	<< yieldCurve->forwardRate(d1,d2,dc,Simple)<< std::endl;
	std::cout << "15x18 Fwd: "	<< yieldCurve->forwardRate(d2,d2+3*Months,dc,Simple)<< std::endl;
	// Check swap rate
	Handle<YieldTermStructure> ycHandle(yieldCurve);
	// ISDA swap is vs 3 month libor, set this up
	boost::shared_ptr<IborIndex> libor3m(new USDLibor(Period(3,Months),ycHandle));
	// set up a 8y ISDA swap, just to have references to all properties
	boost::shared_ptr<SwapIndex> swap8yIndex(new UsdLiborSwapIsdaFixAm(Period(8,Years)));
	// construct a vanilla swap
	VanillaSwap swap =    MakeVanillaSwap(Period(8,Years),libor3m)
						  .withEffectiveDate(settlement)
						  .withFixedLegConvention(swap8yIndex->fixedLegConvention())
						  .withFixedLegTenor(swap8yIndex->fixedLegTenor());

 	std::cout << "8Y Swap:" << swap.fairRate() << std::endl;
}