#ifndef TREE_PRODUCTS_H
#define TREE_PRODUCTS_H
/*
*Notes: 
* There are a number of ways we could approach the 2nd class.
*We could inherit from PayOffBridge since we could view our class as
* adding structure to an existing class. Whilst this would work in code, I 
* personally dislike it as options being priced on a tree is not a type of pay-off,
* and so the inheritance is not expressing an(d) is a relationship.
*
*Another approach might be simply to define a second class to do the calculation rule,
*, and plg both the final pay-off and the calculation rule into the tree. Since for American
* options the final pay-off is generally relevant at all times, such an approach seems
*sub-optimal as it might require two copies of a pay-off.
*/

/*
*
*/
class TreeProduct{
public:
    TreeProduct(double FinalTime_);
    virtual double FinalPayOff(double Spot)const =0;
    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscountedFutureValue)
                                 const = 0;
    
    virtual ~TreeProduct(){}
    virtual TreeProduct* clone()const =0;
    double GetFinalTime()const;

private:
    double FinalTime;
    //FinalTime indicates the expiry time of the option
};


#endif