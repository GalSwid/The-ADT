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
		delete curr;
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

void List::deleteAfter(Bridge* toDeleteAfter)
{
	if (!toDeleteAfter || !toDeleteAfter->getNext())
		return;

	Bridge* toDelete = toDeleteAfter->getNext();
	toDeleteAfter->setNext(toDelete->getNext());
	delete toDelete;
}

void List::insertAfter(Bridge* prevNode, int height)
{
	if (!prevNode)
		return;

	Bridge* newNode = new Bridge(height);
	newNode->setNext(prevNode->getNext());
	prevNode->setNext(newNode);
}

void List::insertAtBeginning(Bridge* bridge)
{
	bridge->setHeight(_head->getHeight());
	bridge->setNext(_head->getNext());
	_head = bridge;
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