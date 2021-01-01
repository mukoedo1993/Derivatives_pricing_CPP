#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

class StatisticsMC
{
public:

    StatisticsMC(){}

    virtual void DumpOneResult(double result)=0;
    virtual std::vector<std::vector<double> > GetResultsSoFar() const=0;
    virtual StatisticsMC* clone() const=0;
    virtual ~StatisticsMC(){}

private:

};


class StatisticsMean : public StatisticsMC
{

public:

    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:

    double RunningSum;
    unsigned long PathsDone;

};

#endif
