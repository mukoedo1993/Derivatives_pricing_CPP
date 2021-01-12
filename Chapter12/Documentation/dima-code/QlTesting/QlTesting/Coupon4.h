
// Author: Dimitri Reiswich
void testingCoupons3(){
	// retrieve a yield curve
	boost::shared_ptr<YieldTermStructure> curve=getZeroYieldCurve();
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
	Real notional=100.0, r=0.04;
	// We want annual payments for 10 years
	Schedule couponSchedule=MakeSchedule(settlement,settlement+10*Years,
								Period(Annual),calendar,bdc)
							    .backwards();
	// Create the cash flow vectors, r is a Simple rate with daycounter dc
	std::vector<boost::shared_ptr<CashFlow>> cashFlowVec,cashFlowVecBp;
	InterestRate rRate(r,dc,Simple,Annual);
	// Rete bumped by 1 basis point
	InterestRate rRateBp(r+0.0001,dc,Simple,Annual);
	cashFlowVec=FixedRateLeg(couponSchedule,dc)
				.withNotionals(notional)
				.withCouponRates(rRate);
	// cash flow vec with bumped rate
	cashFlowVecBp=FixedRateLeg(couponSchedule,dc)
				.withNotionals(notional)
				.withCouponRates(rRateBp);

	Real npv=CashFlows::npv(cashFlowVec,*curve);
	// npv of bumped cash flows
	Real npvBp=CashFlows::npv(cashFlowVecBp,*curve);
	// atm value: should be the initial rate
	Real atm=CashFlows::atmRate(cashFlowVec,*curve);
	Real bps=CashFlows::bps(cashFlowVec,*curve);
	Rate irr=CashFlows::irr(cashFlowVec,npv,dc,Simple,Annual);
	InterestRate irrRate(irr,dc,Simple,Annual);
	Real dur=CashFlows::duration(cashFlowVec,irrRate);
	Real conv=CashFlows::convexity(cashFlowVec,irrRate);
	Real bpv=CashFlows::basisPointValue(cashFlowVec,irrRate,settlement);
	// bumped irr
	InterestRate irrRateBp(irr+0.0001,dc,Simple,Annual);
	// bumped npv of 
	Real npvBpv=CashFlows::npv(cashFlowVec,irrRateBp);
	std::cout << "NPV:" << npv << std::endl;
	std::cout << "BPS True:" << npvBp-npv << std::endl;
	std::cout << "BPS:" << bps << std::endl;
	std::cout << "ATM:" << atm << std::endl;
	std::cout << "IRR:" << irr << std::endl;
	std::cout << "DUR:" << dur << std::endl;
	std::cout << "CONV:" <<conv<< std::endl;
	std::cout << "BPV True:" << (npvBpv-npv) << std::endl;
	std::cout << "BPV 2. Order:" << bpv << std::endl;
}