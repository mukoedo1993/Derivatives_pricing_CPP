
// Author: Dimitri Reiswich
      
		Schedule(const Date& effectiveDate,
                 const Date& terminationDate,
                 const Period& tenor,
                 const Calendar& calendar,
                 BusinessDayConvention convention,
                 BusinessDayConvention terminationDateConvention,
                 DateGeneration::Rule rule,
                 bool endOfMonth,
                 const Date& firstDate = Date(),
                 const Date& nextToLastDate = Date())