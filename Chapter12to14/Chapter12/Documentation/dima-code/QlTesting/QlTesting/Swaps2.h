
// Author: Dimitri Reiswich
void testingSwaps2(){

	boost::shared_ptr<YieldTermStructure> curvePtr=getZeroYieldCurve();
	Handle<YieldTermStructure> curve(curvePtr);

	VanillaSwap::Type type(VanillaSwap::Receiver);

	boost::shared_ptr<IborIndex> libor6m(new USDLibor(Period(Semiannual),curve));
	
	Calendar cal=TARGET();

	BusinessDayConvention fixedBdc=ModifiedFollowing;
	BusinessDayConvention floatBdc=libor6m-> businessDayConvention();

	DayCounter fixedDc=Thirty360(Thirty360::BondBasis);
	DayCounter floatDc=libor6m->dayCounter();

	Date fixing=curvePtr->referenceDate();
	Settings::instance().evaluationDate()=cal.advance(fixing,-2,Days);

	Date mat=fixing+3*Years;

	Schedule fixedSched=MakeSchedule(fixing,mat,Period(Annual),cal,fixedBdc)
						.backwards()
						.endOfMonth(false);
	
	Schedule floatSched=MakeSchedule(fixing,mat,Period(Semiannual),cal,floatBdc)
						.backwards()
						.endOfMonth(false);

	Real nominal=1000000;
	Spread spread=0.0;
	Rate fixedRate=0.04;

	VanillaSwap swap(type,nominal, fixedSched, fixedRate,
                     fixedDc, floatSched,libor6m,spread,floatDc);

	swap.setPricingEngine(boost::shared_ptr<PricingEngine>(
									new DiscountingSwapEngine(curve)));

	Real fairRate=swap.fairRate();
	Real fairSpread=swap.fairSpread();

	std::cout << "Fair Rate:" << fairRate << std::endl;
	std::cout << "Fair Spread:" << fairSpread << std::endl;
	std::cout << "NPV Unfair:" << swap.NPV() << std::endl;
	
	VanillaSwap swapFair=MakeVanillaSwap(Period(3,Years),libor6m, fairRate)
						 .withType(type)
						 .withEffectiveDate(fixing)
  						 .withTerminationDate(mat)
						 .withRule(DateGeneration::Backward)
						 .withNominal(nominal)
						 .withFixedLegTenor(Period(Annual))
						 .withFloatingLegTenor(Period(Semiannual))
						 .withFixedLegCalendar(cal)
						 .withFloatingLegCalendar(cal)
						 .withFixedLegConvention(fixedBdc)
                         .withFloatingLegConvention(floatBdc)
						 .withFixedLegDayCount(fixedDc)
						 .withFloatingLegDayCount(floatDc)
						 .withDiscountingTermStructure(curve);

	std:: cout << "NPV fair:" << swapFair.NPV() << std::endl;
	std::cout << "----------------------------" << std::endl;
	Real bps=0.0001;


	VanillaSwap swapBps(type,nominal, fixedSched, fairRate+bps,
                     fixedDc, floatSched,libor6m,spread,floatDc);

	swapBps.setPricingEngine(boost::shared_ptr<PricingEngine>(
									new DiscountingSwapEngine(curve)));


	Real swapBpsNpvFix=swapBps.fixedLegNPV();
	Real swapFairNpvFix=swapFair.fixedLegNPV();

	Real npvDiffFix=swapBpsNpvFix-swapFairNpvFix;
	Real fixBps=swapFair.fixedLegBPS();

	std::cout << "NPV diff fix:: "	<< npvDiffFix << std::endl;
	std::cout << "Fix Bps: "		<< fixBps	<< std::endl;
}