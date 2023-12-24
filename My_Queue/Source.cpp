#include <iostream>
#include <algorithm>
#include "TQueue.h"
int main()
{
	TLQueue<int> q1;
	TLQueue<int> q2;
	std::cout << "Queue1 is empty?" << std::endl;
	if (q1.empty())
		std::cout << "Yes" << std::endl;
	std::cout << "Queue2 is empty?" << std::endl;
	if (q2.empty())
		std::cout << "Yes" << std::endl;
	std::cout << "Push in Queue1: 1,2,3;" << std::endl;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);

	std::cout << "Queue1:"<<std::endl;
	q1.output();
	std::cout << "Push in Queue2: 4,5,6;" << std::endl;
	q2.Push(4);
	q2.Push(5);
	q2.Push(6);
	std::cout << "Queue2:" << std::endl;
	q2.output();
	bool tmp1=0,tmp2=0 ;
	tmp1 = q1 == q2;
	tmp2 = q1 != q2;
	std::cout << "q1 == q2=" << tmp1 << std::endl;
	std::cout << "q1 != q2=" << tmp2 << std::endl;
	std::cout << "Next:q1=q2;"<<std::endl;
	q1 = q2;
	std::cout << "Queue1:" << std::endl;
	q1.output();
	std::cout << "Queue2:" << std::endl;
	q2.output();
	std::cout << "Next:Pop from Queue1 2 times" << std::endl;
	q1.Pop();
	q1.Pop();
	std::cout << "Queue1:" << std::endl;
	q1.output();
	std::cout << "Next:Pop from Queue2 3 times" << std::endl;
	q2.Pop();
	q2.Pop();
	q2.Pop();
	std::cout << "Queue2:" << std::endl;
	q2.output();
}