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
          return  vector<vector<double>>(1,{static_cast<double>(RunningSum)/
          static_cast<double>(PathsDone)});
}

std::shared_ptr<StatisticsMC> 
   StatisticsMean::clone()const
   {
       return std::make_shared<StatisticsMean>(*this);
   }
