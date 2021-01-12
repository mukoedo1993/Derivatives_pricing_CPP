
// Author: Dimitri Reiswich

void testingMatrix2(){

Matrix A(3,3);
A[0][0] = 1.0;  A[0][1] = 0.9;  A[0][2] = 0.7;
A[1][0] = 0.9;  A[1][1] = 1.0;  A[1][2] = 0.4;
A[2][0] = 0.7;  A[2][1] = 0.4;  A[2][2] = 1.0;

SymmetricSchurDecomposition schurDec(A);
SVD svdDec(A);

	std::cout << "Schur Eigenvalues:" << std::endl;
	std::cout << schurDec.eigenvalues()  << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "Schur Eigenvector Mat:" << std::endl;
	std::cout << schurDec.eigenvectors() << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "Cholesky:" << std::endl;
	std::cout << CholeskyDecomposition(A) << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "SVD U:" << std::endl;
	std::cout << svdDec.U() << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "SVD V:" << std::endl;
	std::cout << svdDec.V() << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "SVD Diag D:" << std::endl;
	std::cout << svdDec.singularValues() << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "Pseudo Sqrt:" << std::endl;
	std::cout << pseudoSqrt(A) << std::endl;
}