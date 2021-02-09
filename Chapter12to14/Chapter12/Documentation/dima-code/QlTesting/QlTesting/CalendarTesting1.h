
// Author: Dimitri Reiswich

void CalendarTesting1(){

Calendar frankfCal=Germany(Germany::FrankfurtStockExchange);
Calendar saudiArabCal=SaudiArabia();
Date nyEve(31,Dec,2009);

std::cout << "Is BD:" << frankfCal.isBusinessDay(nyEve) << std::endl;
std::cout << "Is Holiday:" << frankfCal.isHoliday(nyEve) << std::endl;
std::cout << "Is Weekend:" << saudiArabCal.isWeekend(Saturday) << std::endl;
std::cout << "Is Last BD:" << frankfCal.isEndOfMonth(Date(30,Dec,2009)) << std::endl;
std::cout << "Last BD:" << frankfCal.endOfMonth(nyEve) << std::endl;

}