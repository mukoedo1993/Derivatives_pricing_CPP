
// Author: Dimitri Reiswich


void testingCoupons1(){

	Rate r=0.02;

	Real nominal=100000.0;
	Date accrualStartDate=Date::todaysDate();
	Date accrualEndDate=accrualStartDate+6*Months;
	Date paymentDate=accrualEndDate;
	DayCounter dc=SimpleDayCounter();
	InterestRate interestRate(r,dc,Simple,Annual);

	FixedRateCoupon coupon(nominal,paymentDate,interestRate,dc,
					accrualStartDate,accrualEndDate);

	Real accruedAmount=coupon.accruedAmount(accrualStartDate+2*Months);
	std::cout << "Accrued amount:" << accruedAmount << std::endl;
	std::cout << "Accrued end amount:" << coupon.amount() << std::endl;

}
