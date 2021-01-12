
// Author: Dimitri Reiswich

void testingBonds2(){

	boost::shared_ptr<YieldTermStructure> curvePtr=getBondYieldCurve();
	Handle<YieldTermStructure> curve(curvePtr);

    Natural settlementDays = 1;
	Calendar cal=UnitedStates(UnitedStates::GovernmentBond);
    Real faceAmount = 100.0; 
    Date today(14,Sep,2009);
	Settings::instance().evaluationDate() = today;
	Date settlementDate=cal.advance(today,settlementDays,Days);
	Date maturityDate(15,Nov,2016);
	DayCounter dc=ActualActual(ActualActual::Bond);
	Date issueDate(15,Nov,2006);

	BusinessDayConvention bdc=Unadjusted;
	
	Schedule bondSchedule=MakeSchedule(issueDate,maturityDate,
		Period(Semiannual), cal, bdc)
		.backwards();

	std::vector<Date> couponDates=bondSchedule.dates();

    FixedRateBond fixedRateBond(
                 settlementDays,
                 faceAmount,
                 bondSchedule,
                 std::vector<Rate>(1, 0.04625),
                 dc,bdc,faceAmount,issueDate);

	 boost::shared_ptr<PricingEngine> bondEngine(new DiscountingBondEngine(curve));
     fixedRateBond.setPricingEngine(bondEngine);

	 std::cout << "Clean Price:"<< fixedRateBond.cleanPrice() << std::endl;
}