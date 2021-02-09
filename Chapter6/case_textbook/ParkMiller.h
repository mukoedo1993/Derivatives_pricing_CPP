#ifndef PARK_MILLER_H
#define PARK_MILLER_H
#include "Random2.h"
/*
*Park&Miller: minimal standard generator.
* In other words, it is a generator that provides a minimum guaranteed
*level of statistical accuracy. We refer the reader to [28] for further discussion
*of this and many other random number generators.
*   We present the generator in two pieces. A small inner class that develops a random
*generator that returns one integer every time it is called, and a larger class that
*turns the output into a vector of uniforms in the format desired. 
*/
class ParkMiller
{
public:
    
    ParkMiller(long Seed = 1);

    long GetOneRandomInteger();
    void SetSeed(long Seed);

    static unsigned long Max();
    static unsigned long Min();

private:

    long Seed;

};

class RandomParkMiller : public RandomBase
{
public:
/*We do not overwrite the concrete virtual function GetGaussian here.*/
    RandomParkMiller(unsigned long Dimensionality, unsigned long Seed=1);

    virtual RandomBase* clone() const override;    /*virtual copy constructor*/
    virtual void GetUniforms(MJArray& variates) override;    
    virtual void Skip(unsigned long numberOfPaths) override;
    virtual void SetSeed(unsigned long Seed) override;
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long NewDimensionality) override;
   

private:

    ParkMiller InnerGenerator;
    unsigned long InitialSeed;
    double Reciprocal;

};
#endif
