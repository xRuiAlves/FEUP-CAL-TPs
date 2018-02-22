/*
 * Sum.cpp
 */

#include "Sum.h"
#include <climits>
#include <chrono>

#define MAX_S 50

string calcSum(int* sequence, int size)
{
	string answer = "";

	for (int i=1 ; i<=size ; i++){
		answer += parsePairToString(getMinSum(sequence , size , i));
	}

	return answer;
}

string parsePairToString(const pair<int,int> & resPair){
	return ( to_string(resPair.first) +
			',' +
			to_string(resPair.second) +
			';' );
}

pair<int,int> getMinSum(int* sequence, int sequenceSize, int subSequenceLength){
	int currentSum = 0;

	// Initial sum
	for (int i=0 ; i<subSequenceLength ; i++){
		currentSum += sequence[i];
	}
	int minSum = currentSum;	// Starting minimal sum
	int minSumStartingIndex = 0;

	// Analise for next subsums, my removing the previous element and adding the new one!
	for (int i=1 ; i<(sequenceSize-subSequenceLength+1) ; i++){
		currentSum -= sequence[i-1];					// Remove the previous element
		currentSum += sequence[i+subSequenceLength-1];	// Sum the next (new) element

		// Update the minimal sum (if needed)
		if (currentSum < minSum){
			minSum = currentSum;
			minSumStartingIndex = i;
		}
	}

	return make_pair(minSum , minSumStartingIndex);
}

