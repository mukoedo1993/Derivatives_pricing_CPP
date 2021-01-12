
// Author: Dimitri Reiswich


void testingIndexes1(){

EURLibor1M index;

	std::cout << "Name:" << index.familyName() << std::endl;
	std::cout << "BDC:"<< index.businessDayConvention() << std::endl;
	std::cout << "End of Month rule?:"<< index.endOfMonth() << std::endl;
	std::cout << "Tenor:" << index.tenor() << std::endl;
	std::cout << "Calendar:" << index.fixingCalendar() << std::endl;
	std::cout << "Day Counter:" << index.dayCounter() << std::endl;
	std::cout << "Currency:" << index.currency() << std::endl;

}