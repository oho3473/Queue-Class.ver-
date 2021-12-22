#include<iostream>
#include "Queue.h"

Queue::Queue() : mCount{0}, mFront{nullptr}, mRear{nullptr}
{
}

Queue::~Queue()
{
	Element* element = mFront;
	Element* next = nullptr;

	while (element != nullptr)
	{
		next = element->pNext;
		delete element;
		element = next;
	}

}

void Queue::Enqueue(int value)
{
	Element* pElement = new Element{ value, nullptr };

	if (mFront == nullptr && mRear == nullptr)
	{
		mFront = pElement;
		mRear = pElement;
	}
	else
	{
		mRear->pNext = pElement;
		mRear = pElement;
	}

	mCount++;
}

bool Queue::Dequeue()
{
	if (mCount == 0)
	{
		std::cout << "QUEUE is empty!" << std::endl;
		return false;
	}

	Element* pTemp = mFront;
	
	std::cout << "DEQUEUE : " << pTemp->value << std::endl;

	mFront = pTemp->pNext;
	delete pTemp;
	mCount--;
	
	if (mCount == 0)
	{
		mCount = 0;
		mFront = mRear = nullptr;
	}

	return true;

}

void Queue::Print() const
{
	Element* pElement = mFront;

	while (pElement != nullptr)
	{
		std::cout << pElement->value << std::endl;
		pElement = pElement->pNext;
	}
}
