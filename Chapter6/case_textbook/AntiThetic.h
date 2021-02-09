/* A standard method of improving the convergence of Monte
*Carlo is anti-thetic sampling. The idea is very simple, if a X
*X is a draw from a standard Gaussian distribution so is negative X.
* This means that if we draw a vector (X1,.. ,Xn) for one path then instead
*of drwaing a new vector for the next path we simply use (-X1,...-Xn). The method
*guarantees that, for any even number of paths drawn, all the odd moments of the Sample
*of Gaussian variates drwan are zero, and in particular the mean is correct.
*/

/*
*The implementation of the class is quite straightforward. Most of the methods consist
*of simply forwarding the request to the inner class, together with bookkeeping for odd
*and even paths. The main GetInforms method, gets uniforms from the inner generator for the
*odd draws, store the results, Xj, and return (1-X1,...,1-Xn) for the even draws.
*Note that:
N^(-1)(1-x)=-N^(-1)(x)
.....
*/

#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include"Random2.h"
#include"Wrapper.h"


/*
*The decorator class is quite simple. It has an array as a data member to store
*the last vector drawn, and a boolean to indicate whether the next draw should be
*drawn from the inner generator, or be the anti-thetic of the last draw. A copy of the
*generator we are using is stored using the Wrapper template class and cloning, as usual.
*Note that we are actually taking a copy of the generator here so that the sequence of draws
*from the original generator will not be affected by drawing from the anti-thetic generator.
*/
class AntiThetic: public RandomBase {
public:
AntiThetic(const Wrapper<RandomBase>& innerGenerator);

virtual RandomBase *clone()const override;

void GetUniforms(MJArray& variates)override;

void Skip(unsigned long numberOfPaths)override;

void SetSeed(unsigned long Seed) override;

void ResetDimensionality(unsigned long NewDimensionality) override;

void Reset()override;

private:
    Wrapper<RandomBase> InnerGenerator;

    bool OddEven;

    MJArray NextVariates;
};

#endif