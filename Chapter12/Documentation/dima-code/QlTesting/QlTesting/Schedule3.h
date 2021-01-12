
// Author: Dimitri Reiswich

void testingSchedule3(){

	Date begin(30,September,2009), end(15,Jun,2012);
	Calendar myCal=Japan();

	BusinessDayConvention bdC=BusinessDayConvention(Following);

	Period myTenor(6,Months);
	DateGeneration::Rule myRule=DateGeneration::Forward;

	Schedule mySched(begin,end,myTenor,myCal,bdC,bdC,myRule,true);

	Date myDate(3,Aug,2010);
	std::cout << "Date:" << myDate << std::endl;
	std::cout << "Next Date:" << mySched.nextDate(myDate) << std::endl;
	std::cout << "Prev Date:" << mySched.previousDate(myDate) << std::endl;

}