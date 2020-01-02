//Sabrina Turney
//COP 2224 - C++
//May 15, 2019



// SpeedTrapFunctions.cpp
// This program generates a random speed limit,
// as well as showcasing output in a series of function calls with and without arguments. Drive safe, or pay!



#include "pch.h"     // included for my Microsoft Visual Studio 2017
#include <cstdlib>   // for rand() and srand() functions
#include <ctime>     // for time()
#include <iostream>  // for cin and cout
#include <iomanip>   // for correctly displauing output
using namespace std;

// other functions we'll be passing to 
int randomSpeed();  // generates a number for the speed limit
void ticketCost(int);  // gets input for speed and calculates fine amount

const float baseRate = 60.25;  // global constant for ticket cost, before additional fines are added.


int main()
{
	char ticketLoop; // create a loop to execute the program until program is exited
	do
	{
		ticketCost(randomSpeed());
		cout << "\nPress Y to continue, or any key to quit... ";
		cin >> ticketLoop;
	} while (ticketLoop == 'Y' || ticketLoop == 'y');

	return 0;
}

// defining the other functions

// random speed gets the random speed limit for each iteration of the program
int randomSpeed()
{
	srand(time(NULL));  // using computer time for actual random values each time program is run
	return 25 + rand() % (65 + 1 - 25);  // returng rand num between 25-65 for speed limit value
}

// ticketCost gets the cost using the randomSpeed variable from the previous function
void ticketCost(int speedLimit)
{
	long speedInput, speedDifference;
	float ticketCost;  // initializes the variables used for calculating fines

	//	use initialized variables with speedLimit and get the user input for driver speed
	cout << "The speed limit is " << speedLimit; // just like the example output
	cout << "\nEnter the driver's speed \n";
	cin >> speedInput;
	
	// negative input to zero- drivers can't go negative speed
	if (speedInput < 0)
	{
		speedInput = 0;
	}
	
	// output to the user their entered speed, as well as the random speed limit variable generated
	cout << "\nThe speed limit is " << speedLimit;
	cout << "\nThe driver's speed was " << speedInput;

	// elif statement to calculate fines (or not!)
	speedDifference = speedInput - speedLimit;
	if (speedDifference > 0)
	{
		if (speedDifference >= 20)
		{
			ticketCost = baseRate + (baseRate * 0.20);
		}
		else if (speedDifference > 10)  
		{
			ticketCost = baseRate + (baseRate * 0.10);
		}
		else if (speedDifference > 5)
		{
			ticketCost = baseRate + (baseRate * 0.05);
		}
		else
		{
			ticketCost = baseRate;
		}
		cout << fixed << setprecision(2) << "\nThe speeding fine is " << "$" << ticketCost << endl;
	}
	else cout << "\nGood job! You drove safetly under the speed limit." << endl;
	return;
}