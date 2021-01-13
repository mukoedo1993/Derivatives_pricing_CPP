#ifndef STATISTICS_H
#define STATISTICS_H

#include<vector>
#include<memory>

class StatisticsMC
{
public:
    StatisticsMC(){}

    virtual void DumpOneResult(double result)=0;
    virtual std::vector<std::vector<double>>
                    GetResultsSoFar()const = 0;

    virtual std::shared_ptr<StatisticsMC> clone()const =0 ;
    virtual ~StatisticsMC(){}
};

class StatisticsMean: public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>>
                        GetResultsSoFar()const;
    virtual std::shared_ptr<StatisticsMC> clone()const;

private:
    double RunningSum;
    unsigned long PathsDone;

};
#endif