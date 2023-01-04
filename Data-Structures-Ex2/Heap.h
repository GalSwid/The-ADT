#pragma once
#include <iostream>
#include <utility>

using namespace std;

#include "Road.h"

class MaxHeap
{
private:
	int heapSize;
	int maxSize; // this is m 
	int allocated;
	pair<float, int>* data; // point to data pair - min height and number of road

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

	friend class Manager;

public:
	MaxHeap(int max = 1); // allocate memory
	MaxHeap(pair<float, int>* A, int size, Road* roads); // turn A[] into heap

	//pair<float, int> Max();
	//pair<float, int> DeleteMax();

	void FixHeap(int node, Road* roads);
	void insert(pair<float, int> item, Road* roads);
	void Swap(pair<float, int>* node, pair<float, int>* max);
	void SwapRoadsIndices(Road* node, Road* max);

};

