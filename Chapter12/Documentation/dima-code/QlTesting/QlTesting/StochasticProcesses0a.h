    GeneralizedBlackScholesProcess(
            const Handle<Quote>& x0,
            const Handle<YieldTermStructure>& dividendTS,
            const Handle<YieldTermStructure>& riskFreeTS,
            const Handle<BlackVolTermStructure>& blackVolTS,
            const boost::shared_ptr<discretization>& d =
                  boost::shared_ptr<discretization>(new EulerDiscretization));