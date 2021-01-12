
// Author: Dimitri Reiswich

void dayCounterTesting1(){

	DayCounter dc=Thirty360();
	Date d1(1,Oct,2009);
	Date d2=d1+2*Months;

std::cout << "Days Between d1/d2:" <<dc.dayCount(d1,d2) << std::endl;
std::cout << "Year Fraction d1/d2:" <<dc.yearFraction(d1,d2) << std::endl;
}