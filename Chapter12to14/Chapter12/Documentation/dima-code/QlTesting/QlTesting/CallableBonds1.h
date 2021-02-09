
// Author: Dimitri Reiswich
   CallableFixedRateBond(Natural settlementDays,
                              Real faceAmount,
                              const Schedule& schedule,
                              const std::vector<Rate>& coupons,
                              const DayCounter& accrualDayCounter,
                              BusinessDayConvention paymentConvention = Following,
                              Real redemption = 100.0,
                              const Date& issueDate = Date(),
                              const CallabilitySchedule& putCallSchedule);