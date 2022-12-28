#pragma once

class Bridge
{
private:
	int _height;
	Bridge* _next;

public:
	Bridge(int height = 0, Bridge* next = nullptr);
	void setHeight(int height) { _height = height; }
	int getHeight() { return _height; }
	void setNext(Bridge* next) { _next = next; }
	Bridge* getNext() { return _next; }
};