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


static int Parent(int node)
{
	return (node - 1) / 2;
}

static int Left(int node)
{
	return 2 * node + 1;
}

static int Right(int node)
{
	return 2 * node + 2;
}

void FixHeap(int node)
{
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	if (l < heapSize && heap[l] > heap[i])
		largest = l;
	if (r < heapSize && heap[r] > heap[largest])
		largest = r;
	if (largest != i) {
		swap(heap[i], heap[largest]);
		FixHeap()
	}
}


pair<int, int>* Max();
pair<int, int>* DeleteMax();
void insert(pair<int, int>* item);


MaxHeap::~MaxHeap()
{
	if (allocated)
		delete[] data;
	data = NULL;
}