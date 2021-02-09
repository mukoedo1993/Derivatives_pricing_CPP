
// Author: Dimitri Reiswich
        PiecewiseYieldCurve(
               const Date& referenceDate,
               const std::vector<boost::shared_ptr<typename Traits::helper> >& instruments,
               const DayCounter& dayCounter,
               const std::vector<Handle<Quote> >& jumps = std::vector<Handle<Quote> >(),
               const std::vector<Date>& jumpDates = std::vector<Date>(),
               Real accuracy = 1.0e-12,
               const Interpolator& i = Interpolator(),
               const Bootstrap<this_curve>& bootstrap = Bootstrap<this_curve>())