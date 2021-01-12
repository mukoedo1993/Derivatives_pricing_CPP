
// Author: Dimitri Reiswich

void testingRandomNumbers4(){
   Size dim=5;

   SobolRsg sobolGen(dim);
   HaltonRsg haltonGen(dim);
   FaureRsg faureGen(dim);

   std::vector<Real> sampleSobol(sobolGen.dimension()),
					 sampleHalton(haltonGen.dimension()),
					 sampleFaure(faureGen.dimension());

   sampleSobol=sobolGen.nextSequence().value;
   sampleHalton=haltonGen.nextSequence().value;
   sampleFaure=faureGen.nextSequence().value;

   BOOST_FOREACH(Real x, sampleSobol) std::cout << "S:" << x << std::endl;
   BOOST_FOREACH(Real x, sampleHalton) std::cout << "H:" << x << std::endl;
   BOOST_FOREACH(Real x, sampleFaure) std::cout << "F:" << x << std::endl;

}