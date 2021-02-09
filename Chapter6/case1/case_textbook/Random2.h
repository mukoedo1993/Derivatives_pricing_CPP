#ifndef RANDOM2_H
#define RANDOM2_H

#include "Arrays.h"

class RandomBase
{
public:

    RandomBase(unsigned long Dimensionality);

    inline unsigned long GetDimensionality() const;

    virtual RandomBase* clone() const=0;
    virtual void GetUniforms(MJArray& variates)=0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SetSeed(unsigned long Seed) =0;
    virtual void Reset()=0;

    virtual void GetGaussians(MJArray& variates);
    /*
    *While most of the methods of RandomBase are pure virtual, three are 
    * not. The method GetGaussians transforms uniforms obtained from the
    * GetUniform method into standard Gaussian distributions. It does this
    * via an approximation....
    */



   
    /*
    *We also have the concrete virtual function ResetDimensionality. 
    * As the base class stores dimensionality, it must be told when dimensionality
    * changes: that is the purpose of this function. However, the function is virtual
    * because generally if dimensionality changes, the random number generator will also
    * need to know. Suppose we have overridden this virtual function in an inherited class.
    * Calling the method thus only calls the inherited class method and the base class method
    * is ignored; however, we still need the base class method to be called; this has to be
    * done by the inherited class method. The syntax to do this is to prefix the method with
    * RandomBase::. The compiler then ignores the virtual function table and instead knows 
    * to call the method associated to the base class.
    */
    virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
    unsigned long Dimensionality;

};

unsigned long RandomBase::GetDimensionality() const
{
    return Dimensionality;
}

#endif