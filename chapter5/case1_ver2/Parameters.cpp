#include"Parameters.h"

Parameters::Parameters(const ParametersInner& InnerObject)
{
    InnerObjectPtr =  InnerObject.clone();
}

Parameters::Parameters(const Parameters& original)
:InnerObjectPtr(original.InnerObjectPtr)
{
   
}
Parameters::Parameters(Parameters&& original)
:InnerObjectPtr(std::move(original.InnerObjectPtr))
{

}

Parameters& Parameters::operator=(const Parameters& original)
{
    if(this!=&original)
    {InnerObjectPtr= original.InnerObjectPtr;
    }
    return *this;
}

Parameters& Parameters::operator=(Parameters&& original)
{
    if(this!=&original)
    {InnerObjectPtr= std::move(original.InnerObjectPtr);
    }
    return *this;
}

double Parameters::Mean(double time1,double time2)const {
   return Integral(time1,time2)/(time2-time1);
}

double Parameters::RootMeanSquare(double time1, double time2)const
{
    return IntegralSquare(time1, time2)/(time2-time1);
}

ParametersConstant::ParametersConstant(double constant)
:Constant(constant),ConstantSquare(Constant*Constant)
{

}

std::shared_ptr<ParametersInner> ParametersConstant::clone()const
{
    return std::make_shared< ParametersConstant>(*this);
}

double ParametersConstant::Integral(double time1,
                                    double time2)const
{
    return (time2-time1)*Constant;
}

double ParametersConstant::IntegralSquare(double time1,
                                         double time2)const
{
    return (time2-time1)*ConstantSquare;
}