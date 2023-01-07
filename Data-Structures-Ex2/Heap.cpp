#include "Heap.h"

MaxHeap::MaxHeap(int max)
{
	_data = new Pair[max];
	_maxSize = max;
	_heapSize = 0;
}

int MaxHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int MaxHeap::Left(int node)
{
	return (2 * node + 1);
}

int MaxHeap::Right(int node)
{
	return (2 * node + 2);
}

void MaxHeap::fixHeap(int node, Road* roads)
{
	int max;
	int l = Left(node);
	int r = Right(node);

	if (l < _heapSize && _data[l].minHeight > _data[node].minHeight)
		max = l;
	else max = node;
	if (r < _heapSize && _data[r].minHeight > _data[max].minHeight)
		max = r;

	if (max != node) 
	{
		swapRoadsIndices(roads[_data[node].roadNum], roads[_data[max].roadNum]);
		swap(_data[node], _data[max]);
		fixHeap(max, roads);
	}
}

void MaxHeap::swap(Pair& node, Pair& max)
{
	Pair temp;
	temp = node;
	node = max;
	max = temp;
}

void MaxHeap::swapRoadsIndices(Road& node, Road& max)
{
	Road temp; 
	temp.setMaxHeapIndex(node.getMaxHeapIndex());
	node.setMaxHeapIndex(max.getMaxHeapIndex());
	max.setMaxHeapIndex(temp.getMaxHeapIndex());
}

Pair MaxHeap::deleteMax(Road* road)
{
	if (_heapSize == _maxSize)
	{
		cout << "heap is empty" << endl;
		exit(1);
	}
	Pair max = _data[0];
	_heapSize--;
	_data[0] = _data[_heapSize];
	fixHeap(0, road);
	return max;
}

void MaxHeap::insert(Pair item, Road* road)
{
	if (_heapSize == _maxSize)
	{
		cout << "heap is full" << endl;
		exit(1);
	}

	int i = _heapSize;
	_heapSize++;

	while ((i > 0) && _data[Parent(i)].minHeight < item.minHeight)
	{
		_data[i] = _data[Parent(i)];
		i = Parent(i);
	}

	_data[i] = item;
}


