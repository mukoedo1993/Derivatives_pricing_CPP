
// Author: Dimitri Reiswich
void testingBonds3(){
	boost::shared_ptr<YieldTermStructure> curvePtr=getBondYieldCurve();
	Handle<YieldTermStructure> curve(curvePtr);

    Natural settlementDays = 1;
	Calendar cal=UnitedStates(UnitedStates::GovernmentBond);
    Real faceAmount = 100.0; 
    Date today(14,Sep,2009);
	Settings::instance().evaluationDate() = today;
	Date settlementDate=cal.advance(today,settlementDays,Days);
	Date maturityDate(15,Nov,2017);
	DayCounter dc=ActualActual(ActualActual::Bond);
	Date issueDate(15,Nov,2007);

	BusinessDayConvention bdc=Unadjusted;
	
	Schedule bondSchedule=MakeSchedule(issueDate,maturityDate,
		Period(Semiannual), cal, bdc)
		.backwards();

	std::vector<Date> couponDates=bondSchedule.dates();
	
	FixedRateBond fixedRateBond(
                 settlementDays,
                 faceAmount,
                 bondSchedule,
                 std::vector<Rate>(1, 0.0425),
                 dc,bdc,faceAmount,issueDate);

	 boost::shared_ptr<PricingEngine> bondEngine(new DiscountingBondEngine(curve));
     fixedRateBond.setPricingEngine(bondEngine);

	 std::cout << "Clean Price:"<< fixedRateBond.cleanPrice() << std::endl;
	 std::cout << "Dirty Price:"<< fixedRateBond.dirtyPrice() << std::endl;
		Real accruedInterest= fixedRateBond.dirtyPrice()- fixedRateBond.cleanPrice();
	 std::cout << "Accrued Interest:" << accruedInterest << std::endl;
		Rate yield=fixedRateBond.yield(dc,Compounded,Semiannual);
		InterestRate yieldRate=InterestRate(yield,dc,Compounded,Semiannual);
	 std::cout << "Bond Yield:"<< yield << std::endl;
	 Real durationMod=CashFlows::duration(fixedRateBond.cashflows(),yieldRate, Duration::Modified);
	 std::cout << "Duration:" << - durationMod << std::endl;
	 std::cout << "BPV:" << CashFlows::basisPointValue(fixedRateBond.cashflows(),yieldRate)*100 << std::endl;
		Real convexity=CashFlows::convexity(fixedRateBond.cashflows(),yieldRate);
	 std::cout << "Convexity:" << convexity << std::endl;
		 Real dy=0.01; 
		 Real p=CashFlows::npv(fixedRateBond.cashflows(),yieldRate);
		 InterestRate yieldRateDyP=InterestRate(yield+dy,dc,Compounded,Semiannual);
		 Real pPlus=CashFlows::npv(fixedRateBond.cashflows(),yieldRateDyP);
		 Real manualChange=(pPlus-p)/p;
	std::cout << "---------- Manual % Change Calculations ---------" << std::endl;
	std::cout << "Manual % Change:" << manualChange*100.0 << std::endl;
		Real durationChange=-CashFlows::duration(fixedRateBond.cashflows(),yieldRate)*dy*100.0;
	std::cout << "Duration Change:" << durationChange << std::endl;
		Real convexityChange=0.5*convexity*dy*dy*100.0;
	std::cout << "Conv Change:" << convexityChange << std::endl;
		Real durConvChange=durationChange+convexityChange;
	std::cout << "Duration+Conv Change:" << durConvChange << std::endl;
	std::cout << "---------- Manual Abs Change Calculations ---------" << std::endl;
		dy=0.0001;
		InterestRate yieldRate1=InterestRate(yield+dy,dc,Compounded,Semiannual);
		pPlus=CashFlows::npv(fixedRateBond.cashflows(),yieldRate1);
		manualChange=pPlus-p;
	std::cout << "Manual abs Change:" << manualChange << std::endl;
	std::cout << "BPV:" << CashFlows::basisPointValue(fixedRateBond.cashflows(),yieldRate) << std::endl;
}