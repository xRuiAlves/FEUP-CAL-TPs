/*
 * Change.cpp
 */

#include "Change.h"

string calcChange(int m, int numCoins, int *coinValues)
{
	// Check if no coins are passed or if change is 0
	if (numCoins==0 || m==0)
		return "";

	// Check if it is possible to make change for the 'm' value
	if (minCoins(numCoins-1 , m , coinValues) == 0)
		return "-";


	int coin = lastCoin(numCoins-1 , m , coinValues);
	vector<int> answer;

	// Compute all the needed coins to make change for the 'm' value
	while(coin != 0){
		m -= coin;
		answer.push_back(coin);
		coin = lastCoin(numCoins-1 , m , coinValues);
	}

	// Return the answer in the expected string format (C1;C2;C3;...;...;CN; , where C represents a coin)
	return computeOutput(answer);
}

string computeOutput(const vector<int> & coins){
	string output = "";

	// Compute the output in the indicated way by the unit tests
	for (unsigned int i=0 ; i<coins.size() ; i++){
		output += to_string(coins.at(i)) + ";";
	}

	return output;
}

int minCoins(int i , int k , int *coinValues){
	// Base case
	if (k==0){
		return 0;
	}

	// Impossible solution case
	if (k<0){
		return -1;
	}

	// Reduction case #1
	else if (i==0 ||
			(coinValues[i]<=k && 1 + minCoins(i, k-coinValues[i], coinValues) < minCoins(i-1,k,coinValues))) {

		return (1 + minCoins(i,k-coinValues[i],coinValues));
	}

	// Reduction case #2
	else{
		return minCoins(i-1 , k , coinValues);
	}
}

int lastCoin(int i , int k , int *coinValues){
	// Base case
	if (k==0 || i==-1){
		return 0;
	}

	// Reduction case #1
	if (coinValues[i] <= k &&
		(i==0 || (1+minCoins(i , k-coinValues[i] , coinValues) < minCoins(i-1,k,coinValues))) ){
		return coinValues[i];
	}

	// Reduction case #2
	else{
		return lastCoin(i-1 , k , coinValues);
	}
}


