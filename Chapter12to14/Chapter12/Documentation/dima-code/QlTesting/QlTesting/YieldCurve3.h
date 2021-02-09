
// Author: Dimitri Reiswich
  InterpolatedDiscountCurve(
            const std::vector<Date>& dates,
            const std::vector<DiscountFactor>& dfs,
            const DayCounter& dayCounter,
            const Calendar& cal = Calendar(),
            const std::vector<Handle<Quote> >& jumps = std::vector<Handle<Quote> >(),
            const std::vector<Date>& jumpDates = std::vector<Date>(),
            const Interpolator& interpolator = Interpolator());