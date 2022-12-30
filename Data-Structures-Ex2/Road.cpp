#include "Road.h"

Road::Road(int num)
{
	_num = num;
	_bridgesList.makeEmpty();
	_MaxHeapIndex = 0;
}

