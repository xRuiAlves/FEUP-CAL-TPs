/*
 * labirinth.cpp
 */

#include "Labirinth.h"

using namespace std;



Labirinth::Labirinth(int values[10][10]){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			labirinth[i][j]=values[i][j];
		}
	}
}


void Labirinth::initializeVisited() {
	for (int i = 0; i < 10; i++)
		for (int a = 0; a < 10; a++)
			visited[i][a] = false;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
			cout << labirinth[i][a] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y){
	initializeVisited();
	searchSolution(x,y);

	return foundTheSolution;
}

void Labirinth::searchSolution(int x, int y){
	// Check if solution already found
	if(foundTheSolution) {
		return;
	}

	// Check if visited
	if(visited[x][y]) {
		return;
	}
	else {
		visited[x][y] = true;
	}

	// Out of Bounds
	if(x<0 || x>=10 || y<0 || y>=10) {
		return;
	}

	// Inside Wall
	if(labirinth[x][y] == 0) {
		return;
	}

	// Found Goal
	if(labirinth[x][y] == 2) {
		foundTheSolution = true;
		return;
	}

	// Regular labirinth piece
	searchSolution(x+1 , y);
	searchSolution(x-1 , y);
	searchSolution(x , y+1);
	searchSolution(x , y-1);
}




