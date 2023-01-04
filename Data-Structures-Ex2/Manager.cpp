#include "Manager.h"


Manager::Manager()
{
	getNumOfRoadsAndActions();
	_roads = new Road[_numOfRoads];
	_heap = new MaxHeap(_numOfRoads);
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
				throw std::invalid_argument("wrong input");
				break;
			}
		}
		catch (const std::invalid_argument& err)
		{
			cout << err.what() << endl;
		}
	}
}

void Manager::Init()
{
	for (int i = 0; i < _numOfRoads; i++)
	{
		_heap->data[i].first = 100;	// min 
		_heap->data[i].second = i;	// road num
		_heap->heapSize++;

		_roads[i].getList()->setHead(NULL);
		_roads[i].setMaxHeapIndex(i);
	}
}

void Manager::AddBridge(float bridgeHeight, int roadIndex)
{
	_roads[roadIndex - 1].getList()->insertDataToStartList(bridgeHeight); // insert 6.3 to bridge list of road 5

	int index = _roads[roadIndex - 1].getMaxHeapIndex();
	/*cout << "index: " << index << endl;
	cout << "heapIndex: " << _heap->data[index].second << endl;

	cout << "_roads: ";
	for (int i = 0; i < _numOfRoads; i++)
		cout << "  " << _roads[i].getMaxHeapIndex();

	cout << endl;*/
	if (bridgeHeight < _heap->data[_heap->data[index].second].first)
	{
		_heap->data[_heap->data[index].second].first = bridgeHeight;

		//cout << endl << "heap before: ";
		//for (int i = 0; i < _numOfRoads; i++)
		//	cout << " (" << _heap->data[i].first << "," << _heap->data[i].second << ")";
		//cout << endl;

		_heap->FixHeap(_heap->data[index].second, _roads);
	}
	//else cout << endl << bridgeHeight << " is higher than " << _heap->data[index].first << endl;


	//cout << "heap after: ";
	//for (int i = 0; i < _numOfRoads; i++)
	//	cout << " (" << _heap->data[i].first << "," << _heap->data[i].second << ")";

	//cout << endl;
	//cout << endl;
}


int Manager::WhichRoad(float truckHeight)
{
	float max = _heap->data[0].first;

	if (truckHeight < max)
		return _heap->data[0].second + 1;

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

