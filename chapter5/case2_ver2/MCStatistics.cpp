//
//  MCStatisitcs.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "MCStatistics.h"
using namespace std;

StatisticsMean::StatisticsMean(): RunningSum(0.0),PathsDone(0)
{
    
}

// collect one result from one path
// called every path
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

// called only once per simulation
vector<vector<double>> StatisticsMean::GetResultsSoFar()const
{
    
    return {{static_cast<double>(RunningSum)/
          static_cast<double>(PathsDone)}};

}

StatisticsMC* StatisticsMean::clone()const
{
    return new StatisticsMean(*this);
}



