#pragma once
#include <iostream>
#include <iomanip>
#include "Bridge.h"

using namespace std;

class List
{
private:
	Bridge* _head;
	Bridge* _tail;

public:
	List(Bridge* head = nullptr, Bridge* tail = nullptr);
	~List();
	void makeEmpty();
	bool isEmpty() const;
	void insertDataToStartList(float bridgeHeight);
	void insertDataToEndList(float bridgeHeight);
	void insertDataToSortedList(float bridgeHeight);
	void printList() const;
	void setHead(Bridge* head) { _head = head; }
	Bridge* getHead() const { return _head; }
	void setTail(Bridge* tail) { _tail = tail; }
	Bridge* getTail() const { return _tail; }
};
