# Data Structure Assignment
This project finds the best route for a truck to travel between city A and city B, 
given m parallel roads that connect the two cities. 
The roads do not intersect, and bridges may be built on the roads at any time. 
The number of bridges that can be built on each road is unlimited, and the height of any bridge can be any positive real number.

![צילום מסך 2023-01-04 224521](https://user-images.githubusercontent.com/82842819/210647907-611a78af-dd37-42fd-944d-28a0226334a8.png)

## Getting Started

You will need a C++ compiler to build and run this project.

## Installing

Clone the repository to your local machine:

git clone https://github.com/galswid/The-ADT.git

## Instructions

Insert line by line:
1. Number of roads (suppose that number of roads is 2)
2. Number of actions (suppose that number of actions is 2)

Now the first action must be "Init" - one and only.
After that, continue to insert actions, for example:

3. a 
4. b 2.5 1

Then press enter to continue..

Note: Init - a, AddBridge(float, int) - b, WhichRoad(float) - c, Print(int) - d

## Initiate
- The efficiency of the operation is O(m) in the worst case.
- // m == number of roads 

```cpp
void Init()
{
	for (int i = 0; i < _numOfRoads; i++)
	{
		_heap->_data[i].minHeight = INT8_MAX;	// min 
		_heap->_data[i].roadNum = i;	// road num
		_heap->_heapSize++;
		_roads[i].getList()->setHead(nullptr);
		_roads[i].setMaxHeapIndex(i);
	}
}
```

- This code initializes the data structures used in the project. 
- It sets the minimum value of _heap to 100, sets the road number to i, and increments the heap size. 
- It also sets the head of the list for each road to NULL and sets the maximum heap index for each road to i.

## Add New Bridge
- The efficiency of the operation is O(log m) in the worst case.
- // m == number of roads 

```cpp
void AddBridge(float bridgeHeight, int roadIndex)
{
	_roads[roadIndex - 1].getList()->insertDataToEndList(bridgeHeight); 
	int index = _roads[roadIndex - 1].getMaxHeapIndex(); 
	
	if (bridgeHeight < _heap->_data[index].minHeight)
	{
		_heap->_data[index].minHeight = bridgeHeight;
		_heap->fixHeap(index, _roads);
	}
}
```

- This code adds a new bridge to the specified road and updates the minimum height value in the heap data structure if necessary. 
- It inserts the new bridge height to the start of the list for the specified road and retrieves the maximum heap index for that road. 
- If the new bridge height is less than the minimum value in the heap, it updates the minimum value and calls the FixHeap function to update the heap.

## The Best Road
- The efficiency of the operation is O(1) in the worst case.

```cpp
int WhichRoad(float truckHeight)
{
	float max = _heap->_data[0].minHeight;

	if (truckHeight < max)
		cout << _heap->_data[0].roadNum + 1 << endl;
	else
		cout << "0" << endl;
}
```

- This code determines the best road for a truck to take given the truck's height. 
- It retrieves the minimum value in the heap data structure and checks if the truck's height is less than this value. 
- If it is, it returns the road number (which is the second value in the heap data structure) plus 1. 
- If the truck's height is not less than the minimum value in the heap, it returns 0.

##### Made by [Gal Swid](https://github.com/GalSwid) & [Ori Nurieli](https://github.com/orinurieli)  
