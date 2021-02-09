
// Author: Dimitri Reiswich

Real normalPdf(const Real& x, const Real& a, const Real& b){
		boost::math::normal_distribution<> d;
		Real t1=0.5*(b-a), t2=0.5*(b+a);
		return t1*pdf(d,t1*x+t2);
}

void testIntegration3(){
	Real a=-1.96, b=1.96;
	boost::function  <double (double)>	myPdf;	

	myPdf=boost::bind(normalPdf,_1,a,b);
	GaussChebyshevIntegration gChebInt(64); //(-1,1)
	
	Real analytical=normalCdf(b)-normalCdf(a);

	std::cout << "Analytical:" << analytical<< std::endl;
	std::cout << "Chebyshev:" << gChebInt(myPdf)<< std::endl;
}