#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H
#include"Vanilla1.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif