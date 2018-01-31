#ifndef HW3_H
#define HW3_H	

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Function Declarations
double average_complexity(int i);
int randomNumGen(int i); 
std::vector<int> randshuffleVector(int i, std::vector<int> randVector);
int searchVector(int x, std::vector<int> myVector);


double average_complexity(int i)
{
	srand(static_cast<int>(time(0))); // Provide a random seed
	std::vector<int> randVector; // Vector that will hold shuffled number from 1 to i
	std::vector<int> sumVector; // Vector that will hold all values to sum  
	double sum = 0.0;
	int x = 0; 
	int y = 0; 

	randVector = randshuffleVector(i, randVector);

	for (int n = 0; n<randVector.size(); ++n)
	{
		x = randomNumGen(i); // Generate random number between 1 and i
		y = searchVector(x, randVector); // The position of the found index
		sumVector.push_back(y);
		sum += sumVector[n];
	}

	double averageComparisons = 0.0; // Will hold the value of sum/number of values 
	averageComparisons = sum/sumVector.size();
	return averageComparisons;
}

// Generate random number between 1 and i
// return a random number
int randomNumGen(int i)
{
	int r = 1 + rand()%i; // Random number in [1, i]
	return r; 
}

// Fill randVector with numbers from 1 to i, and shuffle randomly
// returns the  randVector
std::vector<int> randshuffleVector(int i, std::vector<int> randVector)
{
	for ( int n=1 ; n <= i ; ++n )
	{
		randVector.push_back(n);
	}
	// Shuffling the vector
	std::random_shuffle(std::begin(randVector), std::end(randVector));
	return randVector;
}

// Given a number x and a vector myVector, search myVector for x
// returns the position of x
int searchVector(int x, std::vector<int> myVector)
{
	int value = 0;
	for (int i = 0; i<myVector.size(); ++i)
	{
		if (myVector[i] == x)
		{
			value = i+1;	
			break;
		}
	}
	return value; // value is the position where x was found
}

#endif