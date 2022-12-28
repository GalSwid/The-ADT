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
	vector<pair<int, int>> _heapArray;


public:
	Manager();
	void Run();
	void getNumOfRoadsAndActions();
	void getParameters(char action, float* bridgeHeight, int* road, float* truckHeight);

	void Init();
	void AddBridge(float bridgeHeight, int roadIndex);
	int WhichRoad(float truckHeight);
	void Print(int road);


};
