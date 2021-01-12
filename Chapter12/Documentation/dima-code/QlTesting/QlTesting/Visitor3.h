
// Author: Dimitri Reiswich

void testingVisitor1(){

	MySimpleRate rSimple(0.03);
	MyContinuousRate rCont(0.03);
	Real t=5.0;

	MyDiscounter<MySimpleRate>		simpleDisc(t,rSimple);
	MyDiscounter<MyContinuousRate>	contDisc(t,rCont);

	std::cout << "Simple discount:" << simpleDisc.getDiscount() << std::endl;
	std::cout << "Continuous discount:" << contDisc.getDiscount() << std::endl;
}