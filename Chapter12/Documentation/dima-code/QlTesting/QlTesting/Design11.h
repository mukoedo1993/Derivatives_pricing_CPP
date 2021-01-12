
// Author: Dimitri Reiswich
        
		SABRInterpolation(const I1& xBegin,  // x = strikes
                          const I1& xEnd,
                          const I2& yBegin,  // y = volatilities
                          Time t,            // option expiry
                          const Real& forward,
                          Real alpha,
                          Real beta,
                          Real nu,
                          Real rho,
                          bool alphaIsFixed,
                          bool betaIsFixed,
                          bool nuIsFixed,
                          bool rhoIsFixed,
                          bool vegaWeighted = false,
                          const boost::shared_ptr<EndCriteria>& endCriteria
                                  = boost::shared_ptr<EndCriteria>(),
                          const boost::shared_ptr<OptimizationMethod>& optMethod
                                  = boost::shared_ptr<OptimizationMethod>())