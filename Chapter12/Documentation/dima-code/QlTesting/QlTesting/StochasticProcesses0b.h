        HestonProcess(const Handle<YieldTermStructure>& riskFreeRate,
                      const Handle<YieldTermStructure>& dividendYield,
                      const Handle<Quote>& s0,
                      Real v0, Real kappa,
                      Real theta, Real sigma, Real rho,
                      Discretization d = FullTruncation);