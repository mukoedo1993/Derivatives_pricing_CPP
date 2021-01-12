
// Author: Dimitri Reiswich
#include <boost/math/distributions.hpp>

Real   blackScholesPrice(const Real& spot, 
						 const Real& strike,
						 const Rate& rd,
						 const Rate& rf,
						 const Volatility& vol,
						 const Time& tau,
						 const Integer& phi){

	boost::math::normal_distribution<> d(0.0,1.0);
	Real dp,dm, fwd, stdDev, res, domDf, forDf;

	domDf=std::exp(-rd*tau); forDf=std::exp(-rf*tau);
	fwd=spot*forDf/domDf;
	stdDev=vol*std::sqrt(tau);

	dp=(std::log(fwd/strike)+0.5*stdDev*stdDev)/stdDev;
	dm=(std::log(fwd/strike)-0.5*stdDev*stdDev)/stdDev;

	res=phi*domDf*(fwd*cdf(d,phi*dp)-strike*cdf(d,phi*dm));
	return res;
}

Real   impliedVolProblem(const Real& spot,
						 const Rate& strike,
						 const Rate& rd,
						 const Rate& rf,
						 const Volatility& vol,
						 const Time& tau,
						 const Integer& phi,
						 const Real& price){

		return blackScholesPrice(spot,strike, rd,rf,vol,tau, phi) - price;
}

