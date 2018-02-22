/*
 * Partioning.cpp
 */

#include "Partitioning.h"



int s_recursive(int n,int k)
{
	// Base case
	if (k==1 || k==n){
		return 1;
	}
	// Reduction case
	else {
		return ( s_recursive(n-1,k-1) + k*s_recursive(n-1,k) );
	}

}

int s_dynamic(int n,int k)
{
	// Dynamic Programming using only a vector of K size, best possible solution
	vector<int> vals(k,1);

	// Perform (n-k) iterations on the vector
	for (int i=0 ; i<(n-k) ; i++){

		for (int j=1 ; j<k ; j++){
			/* The element at index 'j' is equal to itself multiplited
			   by k (which is j+1) plus the element at the previous index */
			vals[j] = (j+1)*vals[j] + vals[j-1];
		}
	}

	return vals.at(k-1);
}


int b_recursive(int n)
{
	int sum = 0;

	for (int i=1 ; i<=n ; i++){
		sum += s_recursive(n,i);
	}

	return sum;
}

int b_dynamic(int n)
{
	int sum = 0;

	for (int i=1 ; i<=n ; i++){
		sum += s_dynamic(n,i);
	}

	return sum;
}


