#include"SimpleMC5.h"
#include<iostream>
using namespace std;
#include"Vanilla3.h"
//Rather than using implicit big five, we give all definitions explicitly for the interface
//class: VanillaOption here.
/*
   requires PayOff3.cpp, 
            PayOffBridge.cpp,
            Random1.cpp, 
            SimpleMC5.cpp
            Vanilla3.cpp
*/
int main()
{
	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nStrike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);

	cout <<"\nthe call price is " << result << "\n";
    
    VanillaOption secondOption(theOption);
    result = SimpleMonteCarlo3(secondOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

	cout <<"\nthe call price is " << result << "\n";

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    VanillaOption back_up_op(theOption);
    theOption = thirdOption;
     
    result = SimpleMonteCarlo3(theOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"\nthe put price is " << result << "\n";
     
     VanillaOption fourthOption(back_up_op);
     result = SimpleMonteCarlo3(fourthOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"\nthe call price is " << result << "\n";

    VanillaOption fifthOption(std::move(fourthOption));
    result = SimpleMonteCarlo3(fifthOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"\nthe call price is " << result << "\n";
    theOption=std::move(fifthOption);
        result = SimpleMonteCarlo3(theOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"\nthe call price is " << result << "\n";

    double tmp;
    cin >> tmp;

	return 0;

}