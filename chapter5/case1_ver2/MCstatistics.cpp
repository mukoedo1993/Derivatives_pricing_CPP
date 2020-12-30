#include"StatisticsMC.h"
using std::vector;
StatisticsMean::StatisticsMean()
:
RunningSum(0.0),PathsDone(0UL)
{

}

void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

vector<vector<double>>
                StatisticsMean::GetResultsSoFar()const {
          return {{static_cast<double>(RunningSum)/
          static_cast<double>(PathsDone)}};
}

std::unique_ptr<StatisticsMC> 
   StatisticsMean::clone()const
   {
       return std::make_unique<StatisticsMean>(*this);
   }
