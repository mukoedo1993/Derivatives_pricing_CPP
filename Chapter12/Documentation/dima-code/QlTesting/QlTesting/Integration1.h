
// Author: Dimitri Reiswich

#include <boost/function.hpp>
#include <boost/math/distributions.hpp>

Real normalCdf(const Real& x){
		boost::math::normal_distribution<> d;
		return cdf(d,x);
}
Real normalPdf(const Real& x){
		boost::math::normal_distribution<> d;
		return pdf(d,x);
}

void testIntegration1(){
	Real absAcc=0.00001;
	Size maxEval=1000;

	boost::function<Real (Real)> ptrF(normalPdf);
	Real a=0.0, b=M_PI; // M_PI is a QuantLib macro for \pi

	TrapezoidIntegral<MidPoint>		numInt1(absAcc,maxEval);
	SimpsonIntegral				numInt2(absAcc,maxEval);
	GaussLobattoIntegral			numInt3(maxEval,absAcc);
	GaussKronrodAdaptive			numInt4(absAcc,maxEval);
	GaussKronrodNonAdaptive			numInt5(absAcc,maxEval,absAcc);
	
	Real analytical=normalCdf(b)-normalCdf(a);

	std::cout << "Analytical:"<< analytical<< std::endl;
	std::cout << "Midpoint Trapezoidal:"<<numInt1(ptrF,a,b)<< std::endl;
	std::cout << "Simpson:"	<< numInt2(ptrF,a,b)<< std::endl;
	std::cout << "Gauss Lobatto:"<< numInt3(ptrF,a,b)<< std::endl;
	std::cout << "Gauss Kronrod Adpt:"<< numInt4(ptrF,a,b)<< std::endl;
	std::cout << "Gauss Kronrod Non Adpt:"<< numInt5(ptrF,a,b)<< std::endl;
}