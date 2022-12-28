#pragma once

#include <iostream>
#include "List.h"
using namespace std;



class Road
{
private:
	int _num;
	int _MaxHeapIndex; // road index in MaxHeap array
	List _bridgesList;


public:
	Road(int num = 0);
	List getList() { return _bridgesList; }
	int getMaxHeapIndex() { return _MaxHeapIndex; }
	int getnum() { return _num; }

	void setListHead(Bridge* ptr) { _bridgesList.setHead(ptr); }
	void setMaxHeapIndex(int index) { _MaxHeapIndex = index; };
};
