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

Paramters& Parameters::operator=(const Paramers& original)
{
    if(this!=&original)
    {InnerObjectPtr= original.InnerObjectPtr;
    }
    return *this;
}

Paramters& Paramters::operator=(Paramters&& original)
{
    if(this!=&original)
    {InnerObjectPtr= std::move(original.InnerObjectPtr);
    }
    return *this;
}

Parameters::~Parameters()
{

}

double Parameters::Mean(double time1,double time2)const {
   return Integral(time1,time2)/(time2-time1);
}

double Paramters::RootMeanSquare(double time1, double time2)const
{
    return IntegralSquare(time1, time2)/(time2-time1);
}

ParametersConstant::ParametersConstant(double constant)
:Constant(constant),ConstantSquare(Constant*Constant)
{

}

ParametersInner* ParametersConstant::clone()const
{
    return new ParametersConstant(*this);
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