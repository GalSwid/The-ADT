#pragma once

#include <iostream>
using namespace std;

class Road
{
private:
	int num;
	int MaxHeapIndex; // road index in MaxHeap array
	List Bridge;


public:
	Road();
	~Road();

};
