#include "Heap.h"

MaxHeap::MaxHeap(int max)
{
	data = new pair<float, int>[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

MaxHeap::MaxHeap(pair<float, int>* A, int size, Road* roads)
{
	heapSize = maxSize = size;
	data = new pair<float, int>[size];

	data = A;
	allocated = 0;

	for (int i = size / 2 - 1; i >= 0; i--)
		FixHeap(i, roads);
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

void MaxHeap::FixHeap(int node, Road* roads)
{
	int max = node;
	int l = Left(node);
	int r = Right(node);

	/*for (int i = 0; i < 5; i++)
		cout << " data[" << i << "] = " << " (" << data[i].first << "," << data[i].second << ")" << endl;*/

	if (l < heapSize && data[l].first > data[node].first)
		max = l;

	if (r < heapSize && data[r].first > data[max].first)
		max = r;

	//cout << " node: " << node << " max: " << max << endl << endl;
	if (max != node) {
		Swap(&data[node], &data[max]);
		SwapRoadsIndices(&roads[node], &roads[max]);
		//roads[node - 1].setMaxHeapIndex(data[node - 1].second);
		//roads[max - 1].setMaxHeapIndex(data[max - 1].second);
		FixHeap(max, roads);
	}
}


void MaxHeap::Swap(pair<float, int>* node, pair<float, int>* max)
{
	pair<float, int> temp{ *node };

	*node = *max;
	*max = temp;
}

void MaxHeap::SwapRoadsIndices(Road* node, Road* max)
{
	Road temp{ *node };
	int tempIndex = temp.getMaxHeapIndex();

	node->setMaxHeapIndex(max->getMaxHeapIndex());
	max->setMaxHeapIndex(temp.getMaxHeapIndex());
}

//pair<float, int> MaxHeap::Max()
//{
//	return data[0];
//}

//pair<float, int> MaxHeap::DeleteMax()
//{
//	if (heapSize < 1) {
//		cout << "empty heap";
//		return { 0,0 };
//	}
//
//	pair<float, int> max = data[0];
//	heapSize--;
//
//	data[0] = data[heapSize];
//	FixHeap(0);
//
//	return max;
//}

void MaxHeap::insert(pair<float, int> item)
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


