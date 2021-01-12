
// Author: Dimitri Reiswich

void CalendarTesting3(){

Calendar frankfCal=Germany(Germany::FrankfurtStockExchange);

	Date firstDate(31,Oct,2009);
	Date secondDate(1,Jan,2010);

std::cout <<"Date 2 Adv:" << frankfCal.adjust(secondDate,
	BusinessDayConvention(Preceding)) << std::endl;
std::cout <<"Date 2 Adv:" << frankfCal.adjust(secondDate,
	BusinessDayConvention(ModifiedPreceding)) << std::endl;

Period mat(2,Months);
std::cout << "Date 1 Month Adv:" << frankfCal.advance(firstDate,mat,
	BusinessDayConvention(Following),false) << std::endl;
std::cout << "Date 1 Month Adv:" << frankfCal.advance(firstDate,mat,
	BusinessDayConvention(ModifiedFollowing),false) << std::endl;

std::cout << "Business Days Between:" << frankfCal.businessDaysBetween(
	firstDate,secondDate,false,false) << std::endl;
}