
// Author: Dimitri Reiswich

void testingNull(){

	// setup a standard real
	Real myReal=10.0;
	// check against being null
	bool realIsNull=(myReal==Null<Real>());

	std::cout << "----------- Old -----------" << std::endl;
	std::cout << "Real is Null: " << realIsNull << std::endl;
		// set my real to max real and check against null
		myReal=(std::numeric_limits<float>::max)();
		realIsNull=(myReal==Null<Real>());
	std::cout << "Real is Null: " << realIsNull << std::endl;

	// do the same with new code
	myReal=10.0;

	bool realIsNullNew=(myReal==NullNew<Real>());

	std::cout << "----------- NEW -----------" << std::endl;
	std::cout << "Real is Null: " << realIsNullNew << std::endl;
		myReal=(std::numeric_limits<float>::max)();
		realIsNullNew=(myReal==NullNew<Real>());
	std::cout << "Real is Null: " << realIsNullNew << std::endl;

	Foo myFoo;
	Null<Foo> nullFoo;
	
	bool myFooIsNull=(myFoo==Null<Foo>());
//	bool myFooIsNullNew=(myFoo==NullNew<Foo>());

	std::cout << "----------- Foo Tests ---------" << std::endl;
	std::cout << "My Foo is Null Old: " << myFooIsNull<< std::endl;
	
	
}