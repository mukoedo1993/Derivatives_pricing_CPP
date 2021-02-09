
// Author: Dimitri Reiswich
#include <boost/assign.hpp>

boost::shared_ptr<YieldTermStructure> getBondYieldCurve(){

	std::vector<boost::shared_ptr<SimpleQuote>> quoteVec;
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(101.53125)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(107.8203125)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(109.09375)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(101.8828125)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(110.0625)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(110.5)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(107.304688)));
	quoteVec.push_back(boost::shared_ptr<SimpleQuote>(new SimpleQuote(144.34375)));

	std::vector<Real> couponVec;
	couponVec+=0.0175,0.04,0.0425,0.1175,0.045,0.04625,0.0425,0.09;

	std::vector<Date> matVec;
	matVec.push_back(Date(15,Nov,2011));
	matVec.push_back(Date(15,Nov,2012));
	matVec.push_back(Date(15,Nov,2013));
	matVec.push_back(Date(15,Nov,2014));
	matVec.push_back(Date(15,Nov,2015));
	matVec.push_back(Date(15,Nov,2016));
	matVec.push_back(Date(15,Nov,2017));
	matVec.push_back(Date(15,Nov,2018));

	std::vector<Date> issueVec;
	issueVec.push_back(Date(17,Nov,2008));
	issueVec.push_back(Date(15,Nov,2002));
	issueVec.push_back(Date(17,Nov,2003));
	issueVec.push_back(Date(15,Nov,1984));
	issueVec.push_back(Date(15,Nov,2005));
	issueVec.push_back(Date(15,Nov,2006));
	issueVec.push_back(Date(15,Nov,2007));
	issueVec.push_back(Date(22,Nov,1988));

	BusinessDayConvention bdc=Unadjusted;
	Natural settlementDays = 1;
	Calendar cal=UnitedStates(UnitedStates::GovernmentBond);
    Real faceAmount = 100;
	Date today(14,Sep,2009);
    Settings::instance().evaluationDate() = today;
	Date settlementDate=cal.advance(today,settlementDays,Days);

    std::vector<boost::shared_ptr<RateHelper>> bondHelpers;

	   for (Size i=0; i<matVec.size(); i++) {

				Schedule schedule(issueVec[i], 
					matVec[i], 
					Period(Semiannual), 
					UnitedStates(UnitedStates::GovernmentBond),
                    bdc, bdc, 
					DateGeneration::Backward, 
					false);

  					Handle<Quote> tmpHandle(quoteVec[i]);
            
				boost::shared_ptr<RateHelper> bondHelper(new FixedRateBondHelper(
					tmpHandle,
                    settlementDays,
                    100.0,
                    schedule,
                    std::vector<Rate>(1,couponVec[i]),
                    ActualActual(ActualActual::Bond),
                    bdc,
                    100.0,
                    issueVec[i]));

            bondHelpers.push_back(bondHelper);
        }

	boost::shared_ptr<YieldTermStructure> curve(
                 new PiecewiseYieldCurve<ZeroYield,Linear>(settlementDate,bondHelpers,ActualActual(ActualActual::Bond)));
 
	return curve;
}