/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	// Base Case
	if (n == 0)
		return 1;

	// Reduction Case
	else
		return n*factorialRecurs(n-1);
}

int factorialDinam(int n)
{
	// Static vector to save computed values for future usage
	static vector<int> answers = {1 , 1};

	// If the answer wasn't computed yet, compute it (starting in the previously highest computed answer)
	if (n >= answers.size()){
		for (int i=answers.size() ; i<=n ; i++){
			answers.push_back(i*answers.at(i-1));
		}
	}

	return answers.at(n);
}
