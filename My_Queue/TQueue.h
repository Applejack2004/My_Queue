#pragma once
#include <iostream>
#include <algorithm>
template <class T>
class TQueue
{
	T* pMem;
	int size, start, finish, count;
public:
TQueue(int _size)
{
		if (_size <= 0)
		{
			throw "erroR";
		}
		size = _size;
		pMem = new T[size];
		count = 0;
		start = 0;
		finish = -1;
}
TQueue(const TQueue& s)
{
	size = s.size;
	count = s.count;
	start = s.start;
	finish = s.finish;
	delete[]pMem;
	pMem = new T[size];
	std::copy(s.pMem, s.pMem + size, pMem);


}
~TQueue()
{
	delete[] pMem;
}
bool operator==(const TQueue& s) const
{
	if (count != s.count)
	{
		return false;
	}
	int i = 0;
	while (i <= finish)
	{
		i = i % size;
		if (pMem[i] != s.pMem[i]) return false;

	}	
	return true;
}
bool operator!=(const TQueue& s) const
{
	return !(*this == s);

}
	int Get_count()
	{
		return count;
	}
	bool Empty()
	{
		return count == 0;
	}
	bool Full()
	{
		return count == size;
	}
	void Push(const T& el)
	{
		if (Full() == 1)
		{
			throw "error";
		}
		finish++;
		finish = finish % size;
		pMem[finish] = el;
		count++;
	}
	T Pop()
	{
		if (Empty())
		{
			throw "Error";
		}
		T el = pMem[start];
		start++;
		count--;
		start = start % size;
		return el;


	}
	TQueue& operator = (const TQueue& q)
	{
		if (*this == q)
		{
			return *this;
		}
		delete[] pMem;
		size = q.size;
		count = q.count;
		start = q.start;
		pMem = new T[size ];
		std::copy(q.pMem, q.pMem + size, pMem);
		return *this;

	}
	T front()
	{
		if (Empty())
		{
			throw "Error";
		}
		T el = pMem[start];
		return el;
	}
	T back()
	{
		if (Empty())
		{
			throw "Error";
		}
		T el = pMem[finish];
		return el;
	}
};

