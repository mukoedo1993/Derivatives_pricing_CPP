
// Author: Dimitri Reiswich
#include "Factory1.h"
#include "Factory3.h"
#include <boost/foreach.hpp>
#include "Singleton1.h"
#include <boost/optional.hpp>

void addOption1(){

	Real spot=100.0, strike=110.0;
	Rate rd=0.03, rf=0.01;
	Volatility vol=0.20;
	Time mat=1.0;
	MyOption::Type type(MyOption::Call);

	MyOption optionMade=MakeMyOption()
			.withType(type)
			.withMat(mat)
			.withSpot(spot)
			.withForRate(rf)
			.withStrike(strike)
			.withVol(vol)
			.withDomRate(rd);

		ObjectRepository::instance().addObject("option1",optionMade);

}

void addOption2(){

	Real spot=50.0, strike=32.0;
	Rate rd=0.02, rf=0.044;
	Volatility vol=0.133;
	Time mat=5.0;
	MyOption::Type type(MyOption::Call);

	MyOption optionMade=MakeMyOption()
			.withType(type)
			.withMat(mat)
			.withSpot(spot)
			.withForRate(rf)
			.withStrike(strike)
			.withVol(vol)
			.withDomRate(rd);

		ObjectRepository::instance().addObject("option2",optionMade);
}

void exercise3(){

	addOption1();	
	addOption2();

	boost::optional<MyOption> myOption1=ObjectRepository::instance().getObject<MyOption>("option1");
	boost::optional<MyOption> myOption2=ObjectRepository::instance().getObject<MyOption>("option2");

	std::cout << "------------- My Option 1:--------------------" << std::endl;
	std::cout << myOption1->getMat() << std::endl;
	std::cout << myOption1->getSpot() << std::endl;
	std::cout << myOption1->getStrike() << std::endl;
	std::cout << "------------- My Option 2:--------------------" << std::endl;
	std::cout << myOption2->getMat() << std::endl;
	std::cout << myOption2->getSpot() << std::endl;
	std::cout << myOption2->getStrike() << std::endl;

	


}