
// Author: Dimitri Reiswich
#include <boost/function.hpp>
#include <boost/math/distributions.hpp>

void testIntegration2(){

		boost::function<Real (Real)> ptrNormalPdf(normalPdf);
		GaussLaguerreIntegration gLagInt(16); // [0,\infty]
		GaussHermiteIntegration	 gHerInt(16); //(-\infty,\infty)
		GaussChebyshevIntegration gChebInt(64); //(-1,1)
		GaussChebyshev2thIntegration gChebInt2(64); //(-1,1)

		Real analytical=normalCdf(1)-normalCdf(-1);

		std::cout << "Laguerre:"	<< gLagInt(ptrNormalPdf) << std::endl;
		std::cout << "Hermite:"		<< gHerInt(ptrNormalPdf) << std::endl;
		std::cout << "Analytical:"		<< analytical << std::endl;
		std::cout << "Cheb:"		<< gChebInt(ptrNormalPdf) << std::endl;
		std::cout << "Cheb 2 kind:"	<< gChebInt2(ptrNormalPdf) << std::endl;

}