#pragma once
#include "Heap.h"
#include "Road.h"

class Manager
{
private:
	int _numOfRoads;
	int _numOfActions;

	MaxHeap* _heap; // error: send params?
	Road* _roads; // error: change to Road** ?
	pair<float, int>* _heapArray;

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
