
// Author: Dimitri Reiswich
void testingBonds1(){

	boost::shared_ptr<YieldTermStructure> curvePtr=getZeroYieldCurve();
	Handle<YieldTermStructure> curve(curvePtr);

    Natural settlementDays = 1;
	Calendar cal=UnitedStates();
    Real faceAmount = 100.0;
	Date refDate=curvePtr->referenceDate();
	Settings::instance().evaluationDate() = refDate;
	Date settlement=cal.advance(refDate,settlementDays,Days);
	Date maturity= settlement+10*Years;

	// Zero coupon bond
	ZeroCouponBond zeroCouponBond(
                 settlementDays,
                 UnitedStates(UnitedStates::GovernmentBond),
                 faceAmount,
                 maturity);
	// Pricing engine
	boost::shared_ptr<PricingEngine> bondEngine(
                 new DiscountingBondEngine(curve));

    zeroCouponBond.setPricingEngine(bondEngine);

	std::cout << "Ref Date Curve:" << refDate << std::endl;
	std::cout << "Settlement Date:" << zeroCouponBond.settlementDate() << std::endl;
	std::cout << "Zero Bond Npv:" << zeroCouponBond.NPV() << std::endl;
	std::cout << "Zero Bond Settlement:" << zeroCouponBond.settlementValue() << std::endl;
}