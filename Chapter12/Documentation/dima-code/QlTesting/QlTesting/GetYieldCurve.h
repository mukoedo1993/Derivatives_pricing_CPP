
// Author: Dimitri Reiswich

boost::shared_ptr<YieldTermStructure> getYieldCurve(){

std::vector<boost::shared_ptr<RateHelper>> instruments=getRateHelperVector();

	Calendar calendar = TARGET();
	Date today(11,Sep,2009);
	Natural settlementDays = 2;
	Date settlement = calendar.advance(today,settlementDays,Days);
	
	DayCounter dc=Actual360();
	boost::shared_ptr<YieldTermStructure> yieldCurve;
  
	yieldCurve = boost::shared_ptr<YieldTermStructure>(new
				PiecewiseYieldCurve<ZeroYield,Linear>(settlement,instruments, dc));

	return yieldCurve;
}