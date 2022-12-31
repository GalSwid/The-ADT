#pragma once
#include <iostream>
#include <utility>

using namespace std;

#include "Road.h"

class MaxHeap
{
private:
	pair<float, int>* data; // point to data pair - min height and number of road
	int maxSize; // this is m 
	int heapSize;
	int allocated;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

public:
	MaxHeap(int max); // allocate memory
	MaxHeap(pair<float, int>* A, int size, Road* roads); // turn A[] into heap

	//pair<float, int> Max();
	//pair<float, int> DeleteMax();

	void FixHeap(int node, Road* roads);
	void insert(pair<float, int> item);
	void Swap(pair<float, int>* node, pair<float, int>* max);
	void SwapRoads(Road* node, Road* max);

};

