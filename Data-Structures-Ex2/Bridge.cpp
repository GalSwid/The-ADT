#include "Bridge.h"

Bridge::Bridge(float height, Bridge* next)
{
	_height = height;
	_next = next;
}