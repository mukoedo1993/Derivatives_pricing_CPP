
// Author: Dimitri Reiswich
#include <boost/math/distributions.hpp>
#include <boost/function.hpp>


Real evInv(boost::math::extreme_value_distribution<> d, const Real& x){
		return quantile(d,x);	
}

void testingRandomNumbers3(){

	boost::math::extreme_value_distribution<> d(0.0,0.1);
	boost::function<Real (Real)> invEv=boost::bind(evInv,d,_1);

	// Mersenne Twister setup
	BigInteger seed=12324;
	MersenneTwisterUniformRng	unifMt(seed);
	// sequence setup
	RandomSequenceGenerator<MersenneTwisterUniformRng> unifMtSeq(10,unifMt);
	// 
	
	InverseCumulativeRsg<RandomSequenceGenerator<MersenneTwisterUniformRng>,
		boost::function<Real (Real)>> myEvInvMt(unifMtSeq,invEv);

	std::vector<Real> sample=myEvInvMt.nextSequence().value;
	BOOST_FOREACH(Real x, sample) std::cout << x << std::endl;
}