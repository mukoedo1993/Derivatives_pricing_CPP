
// Author: Dimitri Reiswich

void testingMatrix3(){


Matrix A(5,5);

A[0][0] = 1.0;    A[0][1] = 0.968;  A[0][2] = 0.953;A[0][3] = 0.927;A[0][4] = 0.898;
A[1][0] = 0.968;  A[1][1] = 1.0;    A[1][2] = 0.989;A[1][3] = 0.968;A[1][4] = 0.923;
A[2][0] = 0.953;  A[2][1] = 0.989;  A[2][2] = 1.0;  A[2][3] = 0.991;A[2][4] = 0.951;
A[3][0] = 0.927;  A[3][1] = 0.968;  A[3][2] = 0.991;A[3][3] = 1.0;  A[3][4] = 0.966;
A[4][0] = 0.898;  A[4][1] = 0.923;  A[4][2] = 0.951;A[4][3] = 0.966;A[4][4] = 1.00;

SymmetricSchurDecomposition schurDec(A);
SVD svdDec(A);


	std::cout << A << std::endl;
	std::cout << "PCA Eigenvalues:" << std::endl;
	std::cout << schurDec.eigenvalues()  << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "PCA Eigenvectors:" << std::endl;
	std::cout << schurDec.eigenvectors() << std::endl;


/* R- Equivalent	.
> prA1=prcomp(A,center=FALSE,scale.=FALSE)
> prA1
Standard deviations:
[1] 2.407175562 0.060866019 0.024499379 0.006189314 0.001269725

Rotation:
            PC1          PC2        PC3         PC4          PC5
[1,] -0.4408395  0.625136821  0.5646219 -0.30985889 -0.007352174
[2,] -0.4504205  0.312620494 -0.3307845  0.67736657 -0.362140809
[3,] -0.4537677  0.002698232 -0.3783505 -0.05749799  0.804756160
[4,] -0.4507878 -0.286883738 -0.3688516 -0.59842481 -0.469387218
[5,] -0.4400764 -0.655105199  0.5409095  0.28938509  0.029036901
*/

}