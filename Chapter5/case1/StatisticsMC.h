#ifndef STATISTICS_H
#define STATISTICS_H

#include<vector>
#include<memory>

class StatisticsMC
{
public:
    StatisticsMC(){}
    //The author omitted copy constructor.
    //It is too trivial to write as all members in its derived class are built-in types.
    virtual void DumpOneResult(double result)=0;
    virtual std::vector<std::vector<double>>
                    GetResultsSoFar()const = 0;

    virtual std::unique_ptr<StatisticsMC> clone()const =0 ;
    virtual ~StatisticsMC(){}
};

class StatisticsMean: public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>>
                        GetResultsSoFar()const;
    virtual std::unique_ptr<StatisticsMC> clone()const;

private:
    double RunningSum;
    unsigned long PathsDone;

};
#endif