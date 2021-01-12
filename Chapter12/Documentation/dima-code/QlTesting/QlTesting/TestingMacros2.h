
// Author: Dimitri Reiswich

int _tmain(int argc, _TCHAR* argv[])
{
	try{
			testingMacros1();
	} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			return 1;
	} catch (...) {
			std::cout << "unknown error" << std::endl;
			return 1;
	}
}