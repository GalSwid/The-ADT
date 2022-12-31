#include "List.h"

List::List(Bridge* head)
{
	_head = head;
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

void List::makeEmpty()
{
	_head = nullptr;
}

bool List::isEmpty()
{
	return _head == nullptr;
}


void List::insertAtBeginning(float bridgeHeight)
{
	Bridge* bridge = new Bridge(bridgeHeight, NULL);
	if (_head == NULL)
		this->setHead(bridge);
	else {
		bridge->setNext(_head);
		_head = bridge;
	}
}


void List::printList()
{
	Bridge* curr = _head;

	if (isEmpty()) {
		cout << "List empty" << endl;
		return;
	}

	while (curr != nullptr) {
		cout << curr->getHeight() << " ";
		curr = curr->getNext();
	}
}


