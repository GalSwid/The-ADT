#include "Manager.h"



Manager::Manager()
{

}



void Manager::Run()
{

	getNumOfRoadsAndActions();

	for (int i = 0; i < _numOfActions; i++)
	{
		char action;
		int truckHeight;
		int bridgeHeight;
		int road;

		cin >> action;
		getParameters(action);

		switch (action)
		{
		case 'a':
			Init();
		case 'b':
			AddBridge(bridgeHeight, road);
		case 'c':
			int res = WhichRoad(truckHeight);
		case 'd':
			Print(r);
		default:
			break;
		}
	}
}


void Manager::Init()
{
	for (int i = 0; i < _numOfRoads; i++)
	{
		_heap[i].first = 1000000; // key
		_heap[i].second = i; // value

		_roads[i].setListHead(NULL);
		_roads[i].setMaxHeapIndex(i)‏;
	}
}

void Manager::AddBridge(float bridgeHeight, int roadIndex)
{
	// add birdgeHeight to roads[roadIndex].list.setHead


}


void getParameters(char action)
{
	switch (action)
	{
	default:
		break;
	}

}