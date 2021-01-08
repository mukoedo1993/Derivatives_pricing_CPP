/*
*   uses source files
*   AntiThetic.cpp
*   Arrays.cpp
*   ConvergenceTable.cpp
*   ExoticBSEngine.cpp
*   ExtoticEngine.cpp
*   MCStatistics.cpp
*   Normals.cpp
*   Parameters.cpp
*   ParkMiller.cpp
*   PathDependent.cpp
*   PathDependentKnockOut.cpp
*   PayOff3.cpp
*   PayOffBridge.cpp
*   Random2.cpp
*/

#include"ParkMiller.h"
#include<iostream>

#include"MCStatistics.h"
#include"ConvergenceTable.h"
#include"AntiThetic.h"
#include"PathDependentKnockOut.h"
#include"ExoticBSEngine.h"
#include<stdexcept>
using std::cin; using std::cout;
using std::vector;
int main()
{
    double Expiry;
    double Strike;
    double Barrier;
    double Rebate;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long NumberOfPaths;
    unsigned NumberOfDates;

    cout<<"\nEnter expiry\n";
    cin >> Expiry;

    cout<<"\nStrike\n";
    cin >> Strike;

    cout<<"\nEnter spot\n";
    cin >> Spot;

    cout<<"\nENter vol\n";
    cin >> Vol;

    cout<<"\nEnter barrier: \n";
    cin >> Barrier;

    if(Spot>=Barrier)
       throw 
       std::invalid_argument("It is meaningless as the option will expire immedieately at the time of trade!\n");

    cout<<"\nEnter Rebate: \n";
    cin>> Rebate;

    cout<<"\nr\n";
    cin >> r;

    cout << "\nd\n";
    cin >> d;//d is dividend.

    cout<<"Number of dates\n";
    cin >> NumberOfDates;

    cout<< "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    MJArray times(NumberOfDates);

    for(unsigned long i=0; i < NumberOfDates; ++i)
            times[i] = (i+1.0)*Expiry/NumberOfDates;

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    PathDependentKnockOut theOption(times, Expiry, thePayOff,Barrier, Rebate);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(NumberOfDates);

    AntiThetic GenTwo(generator);

    ExoticBSEngine theEngine(theOption, rParam, dParam,
                                VolParam, GenTwo, Spot);

    theEngine.DoSimulation(gathererTwo, NumberOfPaths);

    vector<vector<double>> results = 
        gathererTwo.GetResultsSoFar();

    cout << "\nFor the Asian call price the results are\n";

    for(unsigned long i=0; i < results.size();++i)
    {
        for(unsigned long j=0; j<results[i].size();j++)
            cout<<results[i][j]<<" ";

        cout<<'\n';
    }

    double tmp;
    cin >> tmp;

}