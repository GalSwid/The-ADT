#pragma once

#include "Heap.h"
#include "Road.h"
#include <vector>

class Manager
{
private:
	int _numOfRoads;
	int _numOfActions;

	vector<Road> _roads;
	vector< pair<int, int>> _heap;


public:
	Manager();

	
	void getNumOfRoadsAndActions();
	
	void Run();

	void Init();
	void AddBridge(float h, int r);
	int WhichRoad(float truckHeight);
	void Print(int r);

	void getParameters(char action, float* bridgeHeight, int* road, float* truckHeight);

};
