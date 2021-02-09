
// Author: Dimitri Reiswich

void testingMatrix1(){

	Matrix A(3,3);
	A[0][0]=0.2;A[0][1]=8.4;A[0][2]=1.5;
	A[1][0]=0.6;A[1][1]=1.4;A[1][2]=7.3;
	A[2][0]=0.8;A[2][1]=4.4;A[2][2]=3.2;
	   
	Real det=determinant(A);
	QL_REQUIRE(!close(det,0.0),"Non invertible matrix!");

	Matrix invA=inverse(A);

	std::cout << A << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << transpose(A) << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << det << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << invA << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << A*invA << std::endl;
	std::cout << "--------------" << std::endl;
}