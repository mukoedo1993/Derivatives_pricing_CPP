
// Author: Dimitri Reiswich
			InterpolatedSmileSection(
                           Time expiryTime,
                           const std::vector<Rate>& strikes,
                           const std::vector<Handle<Quote> >& stdDevHandles,
                           const Handle<Quote>& atmLevel,
                           const Interpolator& interpolator = Interpolator(),
                           const DayCounter& dc = Actual365Fixed());

		       InterpolatedSmileSection(
                           const Date& d,
                           const std::vector<Rate>& strikes,
                           const std::vector<Handle<Quote> >& stdDevHandles,
                           const Handle<Quote>& atmLevel,
                           const DayCounter& dc = Actual365Fixed(),
                           const Interpolator& interpolator = Interpolator(),
                           const Date& referenceDate = Date());
