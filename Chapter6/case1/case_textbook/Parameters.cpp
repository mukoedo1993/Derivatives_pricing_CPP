
#include "Parameters.h"

Parameters::Parameters(const ParametersInner& innerObject)
{
   InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original)
{
   InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original)
{
   if (this != &original)
   {   
      delete InnerObjectPtr;
      InnerObjectPtr = original.InnerObjectPtr->clone();
   }
   return *this;
}

Parameters::~Parameters()
{
   delete InnerObjectPtr;
}


ParametersConstant::ParametersConstant(double constant)
{
    Constant = constant;
    ConstantSquare = Constant*Constant;
}

ParametersInner* ParametersConstant::clone() const
{
    return new ParametersConstant(*this);
}


double ParametersConstant::Integral(double time1, double time2) const
{
    return (time2-time1)*Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const
{
    return (time2-time1)*ConstantSquare;
}