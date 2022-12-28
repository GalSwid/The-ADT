#include "Manager.h"



Manager::Manager()
{

}



void Manager::Run()
{
	char choice = getInput();

	int numOfRoads;
	int numOfActions;
	int height;
	int truckHeight;

	Road road;

	switch (choice)
	{
	case 'a':
		Init();
	case 'b':
		AddBridge(height, road);
	case 'c':
		int res = WhichRoad(truckHeight);
	case 'd':
		Print(r);
	default:
		break;
	}
}


void Manager::Init(vector< pair<int, int>> Heap, vector<Road> roads, int numOfRoads)
{
	for (int i = 0; i < numOfRoads; i++)
	{
		Heap[i].second = i;
		Heap[i].first = 1000000;

		roads[i].setListHead(NULL);
		roads[i].setMaxHeapIndex(i)‏;
	}
}