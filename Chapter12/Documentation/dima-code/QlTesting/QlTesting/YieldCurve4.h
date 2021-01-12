
// Author: Dimitri Reiswich
void testingYields2(){
	std::vector<Date> dates;
	std::vector<DiscountFactor> dfs;

	Calendar cal= TARGET();
	Date today(11,Sep,2009);
	EURLibor1M libor; 
	DayCounter dc=libor.dayCounter(); 

	Natural settlementDays = 2;
	Date settlement = cal.advance(today,settlementDays,Days);

	dates.push_back(settlement); dates.push_back(settlement+1*Days);
	dates.push_back(settlement+1*Weeks);dates.push_back(settlement+1*Months);
	dates.push_back(settlement+2*Months);dates.push_back(settlement+3*Months);
	dates.push_back(settlement+6*Months);dates.push_back(settlement+9*Months);
	dates.push_back(settlement+1*Years);dates.push_back(settlement+1*Years+3*Months);
	dates.push_back(settlement+1*Years+6*Months); dates.push_back(settlement+1*Years+9*Months);
	dates.push_back(settlement+2*Years);

	dfs.push_back(1.0);	dfs.push_back(0.9999656);
	dfs.push_back(0.9999072); dfs.push_back(0.9996074);
	dfs.push_back(0.9990040); dfs.push_back(0.9981237);
	dfs.push_back(0.9951358); dfs.push_back(0.9929456);
	dfs.push_back(0.9899849); dfs.push_back(0.9861596); // 
	dfs.push_back(0.9815178); dfs.push_back(0.9752363);
	dfs.push_back(0.9680804);

	Date tmpDate1=settlement+1*Years+3*Months;
	InterpolatedDiscountCurve<LogLinear> curve(dates,dfs,dc,cal);
	std::cout << "Zero Rate: " << curve.zeroRate(tmpDate1, dc, Simple, Annual) << std::endl;
	std::cout << "Discount: " << curve.discount(tmpDate1) << std::endl;
	Date tmpDate2=tmpDate1+3*Months;
	std::cout << "1Y3M-1Y6M Fwd Rate: " << curve.forwardRate(tmpDate1,tmpDate2,dc,Continuous) << std::endl;
}