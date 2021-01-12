
// Author: Dimitri Reiswich

#include <boost/foreach.hpp>

void testingSchedule1(){

	Date begin(30,September,2009), end(15,Jun,2012);
	Calendar myCal=Japan();

	BusinessDayConvention bdC=BusinessDayConvention(Following);

	Period myTenor(6,Months);

	DateGeneration::Rule myRule=DateGeneration::Forward;

	Schedule mySched(begin,end,myTenor,myCal,bdC,bdC,myRule,true);

	std::vector<Date> finalSched=mySched.dates();

	BOOST_FOREACH(Date d,finalSched) std::cout << d << std::endl;


}