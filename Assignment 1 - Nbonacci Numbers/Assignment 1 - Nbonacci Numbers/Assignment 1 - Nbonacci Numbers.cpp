#include <iostream>

const unsigned int SEQUENCE_SIZE = 20;


// This function computes the n'th number in the series sequence.  
// For example, a series of 2 is the Fibonacci sequence, a series
// of 3 is the Tribonacci sequence.
long nbonacci(unsigned int series, unsigned int n) 
{
	if (n <= series - 1) 
	{
		return 1;
	}
	unsigned int result = 0;
	for (unsigned int i = 0; i < series; i++) 
	{
		result += nbonacci(series, n - 1 - i);
	}
	return result;
}

// Computes the Nbonacci ratio to the precision of 0.000001
void computeNbonacciRatio(std::string title, unsigned int series) 
{
	double previousRatio = 0;
	double currentRatio = 100;
	unsigned int index = series - 1;
	while (std::abs(previousRatio - currentRatio) > 0.000001) 
	{
		previousRatio = currentRatio;
		currentRatio = static_cast<double>(nbonacci(series, index + 1)) / nbonacci(series, index);
		index++;
	}
	std::cout << title << " ratio approaches " << currentRatio << " after " << index << " iterations." << std::endl;
}

// Displays an Nbonacci sequence of length SEQUENCE_SIZE. Series refers
// to which Nbonacci sequence is to be displayed.
void displayNbonacci(std::string title, unsigned int series) 
{
	std::cout << "--- " << title << " ---\n";
	for (int i = 0; i < SEQUENCE_SIZE; i++) 
	{
		std::cout << nbonacci(series, i) << " ";
	}
	std::cout << "\n";
}



int main()
{
    std::cout << "Nbonacci Numbers\n\n";
	displayNbonacci("Fibonacci", 2);
	displayNbonacci("Tribonacci", 3);
	displayNbonacci("Fourbonacci", 4);
	displayNbonacci("Fivebonacci", 5);
	std::cout << "\n---Ratios---\n";
	computeNbonacciRatio("Fibonacci", 2);
	computeNbonacciRatio("Tribonacci", 3);
	computeNbonacciRatio("Fourbonacci", 4);
	computeNbonacciRatio("Fivebonacci", 5);

	return 0;
}

