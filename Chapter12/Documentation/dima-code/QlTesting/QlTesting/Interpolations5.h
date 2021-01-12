
void testingInterpolations4(){

	std::vector<Real> xVec(11), yVec(xVec.size());
	signed int i=1;

	// setup a x grid from [-5,5]
	BOOST_FOREACH(Real& x, xVec) x=(Real)i;i++;
	// set y=x
	yVec=xVec;

	Matrix M(xVec.size(),yVec.size());

		for(Size rowIt=0;rowIt<xVec.size();rowIt++)
			for(Size colIt=0;colIt<yVec.size();colIt++)
				M[rowIt][colIt]=std::sin(xVec[rowIt])+std::sin(yVec[colIt]);
	
/*	BilinearInterpolation bilinIntp(xVec.begin(), xVec.end(),
									yVec.begin(), yVec.end(), M);

*/
/*	std::vector<Real>::iterator k=xVec.begin(),j=xVec.begin()+1;

	while(j!=xVec.end()){
		std::cout << "k: " << *k << " j:" << *j << std::endl; 
		k++; j++;
	}*/


	BicubicSpline bicubIntp(xVec.begin(), xVec.end(),
									yVec.begin(), yVec.end(), M);

	Real x=0.5, y=4.5;

	std::cout << "Analytical Value:  "	<< std::sin(x)+std::sin(y) << std::endl;
//	std::cout << "Bilinear Value:  "	<< bilinIntp(x,y) << std::endl;
	std::cout << "Bicubic Value:  "		<< bicubIntp(x,y) << std::endl;

}