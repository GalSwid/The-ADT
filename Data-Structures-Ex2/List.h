#pragma once
#include <iostream>
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
	bool isEmpty();

	void insertDataToStartList(float bridgeHeight);
	void insertDataToEndList(float bridgeHeight);
	void printList();

	void setHead(Bridge* head) { _head = head; }
	Bridge* getHead() const { return _head; }
};
