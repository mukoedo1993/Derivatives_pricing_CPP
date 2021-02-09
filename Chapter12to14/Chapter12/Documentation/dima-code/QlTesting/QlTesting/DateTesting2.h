
// Author: Dimitri Reiswich

void DateTesting2(){

	Date myDate(12,QuantLib::Aug,2009);
	
	std::cout << "Original Date:" << myDate << std::endl;
	std::cout << "Weekday:" << myDate.weekday() << std::endl;
	std::cout << "Day of Month:" << myDate.dayOfMonth() << std::endl;
	std::cout << "Day of Year:" << myDate.dayOfYear() << std::endl;
	std::cout << "Month:" << myDate.month() << std::endl;
		int month=myDate.month();
	std::cout << "Month via Integer:" << month << std::endl;
	std::cout << "Year:" << myDate.year() << std::endl;
		int serialNum=myDate.serialNumber();
	std::cout << "Serial Number:" << serialNum << std::endl;
}
