
// Author: Dimitri Reiswich

void testingCoupons2(){
	
	// set all conventions to be the one of the libor
	EURLibor1M libor; 
	DayCounter dc=libor.dayCounter(); 
	Calendar calendar=libor.fixingCalendar();
	BusinessDayConvention bdc=libor.businessDayConvention();
	// settlement is in 2 days
	Date startDate(16,Sep,2009);
	Natural settlementDays = 2;
	Date settlement = calendar.advance(startDate,settlementDays,Days);
	Settings::instance().evaluationDate() = settlement;
	// 4% on 100.0 USD	
	Real notional=100.0;
	Real r=0.04;
	// We want annual payments for 10 years
	Schedule couponSchedule=MakeSchedule(settlement,settlement+10*Years,
								Period(Annual),calendar,bdc)
							    .backwards();
	// Create the cash flow vectors, r is a Simple rate with daycounter dc
	std::vector<boost::shared_ptr<CashFlow>> cashFlowVec;
		cashFlowVec=FixedRateLeg(couponSchedule,dc)
					.withNotionals(notional)
					.withCouponRates(r);
	// Print out the cash flows
	boost::shared_ptr<CashFlow> tmpCf;
	
	BOOST_FOREACH(tmpCf,cashFlowVec) 
	std::cout << "D: " << tmpCf->date() << ", CF: " << tmpCf->amount() << std::endl;
}