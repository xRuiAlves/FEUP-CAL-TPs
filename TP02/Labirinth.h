/*
 * labirinth.h
 *
 */

#ifndef LABIRINTH_H_
#define LABIRINTH_H_

#define REACHED_GOAL 1
#define OK 0
#define OUT_OF_BOUNDS -1
#define WALL -2

#include <iostream>

typedef std::pair<int,int> place;


class Labirinth {
	int labirinth[10][10];
	bool visited[10][10];
	bool foundTheSolution = false;
	void initializeVisited();
	void searchSolution(int x, int y);
public:
	Labirinth(int values[10][10]);
	void printLabirinth();
	bool findGoal(int x, int y);
};

#endif /* LABIRINTH_H_ */
