
// Author: Dimitri Reiswich

void DateTesting4(){

	Date d = Settings::instance().evaluationDate();

	std::cout << "Eval Date:" << d << std::endl;
	Settings::instance().evaluationDate()=Date(5,Jan,1995);
	d=Settings::instance().evaluationDate();
	std::cout << "New Eval Date:" << d << std::endl;
}