#include "List.h"

List::List(Bridge* head, Bridge* tail)
{
	_head = head;
	_tail = tail;
}

List::~List()
{
	Bridge* curr = _head;

	while (curr != nullptr)
	{
		Bridge* next = curr->getNext();
		delete[] curr;
		curr = next;
	}
}

void List::makeEmpty()
{
	_head = _tail = nullptr;
}

bool List::isEmpty() const
{
	return _head == nullptr;
}

void List::insertDataToStartList(float bridgeHeight)
{
	Bridge* bridge = new Bridge(bridgeHeight, nullptr);

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
	
	if (isEmpty())
		_tail = _head = bridge;
	else
	{
		_tail->setNext(bridge);
		_tail = bridge;
	}
}

void List::insertDataToSortedList(float bridgeHeight)
{
	Bridge* newNode = new Bridge(bridgeHeight, nullptr);

	if (_head == nullptr || _head->getHeight() <= newNode->getHeight()) 
	{
		newNode->setNext(_head);
		_head = newNode;
	}
	else 
	{
		Bridge* curr = _head;
		while (curr->getNext() != nullptr && curr->getNext()->getHeight() > newNode->getHeight())
		{
			curr = curr->getNext();
		}
		newNode->setNext(curr->getNext());
		curr->setNext(newNode);
	}
}

void List::printList() const
{
	Bridge* curr = _head;

	if (isEmpty()) 
	{
		cout << "Empty List" << endl;
		return;
	}

	while (curr != nullptr) 
	{
		cout << std::fixed << std::setprecision(4) << curr->getHeight() << " ";
		curr = curr->getNext();
	}
	cout << endl;
}