  BatesProcess(const Handle<YieldTermStructure>& riskFreeRate,
                     const Handle<YieldTermStructure>& dividendYield,
                     const Handle<Quote>& s0,
                     Real v0, Real kappa,
                     Real theta, Real sigma, Real rho,
                     Real lambda, Real nu, Real delta,
                     HestonProcess::Discretization d
                     = HestonProcess::FullTruncation)