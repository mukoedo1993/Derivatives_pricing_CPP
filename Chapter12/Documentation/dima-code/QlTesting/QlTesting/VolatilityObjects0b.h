
// Author: Dimitri Reiswich
        BlackVarianceSurface(const Date& referenceDate,
                             const Calendar& cal,
                             const std::vector<Date>& dates,
                             const std::vector<Real>& strikes,
                             const Matrix& blackVolMatrix,
                             const DayCounter& dayCounter,
                             Extrapolation lowerExtrapolation =
                                InterpolatorDefaultExtrapolation,
                             Extrapolation upperExtrapolation =
                                InterpolatorDefaultExtrapolation);
