#pragma once


#include <iostream>
#include <utility>
using namespace std;

class Road;

class MaxHeap
{
private:
	pair<int, int>* data; // point to data pair - min height and number of road
	int maxSize;
	int heapSize;
	int allocated;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	MaxHeap(int max); // allocate memory
	MaxHeap(pair<int, int> A[], int size); // turn A[] into heap
	~MaxHeap();

	pair<int, int>* Max();
	pair<int, int>* DeleteMax();
	void insert(pair<int, int>* item);
};

