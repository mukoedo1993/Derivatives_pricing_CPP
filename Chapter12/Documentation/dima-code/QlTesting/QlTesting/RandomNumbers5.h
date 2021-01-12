
// Author: Dimitri Reiswich

void testingRandomNumbers5(){

   SobolRsg sobolGen(1);
   // Mersenne Twister setup
	BigInteger seed=12324;
	MersenneTwisterUniformRng	unifMt(seed);
	BoxMullerGaussianRng<MersenneTwisterUniformRng> bmGauss(unifMt);

    IncrementalStatistics boxMullerStat, sobolStat;
	MoroInverseCumulativeNormal invGauss;	

	Size numSim=10000;
	Real currSobolNum;

	for(Size j=1;j<=numSim;++j){
		boxMullerStat.add(bmGauss.next().value);

		currSobolNum=(sobolGen.nextSequence().value)[0];
		sobolStat.add(invGauss(currSobolNum));
	}

	std::cout << "BoxMuller Mean:" << boxMullerStat.mean() << std::endl;
	std::cout << "BoxMuller Var:" << boxMullerStat.variance() << std::endl;
	std::cout << "BoxMuller Skew:" << boxMullerStat.skewness() << std::endl;
	std::cout << "BoxMuller Kurtosis:" << boxMullerStat.kurtosis() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Sobol Mean:" << sobolStat.mean() << std::endl;
	std::cout << "Sobol Var:" << sobolStat.variance() << std::endl;
	std::cout << "Sobol Skew:" << sobolStat.skewness() << std::endl;
	std::cout << "Sobol Kurtosis:" << sobolStat.kurtosis() << std::endl;

}