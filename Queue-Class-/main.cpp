#include<iostream>
#include"Queue.h"

void printInfo()
{
	std::cout << "----QUEUE----" << std::endl;
	std::cout << "[1] ENQUEUE" << std::endl;
	std::cout << "[2] DEQUEUE" << std::endl;
	std::cout << "[3] EXIT" << std::endl;
	std::cout << "------------" << std::endl;
}

void ProcessUserInput(Queue& queue)
{
	int command{};

	while (true)
	{
		queue.Print();

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE:
			{
				int value;
				std::cout << "    > ";
				std::cin >> value;
				queue.Enqueue(value);
				break;
			}
			case DEQUEUE:
			{
				queue.Dequeue();
				break;
			}
			case EXIT:
			{
				return;
				break;
			}
			default:
				std::cout << "잘못된 명령어 입니다." << std::endl;
				break;
		}
	}
}



int main()
{
	Queue myQueue;

	printInfo();
	ProcessUserInput(myQueue);

}