
/*
We now want to adapt the pattern we have presented to work for Newton-Raphson
as well as for bisection. The fundamental difference from a design viewpoint is that Newton-Raphson
involves two functions, the value and the derivative, whereas bisection involves just one. One
solution would be simply to pass in two function objects: one for the value and another for
the derivative. This is unappealing, however, in that we would then need to initialize a set
of parameters for each object and we would have to be careful to make sure they are the same.
More fundamentally, the value and the derivative are really two objects does not express well our 
conceptual model of them.
*/
/*
A 
*/
/*
A sceond solution is to assume a name for the derivative function. After all, that is essentially
what we did for the value function; it was a special name with special syntax but ultimately it was
just assuming a name. Thus we could assume that the class had a method:
*/

/*
Fortunately, there is a way of specifying which class member function to call at compile time using
templatization. The key to this is a pointer to a member function. A pointer to a member function
is similar in syntax and idea to a function pointer, but it is restricted to methods of a single class.
The difference in syntax is pointer, but it is restricted to methods of a single class. The difference in syntax is
that the class name with a :: must be attached to the * when it is declared. Thus to declare a function pointer
called Derivative which must point to a method of the class T, we have:
double(T::*Derivative)(double)const
*/

/*We have three template parameters: the class, the pointer to the value function for that
class, and the pointer to the derivative function for that class.*/
#include<cmath>
template<class T, double (T::*Value)(double)const,
                  double (T::*Derivative)(double)const>
                  double NewtonRaphson(double Target,
                                       double Start,
                                       double Tolerance,
                                       const T& TheObject)
{
    double y = (TheObject.*Value)(Start);
    double x = Start;
    
    while(abs(y-Target)>Tolerance)
    {
       double d = (TheObject.*Derivative)(x);
        x+= (Target-y)/d;
        y = (TheObject.*Value)(x);
    }
    return x;
}
