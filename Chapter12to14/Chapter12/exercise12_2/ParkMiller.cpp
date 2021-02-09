#include "ParkMiller.h"

//#include<boost/uniform_real_distribution.hpp>

#include<boost/random.hpp>
using namespace boost::random;
const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_ ) : Seed(Seed_)
{
    if (Seed ==0)
        Seed=1;
}

  
void ParkMiller::SetSeed(long Seed_)
{
  Seed=Seed_;
  if (Seed ==0)
        Seed=1;
}

unsigned long ParkMiller::Max()
{
    return m-1;
}

unsigned long ParkMiller::Min()
{
    return 1;
}

long ParkMiller::GetOneRandomInteger()
{
    long k;
 
 static mt19937 mt;
   uniform_int_distribution<int> ui(Min(), Max());
   Seed= ui(mt);

        //http://erikerlandson.github.io/algorithm/libs/multiprecision/doc/html/boost_multiprecision/tut/random.html

     return Seed;

                                        
}


RandomParkMiller::RandomParkMiller(unsigned long Dimensionality, unsigned long Seed)
:    RandomBase(Dimensionality),
    InnerGenerator(Seed),
    InitialSeed(Seed)
{
    Reciprocal = 1/(1.0+InnerGenerator.Max());
}

RandomBase* RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);   
}

void RandomParkMiller::GetUniforms(MJArray& variates)
{
    for (unsigned long j=0; j < GetDimensionality(); j++)
        variates[j] = InnerGenerator.GetOneRandomInteger()*Reciprocal;

}
    
void RandomParkMiller::Skip(unsigned long numberOfPaths)
{
    MJArray tmp(GetDimensionality());
    for (unsigned long j=0; j < numberOfPaths; j++)
        GetUniforms(tmp);
}

void RandomParkMiller::SetSeed(unsigned long Seed)
{
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset()
{
    InnerGenerator.SetSeed(InitialSeed);
}


void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality)
{
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}