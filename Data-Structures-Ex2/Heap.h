#pragma once
#include <iostream>
#include <utility>
#include "Road.h"

using namespace std;

typedef struct
{
	float minHeight;
	int roadNum;

}Pair;

class MaxHeap
{
private:
	Pair* _data; // point to pair(minHeight, roadNum)
	int _heapSize; // logical size
	int _maxSize; // physical size - number of roads
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

	friend class Manager;

public:
	MaxHeap(int max = 1); 
	void fixHeap(int node, Road* roads);
	void swap(Pair& node, Pair& max);
	void swapRoadsIndices(Road& node, Road& max);
	Pair max() { return _data[0]; }
	Pair deleteMax(Road* road);
	void insert(Pair item, Road* roads);
};

