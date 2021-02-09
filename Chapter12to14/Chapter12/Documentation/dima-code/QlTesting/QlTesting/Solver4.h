
// Author: Dimitri Reiswich
#include <boost/math/distributions.hpp>

class BlackScholesClass{
	private:
	Real spot_,strike_,price_,logFwd_;
	Real dp_,domDf_,forDf_,fwd_,sqrtTau_;
	Rate rd_,rf_;
	Integer phi_;
	Time tau_;
	boost::math::normal_distribution<> d_;
	public:
		BlackScholesClass(const Real& spot, 
						 const Real& strike,
						 const Rate& rd,
						 const Rate& rf,
						 const Time& tau,
						 const Integer& phi,
						 const Real& price)
						 :spot_(spot), strike_(strike), rd_(rd),rf_(rf),phi_(phi),
						 tau_(tau),price_(price), sqrtTau_(std::sqrt(tau)),
						 d_(boost::math::normal_distribution<>(0.0,1.0)){

							domDf_=std::exp(-rd_*tau_);
							forDf_=std::exp(-rf_*tau_);
							fwd_=spot_*forDf_/domDf_;
							logFwd_=std::log(fwd_/strike_);
						
		}

		Real operator()(const Volatility& x) const{
				return impliedVolProblem(spot_, strike_,rd_,rf_,x,tau_,phi_,price_);
		}
		Real derivative(const Volatility& x)const{
			// vega
			Real stdDev=x*sqrtTau_;
			Real dp=(logFwd_+0.5*stdDev*stdDev)/stdDev;
			return spot_*forDf_*pdf(d_,dp)*sqrtTau_;
		}	
};

