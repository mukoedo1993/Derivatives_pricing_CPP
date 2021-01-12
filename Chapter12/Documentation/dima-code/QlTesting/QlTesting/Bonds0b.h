
// Author: Dimitri Reiswich
  FixedRateBondHelper(const Handle<Quote>& cleanPrice,
                            Natural settlementDays,
                            Real faceAmount,
                            const Schedule& schedule,
                            const std::vector<Rate>& coupons,
                            const DayCounter& dayCounter,
                            BusinessDayConvention paymentConv = Following,
                            Real redemption = 100.0,
                            const Date& issueDate = Date());