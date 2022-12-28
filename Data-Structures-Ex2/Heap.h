#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Road;

class MaxHeap
{
private:
	vector<pair<int, int>> data; // point to data pair - min height and number of road
	int maxSize; // this is m 
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

	pair<int, int> Max();
	pair<int, int> DeleteMax();

	void insert(pair<int, int> item);
	void Swap(pair<int, int> node, pair<int, int> max);
};
