#include"Random1.h"
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<chrono>
#include<random>
using namespace std;



double GetOneGaussianByBoxMuller(){
    static std::default_random_engine generator;
    std::normal_distribution<double>distribution(0.0,1.0);
    return distribution(generator);
}


double GetOneGaussianByBoxMuller(int){
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
