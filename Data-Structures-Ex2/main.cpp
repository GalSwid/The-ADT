#include "Manager.h"
#include <iostream>
using namespace std;


int main()
{
	// a
	// Init() - initiate the ATD with no bridges on the m roads
	// worst case - O(m)


	// b
	// AddBridge(float h, int r) - add bridge with height h to road r
	// worst case - O(logm)


	// c
	// WhichRoad(float truckHeight) - prints number of road for truck which it's height <= bridge's height
	// if multiple roads, prints the heighest bridge the truck can go under
	// if the truck is too high, print 0
	// worst case - teta(logm)


	// d
	// Print(int r) - prints all bridges heights on the road
	// Linear complex by num of roads
	Manager manager;
	manager.Run();

	return 0;
}