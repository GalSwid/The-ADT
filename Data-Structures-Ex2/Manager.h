#pragma once

#include "Heap.h"
#include "Road.h"
#include <vector>

class Manager
{
private:



public:
	Manager();

	void Run();

	void Init(vector< pair<int, int>> Heap, vector<Road> roads, int numOfRoads);
	void AddBridge(float h, int r);
	int WhichRoad(float truckHeight);
	void Print(int r);
};
