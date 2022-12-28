#include "Bridge.h"

Bridge::Bridge(int height, Bridge* next)
{
	_height = height;
	_next = next;
}