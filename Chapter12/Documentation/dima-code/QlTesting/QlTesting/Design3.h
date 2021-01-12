#include<boost/foreach.hpp>
void testingDesignPatternsAddSpot(){
	SimpleRepository::instance().addObject("spot0",(Real)110.23);
}
void testingDesignPatternsAddYields(){
	std::map<Real,Real> yieldMap;
	yieldMap[1.0]=0.0345; yieldMap[3.0]=0.0361; yieldMap[6.0]=0.0415;
	SimpleRepository::instance().addObject("yieldMap0",yieldMap);
}
void testingDesignPatterns1(){
	// write spot and yield map
	testingDesignPatternsAddSpot();
	testingDesignPatternsAddYields();
	// +++++++++++++++++++++ Get Spot
	std::string spotHandle("spot0");
	boost::any currSpot=SimpleRepository::instance().getObject(spotHandle);
	QL_REQUIRE(!currSpot.empty(),
			"No object with name " << spotHandle << "in repository.");
	//
	Real* spot=boost::any_cast<Real>(&currSpot);
	if(spot==NULL){
		std::cout << "spot casting failed" << std::endl;
	}else{
		std::cout << "Spot:" << *spot << std::endl;
	}
	// +++++++++++++++++++++ Get Yield Map
	std::string yieldHandle("yieldMap0");
	boost::any yieldAnyObj=SimpleRepository::instance().getObject(yieldHandle);
	QL_REQUIRE(!yieldAnyObj.empty(),
			"No object with name " << yieldHandle << "in repository.");
	//
	std::map<Real,Real>* yieldMap=boost::any_cast<std::map<Real,Real>>(&yieldAnyObj);
	if(yieldMap==NULL){ 
		std::cout << "yield map casting failed" << std::endl;
	}else{ std::pair<Real,Real> x;
		BOOST_FOREACH(x, (*yieldMap)){
			std::cout << "mat:" << x.first << ", yield:" << x.second << std::endl;
		}
	}
}