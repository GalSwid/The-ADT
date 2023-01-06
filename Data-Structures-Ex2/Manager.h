#pragma once
#include "Heap.h"
#include "Road.h"

class Manager
{
private:
	MaxHeap* _heap; 
	Road* _roads; 
	int _numOfRoads;
	int _numOfActions;

public:
	void Run();
	void getNumOfRoadsAndActions();
	bool isValidInput(int inputUser, int from, int to);
	void Init();
	void AddBridge(float bridgeHeight, int roadIndex);
	void WhichRoad(float truckHeight) const;
	void Print(int road) const;
};
