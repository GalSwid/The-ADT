#include "Manager.h"

Manager::Manager()
{
	getNumOfRoadsAndActions();
	_roads = new Road[_numOfRoads];
	_heapArray = new pair<float, int>[_numOfRoads];

	// initiate global Heap 
	MaxHeap _ManagerHeap(_heapArray, _numOfRoads, _roads);
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

		try
		{
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
				cout << "Truck can go under road with index: " << res << endl << endl;
				break;
			case 'd':
				Print(road);
				break;
			default:
				throw std::invalid_argument("invalid choice");
				break;
			}
		}
		catch (const std::invalid_argument& err)
		{
			cout << "invalid_argument: " << err.what() << endl;
		}
	}
}

void Manager::Init()
{
	for (int i = 0; i < _numOfRoads; i++)
	{
		_heapArray[i].first = 100;	// min 
		_heapArray[i].second = i;	// road num

		_roads[i].getList()->setHead(NULL);
		_roads[i].setMaxHeapIndex(i);
	}
}

void Manager::AddBridge(float bridgeHeight, int roadIndex)
{
	// why create new heap every addBridge() ?
	//MaxHeap Heap(_heapArray, _numOfRoads, _roads);

	_roads[roadIndex - 1].getList()->insertDataToStartList(bridgeHeight);

	int index = _roads[roadIndex - 1].getMaxHeapIndex();
	cout << "index: " << index << endl;
	if (bridgeHeight < _heapArray[index].first)
	{
		_heapArray[index].first = bridgeHeight;
		_ManagerHeap.FixHeap(index, _roads);
	}
	else cout << endl << bridgeHeight << " is higher than " << _heapArray[index].first << endl;

	cout << "_roads: ";
	for (int i = 0; i < _numOfRoads; i++)
	{
		cout << "  " << _roads[i].getMaxHeapIndex();
	}
	cout << endl;

	cout << "_heapArray: ";
	for (int i = 0; i < _numOfRoads; i++)
		cout << " (" << _heapArray[i].first << "," << _heapArray[i].second << ")";

	cout << endl;
	cout << endl;
}


int Manager::WhichRoad(float truckHeight)
{
	float max = _heapArray[0].first;

	if (truckHeight < max)
		return _heapArray[0].second + 1;

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

