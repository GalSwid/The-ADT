#include "List.h"

List::List(Bridge* head, Bridge* tail)
{
	_head = head;
	_tail = tail;
}



void List::makeEmpty()
{
	_head = nullptr;
}

bool List::isEmpty()
{
	return _head == nullptr;
}


void List::insertDataToStartList(float bridgeHeight)
{
	Bridge* bridge = new Bridge(bridgeHeight, NULL);

	if (_head == NULL)
		this->setHead(bridge);
	else {
		bridge->setNext(_head);
		_head = bridge;
	}
}

void List::insertDataToEndList(float bridgeHeight)
{
	Bridge* bridge = new Bridge(bridgeHeight, nullptr);
	//Insert data to the end of the list
	if (isEmpty())
		_tail = _head = bridge;

	else
	{
		_tail->setNext(bridge);
		_tail = bridge;
	}
}

void List::printList()
{
	Bridge* curr = _head;

	if (isEmpty()) {
		cout << "List empty" << endl;
		return;
	}

	cout << "List: ";
	while (curr != nullptr) {
		cout << curr->getHeight() << " ";
		curr = curr->getNext();
	}
	cout << endl << endl;

}

List::~List()
{
	Bridge* curr = _head;

	while (curr != nullptr)
	{
		Bridge* next = curr->getNext();
		//delete[] curr;
		curr = next;
	}
}