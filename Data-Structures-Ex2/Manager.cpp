#include "Manager.h"
Manager::Manager()
{
	getNumOfRoadsAndActions();
	_roads.resize(_numOfRoads);
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
			cout << "Heighest bridge the truck can go under is: " << res << endl << endl;
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
		pair<int, int> temp;
		temp.first = 100; // key
		temp.second = i; // value
		_heapArray.push_back(temp);

		_roads[i].setListHead(NULL);
		_roads[i].setMaxHeapIndex(i);
	}
}

void Manager::AddBridge(float bridgeHeight, int roadIndex)
{
	Bridge bridge(bridgeHeight, NULL);
	MaxHeap Heap(_heapArray, _numOfRoads);

	_roads[roadIndex].setListHead(&bridge);

	// error - returns wrong index after " b 6.3 5 " input
	int index = _roads[roadIndex].getMaxHeapIndex();

	cout << "bridgeHeight: " << bridgeHeight << endl;
	cout << "index: " << index << endl;
	cout << "_heapArray[index].first: " << _heapArray[index].first;
	if (bridgeHeight < _heapArray[index].first)
	{
		pair<int, int> temp;
		temp.first = bridgeHeight; // key
		temp.second = roadIndex; // value

		_heapArray.push_back(temp);
		cout << " size: " << _heapArray.size() << endl;

		Heap.FixHeap(index);
	}
}


int Manager::WhichRoad(float truckHeight)
{
	//MaxHeap Heap(_heapArray, _numOfRoads);
	int max = _heapArray[0].first;

	if (truckHeight < max)
		return _heapArray[0].second;
	else return 0;

}


void Manager::Print(int road)
{
	_roads[road].getList().printList();
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