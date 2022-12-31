#include "Manager.h"

Manager::Manager()
{
	getNumOfRoadsAndActions();
	_roads = new Road[_numOfRoads];
	_heapArray = new pair<float, int>[_numOfRoads];
}

void Manager::Run()
{

	for (int i = 0; i < _numOfActions; i++)
	{
		char action;
		int res;
		float bridgeHeight = 0;
		int road = 0;
		float truckHeight = 0;

		cin >> action;
		getParameters(action, &bridgeHeight, &road, &truckHeight);


		switch (action)
		{
		case 'a':
			Init();
			break;
		case 'b':
			AddBridge(bridgeHeight, road);
			break;
		case 'c':
			res = WhichRoad(truckHeight);
			cout << "Heighest road the truck can go under is road index: " << res + 1 << endl << endl;
			break;
		case 'd':
			Print(road);
			break;
		default:
			break;
		}
	}
}

void Manager::Init()
{
	for (int i = 0; i < _numOfRoads; i++)
	{
		pair<float, int> temp;
		temp.first = 100; // key
		temp.second = i; // value
		_heapArray[i] = temp;

		_roads[i].getList()->setHead(NULL);
		_roads[i].setMaxHeapIndex(i);
	}
}

void Manager::AddBridge(float bridgeHeight, int roadIndex)
{
	MaxHeap Heap(_heapArray, _numOfRoads);

	_roads[roadIndex - 1].getList()->insertAtBeginning(bridgeHeight);

	int index = _roads[roadIndex - 1].getMaxHeapIndex();

	if (bridgeHeight < _heapArray[index].first)
	{
		pair<float, int> temp;
		temp.first = bridgeHeight; // key
		temp.second = roadIndex - 1; // value

		_heapArray[index] = temp;

		Heap.FixHeap(index);
	}
}


int Manager::WhichRoad(float truckHeight)
{
	int max = _heapArray[0].first;

	if (truckHeight < max)
		return _heapArray[0].second;
	else return 0;
}


void Manager::Print(int road)
{
	_roads[road - 1].getList()->printList();
}




void Manager::getNumOfRoadsAndActions()
{
	cin >> _numOfRoads;
	cin >> _numOfActions;
}

void Manager::getParameters(char action, float* bridgeHeight, int* road, float* truckHeight)
{
	switch (action)
	{
	case 'b':
		cin >> *bridgeHeight;
		cin >> *road;
		break;
	case 'c':
		cin >> *truckHeight;
		break;
	case 'd':
		cin >> *road;
		break;
	default:
		break;
	}
}