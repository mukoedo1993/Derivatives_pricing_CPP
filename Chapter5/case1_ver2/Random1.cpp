#include"Random1.h"
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<chrono>
#include<random>
using namespace std;

double GetOneGaussianBysummation(){
double result=0;

for(unsigned long j=0;j<12;j++)
result+=rand()/static_cast<double>(RAND_MAX);
result-=6.0;
return result;
}

double GetOneGaussianByBoxMuller(){
    double result;

    double x;
    double y;
    double sizeSquared;
    do{
    x=2.0*rand()/static_cast<double>(RAND_MAX)-1;
    y=2.0*rand()/static_cast<double>(RAND_MAX)-1;
    sizeSquared=x*x+y*y;
    }while(sizeSquared>=1.0);
    result=x*sqrt(-2*log(sizeSquared)/sizeSquared);
    return result;
}

double GetOneGaussianBySTL(){
    double result;
    static std::default_random_engine e;
    std::normal_distribution<double> d(0.,1.0);
    return d(e);
}