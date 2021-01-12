
// Author: Dimitri Reiswich

#include <boost/foreach.hpp>

void CalendarTesting2(){

	Calendar frankfCal=Germany(Germany::FrankfurtStockExchange);
	Date d1(24,Dec,2009), d2(30,Dec,2009),d3(31,Dec,2009);

	frankfCal.addHoliday(d2);
	frankfCal.removeHoliday(d3);
	
	std::cout << "Is Business Day:" << frankfCal.isBusinessDay(d2) << std::endl;
	std::cout << "Is Business Day:" << frankfCal.isBusinessDay(d3) << std::endl;

	std::vector<Date> holidayVec=frankfCal.holidayList(frankfCal,d1,d2,false);
	std::cout << "----------" << std::endl;
	BOOST_FOREACH(Date d,holidayVec) std::cout << d << std::endl;
}