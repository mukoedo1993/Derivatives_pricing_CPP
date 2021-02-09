
// Author: Dimitri Reiswich

void DateTesting3(){
	std::cout << "Today:" << Date::todaysDate() << std::endl;
	std::cout << "Min Date:" << Date::minDate() << std::endl;
	std::cout << "Max Date:" << Date::maxDate() << std::endl;
	std::cout << "Is Leap:" << Date::isLeap(2011) << std::endl;
	std::cout << "End of Month:" << Date::endOfMonth(Date(4,Aug,2009)) << std::endl;
	std::cout << "Is Month End:" << Date::isEndOfMonth(Date(29,Sep,2009)) << std::endl;
	std::cout << "Is Month End:" << Date::isEndOfMonth(Date(30,Sep,2009)) << std::endl;
	std::cout << "Next WD:" << Date::nextWeekday(Date(1,Sep,2009),Friday) << std::endl;
	std::cout << "n-th WD:" << Date::nthWeekday(3,Wed,Sep,2009)<< std::endl;
}
