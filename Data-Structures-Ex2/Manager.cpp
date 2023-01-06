#include "Manager.h"

void Manager::Run()
{
	try
	{
		getNumOfRoadsAndActions();
		_roads = new Road[_numOfRoads];
		_heap = new MaxHeap(_numOfRoads);

		for (int i = 0; i < _numOfActions; i++)
		{
			char action;
			float bridgeHeight = 0;
			int road = 0;
			float truckHeight = 0;

			cin >> action;
			if (i == 0 && action != 'a')
				throw std::invalid_argument("wrong input");
			if (i !=0 && action == 'a')
				throw std::invalid_argument("wrong input");

			switch (action)
			{
			case 'a':
				Init();
				break;
			case 'b':
				cin >> bridgeHeight >> road;
				if (!isValidInput(road, 1, _numOfRoads) || bridgeHeight <= 0)
					throw std::invalid_argument("wrong input");
				AddBridge(bridgeHeight, road);
				break;
			case 'c':
				cin >> truckHeight;
				if (truckHeight <= 0)
					throw std::invalid_argument("wrong input");
				WhichRoad(truckHeight);
				break;
			case 'd':
				cin >> road;
				if (!isValidInput(road, 1, _numOfRoads))
					throw std::invalid_argument("wrong input");
				Print(road);
				break;
			default:
				throw std::invalid_argument("wrong input");
			}
		}
	}
	catch (const std::invalid_argument& err)
	{
		cout << err.what() << endl;
		exit(1);
	}
}

void Manager::Init()
{
	for (int i = 0; i < _numOfRoads; i++)
	{
		_heap->_data[i].minHeight = FLT_MAX;	// min 
		_heap->_data[i].roadNum = i;	// road num
		_heap->_heapSize++;

		_roads[i].getList()->setHead(nullptr);
		_roads[i].setMaxHeapIndex(i);
	}
}

void Manager::AddBridge(float bridgeHeight, int roadIndex)
{
	_roads[roadIndex - 1].getList()->insertDataToStartList(bridgeHeight);

	int index = _roads[roadIndex - 1].getMaxHeapIndex();
	cout << "heapIndex: " << _heap->_data[index].roadNum + 1 << endl;
	cout << "_roads: ";
	for (int i = 0; i < _numOfRoads; i++)
		cout << "  " << _roads[i].getMaxHeapIndex() + 1;
	cout << endl;
	if (bridgeHeight < _heap->_data[_heap->_data[index].roadNum].minHeight)
	{
		_heap->_data[_heap->_data[index].roadNum].minHeight = bridgeHeight;
		cout << endl << "heap before: ";
		for (int i = 0; i < _numOfRoads; i++)
		cout << " (" << _heap->_data[i].minHeight << "," << _heap->_data[i].roadNum + 1 << ")";
		cout << endl;
		_heap->fixHeap(_heap->_data[index].roadNum, _roads);
	}
	else cout << endl << bridgeHeight << " is higher than " << _heap->_data[_heap->_data[index].roadNum].minHeight << endl;


	cout << "heap after: ";
	for (int i = 0; i < _numOfRoads; i++)
		cout << " (" << _heap->_data[i].minHeight << "," << _heap->_data[i].roadNum + 1 << ")";

	cout << endl;
	cout << endl;
}

void Manager::WhichRoad(float truckHeight) const
{
	float max = _heap->_data[0].minHeight;

	if (truckHeight < max)
		cout << _heap->_data[0].roadNum + 1 << endl;
	else
		cout << "0" << endl;
}

void Manager::Print(int road) const
{
	_roads[road - 1].getList()->printList();
}

void Manager::getNumOfRoadsAndActions()
{
	cin >> _numOfRoads;
	if (_numOfRoads <= 0)
		throw std::invalid_argument("wrong input");
	cin >> _numOfActions;
	if (_numOfActions <= 0)
		throw std::invalid_argument("wrong input");
}

bool Manager::isValidInput(int inputUser, int from, int to)
{
	return inputUser >= from && inputUser <= to;
}