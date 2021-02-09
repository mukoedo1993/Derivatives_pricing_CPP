
// Author: Dimitri Reiswich


boost::shared_ptr<YieldTermStructure> getZeroYieldCurve(){

	std::vector<Date> dates;
	std::vector<Rate> yields;

	Date today(16,Sep,2009);
	EURLibor1M libor; 
	DayCounter dc=libor.dayCounter(); 
	Calendar calendar=libor.fixingCalendar();
	Natural settlementDays = 2;
	Date settlement = calendar.advance(today,settlementDays,Days);
	
	dates.push_back(settlement); 
	dates.push_back(settlement+7*Days); 
	dates.push_back(settlement+30*Days); 
	dates.push_back(settlement+60*Days); 
	dates.push_back(settlement+90*Days);
	dates.push_back(settlement+180*Days); 
	dates.push_back(settlement+270*Days); 
	dates.push_back(settlement+360*Days); 
	dates.push_back(settlement+450*Days); 
	dates.push_back(settlement+540*Days); 
	dates.push_back(settlement+630*Days); 
	dates.push_back(settlement+720*Days); 
	dates.push_back(settlement+810*Days); 
	dates.push_back(settlement+900*Days); 
	dates.push_back(settlement+990*Days); 
	dates.push_back(settlement+1080*Days); 
	dates.push_back(settlement+1170*Days); 
	dates.push_back(settlement+1260*Days); 
	dates.push_back(settlement+1350*Days); 
	dates.push_back(settlement+1440*Days); 
	dates.push_back(settlement+1530*Days); 
	dates.push_back(settlement+1620*Days); 
	dates.push_back(settlement+1710*Days); 
	dates.push_back(settlement+1800*Days); 
	dates.push_back(settlement+1890*Days); 
	dates.push_back(settlement+1980*Days); 
	dates.push_back(settlement+2070*Days); 
	dates.push_back(settlement+2160*Days); 
	dates.push_back(settlement+2250*Days); 
	dates.push_back(settlement+2340*Days); 
	dates.push_back(settlement+2430*Days);
	dates.push_back(settlement+2520*Days); 
	dates.push_back(settlement+2610*Days); 
	dates.push_back(settlement+2700*Days); 
	dates.push_back(settlement+2790*Days); 
	dates.push_back(settlement+2880*Days); 
	dates.push_back(settlement+3060*Days); 
	dates.push_back(settlement+3240*Days); 
	dates.push_back(settlement+3420*Days); 
	dates.push_back(settlement+3600*Days); 
	dates.push_back(settlement+4320*Days); 
	dates.push_back(settlement+5400*Days); 
	dates.push_back(settlement+7200*Days); 
	dates.push_back(settlement+9000*Days); 
	dates.push_back(settlement+10800*Days); 

	yields.push_back(0.0); // todays discount yield
	yields.push_back(0.2301);
	yields.push_back(0.2755);
	yields.push_back(0.2625);
	yields.push_back(0.2811);
	yields.push_back(0.3658);
	yields.push_back(0.4645);
	yields.push_back(0.6024);
	yields.push_back(0.7566);
	yields.push_back(0.9203);
	yields.push_back(1.1001);
	yields.push_back(1.2708);
	yields.push_back(1.4404);
	yields.push_back(1.608);
	yields.push_back(1.767);
	yields.push_back(1.9183);
	yields.push_back(2.0576);
	yields.push_back(2.1861);
	yields.push_back(2.3089);
	yields.push_back(2.4238);
	yields.push_back(2.5304);
	yields.push_back(2.6293);
	yields.push_back(2.7241);
	yields.push_back(2.8126);
	yields.push_back(2.8944);
	yields.push_back(2.9702);
	yields.push_back(3.0429);
	yields.push_back(3.1114);
	yields.push_back(3.1752);
	yields.push_back(3.2367);
	yields.push_back(3.2949);
	yields.push_back(3.3474);
	yields.push_back(3.3964);
	yields.push_back(3.4422);
	yields.push_back(3.4856);
	yields.push_back(3.5269);
	yields.push_back(3.6045);
	yields.push_back(3.6737);
	yields.push_back(3.7323);
	yields.push_back(3.7861);
	yields.push_back(3.978);
	yields.push_back(4.1529);
	yields.push_back(4.2651);
	yields.push_back(4.3063);
	yields.push_back(4.3299);

	BOOST_FOREACH(Rate& r,yields) r/=100.0;

	boost::shared_ptr<YieldTermStructure> curve(new InterpolatedZeroCurve<Linear>(dates,yields,dc));
	return curve;
}