#include "Heap.h"

MaxHeap::MaxHeap(int max)
{
	data = new pair<int, int>[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

MaxHeap::MaxHeap(pair<int, int> A[], int size)
{
	heapSize = maxSize = size;

	data = A;
	allocated = 0;

	for (int i = size / 2 - 1; i >= 0; i--)
		FixHeap(i);
}

int MaxHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int MaxHeap::Left(int node)
{
	return 2 * node + 1;
}

int MaxHeap::Right(int node)
{
	return 2 * node + 2;
}

void MaxHeap::FixHeap(int node)
{
	int max = node;
	int l = Left(node);
	int r = Right(node);

	// find max among node. left and right.
	if (l < heapSize && data[l].first > data[node].first)
		max = l;

	if (r < heapSize && data[r].first > data[max].first)
		max = r;

	if (max != node) {
		Swap(data[node], data[max]);
		FixHeap(max);
	}
}

void MaxHeap::Swap(pair<int, int> node, pair<int, int> max)
{
	pair<int, int> temp;
	temp = node;
	node = max;
	max = temp;
}

pair<int, int> MaxHeap::Max()
{
	return data[0];
}

pair<int, int> MaxHeap::DeleteMax()
{
	if (heapSize < 1) {
		cout << "empty heap";
		return;
	}

	pair<int, int> max = data[0];
	heapSize--;

	data[0] = data[heapSize];
	FixHeap(0);

	return max;
}

void MaxHeap::insert(pair<int, int> item)
{
	if (heapSize == maxSize)
	{
		cout << "heap is full" << endl;
		return;
	}

	int i = heapSize;
	heapSize++;

	while ((i > 0) && data[Parent(i)].first < item.first)
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	data[i] = item;
}


MaxHeap::~MaxHeap()
{
	if (allocated)
		delete[] data;
	data = NULL;
}