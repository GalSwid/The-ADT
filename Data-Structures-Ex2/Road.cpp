#include "Road.h"

Road::Road(int num)
{
	_num = num;
	_bridgesList = new List();
	_MaxHeapIndex = 0;
}



