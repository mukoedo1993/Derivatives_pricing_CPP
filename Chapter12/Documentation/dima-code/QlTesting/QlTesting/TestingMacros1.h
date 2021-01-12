
// Author: Dimitri Reiswich

void testingMacros1(){
	double x=0.0;
	QL_REQUIRE(x!=0,"Zero number!");
}

void testingMacros2(){
	QL_FAIL("Failed!");
}
 
