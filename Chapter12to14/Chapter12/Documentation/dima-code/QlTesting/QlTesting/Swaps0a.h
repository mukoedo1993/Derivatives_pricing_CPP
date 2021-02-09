
// Author: Dimitri Reiswich
   VanillaSwap(Type type,
                    Real nominal,
                    const Schedule& fixedSchedule,
                    Rate fixedRate,
                    const DayCounter& fixedDayCount,
                    const Schedule& floatSchedule,
                    const boost::shared_ptr<IborIndex>& iborIndex,
                    Spread spread,
                    const DayCounter& floatingDayCount,
                    BusinessDayConvention paymentConvention = Following)