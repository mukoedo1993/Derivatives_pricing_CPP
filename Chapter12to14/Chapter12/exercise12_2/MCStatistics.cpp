#include"MCStatistics.h"
using namespace std;

StatisticsMean::StatisticsMean()
    :
    RunningSum(0.0), PathsDone(0UL)
{
}
    
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

vector<vector<double> > StatisticsMean::GetResultsSoFar() const
{
    return {{static_cast<double>(RunningSum)/static_cast<double>(PathsDone)}};
}

StatisticsMC* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}