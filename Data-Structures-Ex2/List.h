#pragma once
#include <iostream>
#include "Bridge.h"

using namespace std;

class List
{
private:
	Bridge* _head;

public:
	List(Bridge* head = nullptr);
	~List();
	void makeEmpty();
	bool isEmpty();

	void insertAtBeginning(float bridgeHeight);
	void printList();

	void setHead(Bridge* head) { _head = head; }
	Bridge* getHead() const { return _head; }
};
