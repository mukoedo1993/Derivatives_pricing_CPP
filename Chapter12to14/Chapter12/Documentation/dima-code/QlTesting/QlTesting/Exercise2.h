
// Author: Dimitri Reiswich



void exercise2(){

	Calendar calJap=Japan();
	Calendar calGer=Germany();
	Calendar calSwitz=Switzerland();
	Calendar calUk=UnitedKingdom();
	Calendar calUs=UnitedStates();


	std::vector<Date> holidayVec;
	
	Size numHolidays=0;

	Date d1(1,Jan,2009),d2(31,Dec,2009);

	holidayVec=Calendar::holidayList(calJap,d1,d2);
	numHolidays=holidayVec.size();
	std::cout << "Num Holidays Japan:" << numHolidays << std::endl;
	//
	holidayVec=Calendar::holidayList(calGer,d1,d2);
	numHolidays=holidayVec.size();
	std::cout << "Num Holidays Germany:" << numHolidays << std::endl;
	//
	holidayVec=Calendar::holidayList(calSwitz,d1,d2);
	numHolidays=holidayVec.size();
	std::cout << "Num Holidays Switzerland:" << numHolidays << std::endl;
	//
	holidayVec=Calendar::holidayList(calUk,d1,d2);;
	numHolidays=holidayVec.size();
	std::cout << "Num Holidays UK:" << numHolidays << std::endl;
	//
	holidayVec=Calendar::holidayList(calUs,d1,d2);
	numHolidays=holidayVec.size();
	std::cout << "Num Holidays USA:" << numHolidays << std::endl;

	holidayVec=Calendar::holidayList(calJap,d1,d2);

	 BigInteger maxDays=0;
	
	for(Size i=0;i<(holidayVec.size()-1);i++){
		maxDays=std::max(maxDays,calJap.businessDaysBetween(holidayVec[i],holidayVec[i+1]));
	}

	std::cout << "Max Working Days:" << maxDays << std::endl;

}
