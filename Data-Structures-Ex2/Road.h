#pragma once
#include "List.h"

class Road
{
private:
	int _maxHeapIndex; // road index in MaxHeap array
	List* _bridgesList;

public:
	Road();
	void setMaxHeapIndex(int maxHeapIndex) { _maxHeapIndex = maxHeapIndex; };
	int getMaxHeapIndex() const { return _maxHeapIndex; }
	List* getList() const { return _bridgesList; }
};
