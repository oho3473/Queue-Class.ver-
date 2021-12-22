#pragma once
#include<iostream>

class Queue
{
public:
	struct Element
	{
		int value;
		Element* pNext;
	};

	int mCount;
	Element* mFront;
	Element* mRear;

public:
	Queue();
	~Queue();

	void Enqueue(int value);
	bool Dequeue();
	void Print() const;
};


enum Command
	{
		ENQUEUE = 1,
		DEQUEUE = 2,
		EXIT = 3
	};

void Initialize(Queue& queue);
void ClearAll(Queue& queue);





