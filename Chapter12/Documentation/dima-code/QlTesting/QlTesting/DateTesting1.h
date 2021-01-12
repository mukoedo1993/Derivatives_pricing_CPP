
// Author: Dimitri Reiswich

void DateTesting1(){

	Date myDate(12,Aug,2009);
		std::cout << myDate << std::endl;
	myDate++;
		std::cout << myDate << std::endl;
	myDate+=12*Days;
		std::cout << myDate << std::endl;
	myDate-=2*Months;
		std::cout << myDate << std::endl;
	myDate--;
		std::cout << myDate << std::endl;
    
		
	Period myP(10, Weeks);
	myDate+=myP;
		std::cout << myDate << std::endl;
}
