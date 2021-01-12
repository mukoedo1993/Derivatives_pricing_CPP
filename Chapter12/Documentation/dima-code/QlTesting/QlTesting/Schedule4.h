
// Author: Dimitri Reiswich


void testingSchedule4(){

	Date begin(30,September,2009), end(15,Jun,2012);
	Calendar myCal=Japan();

	BusinessDayConvention bdC=BusinessDayConvention(Following);
	Period myTenor(6,Months);

    Schedule myScheduleMade=MakeSchedule(begin,end,myTenor,myCal,bdC)
		.backwards()
		.endOfMonth(false)
		.withNextToLastDate(Date(24,Aug,2011));
	
	std::vector<Date> finalSched=myScheduleMade.dates();
	BOOST_FOREACH(Date d,finalSched) std::cout << d << std::endl;


}
