#pragma once

class Bridge
{
private:
	float _height;
	Bridge* _next;

public:
	Bridge(float height = 0, Bridge* next = nullptr);
	void setHeight(int height) { _height = height; }
	int getHeight() { return _height; }
	void setNext(Bridge* next) { _next = next; }
	Bridge* getNext() { return _next; }
};