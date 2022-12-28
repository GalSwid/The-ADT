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
		int road;
		float truckHeight;
		float bridgeHeight;

		cin >> action;
		getParameters(action, &bridgeHeight, &road, &truckHeight);

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


void Manager::getParameters(char action, float* bridgeHeight, int* road, float* truckHeight)
{
	switch (action)
	{
	case 'b':
		cin >> *bridgeHeight;
		cin >> *road;
	case 'c':
		cin >> *truckHeight;
	case 'd':
		cin >> *road;
	default:
		break;
	}

}