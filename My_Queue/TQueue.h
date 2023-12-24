#pragma once
#include <iostream>
#include <algorithm>
template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};

template <class T>
class TLQueue
{
private:
	TNode<T>* pFirst, * pLast;

public:
	TLQueue() { pFirst = nullptr; pLast = nullptr; }; //����������� �� ���������
	~TLQueue() { ClearQueue(); }; //����������
	TLQueue(const TLQueue<T>& queue_object); //����������� �����������

	TLQueue<T>& operator=(const TLQueue<T>& queue_object); //�������� ������������
	bool operator==(const TLQueue<T>& queue_object); //�������� ���������
	bool operator != (const TLQueue<T>& queue_object); //�������� ��������� ���������

	bool empty(); //�������� �� �������
	void Push(const T& element); //������� ��������� � �����
	T Pop(); //�������� �������� �� ������ ������� � ��� ���������
	T Front(); //�������� �������� �� ������ ������� ��� ��� ���������
	T Back(); //�������� �������� � ����� �������
	int ElementsNumber(); //���������� ��������� � �������
	void ClearQueue(); //�������� �������
	void output(); //������� ������� �� �����
	bool Full()
	{
		TNode<T>*p = new TNode<T>;
		bool res = p == nullptr;
		delete p;
		return res;

	}
};

template<class T>
inline TLQueue<T>::TLQueue(const TLQueue<T>& queue_object)
{
	TNode<T>* tmp = queue_object.pFirst, * curr;
	pFirst = pLast = nullptr;
	while (tmp != nullptr)
	{
		curr = new TNode<T>;
		curr->value = tmp->value;
		if (pFirst == nullptr)
		{
			pFirst = curr;
			pLast = curr;
		}
		else
		{
			pLast->pNext = curr;
			pLast = curr;
		}
		tmp = tmp->pNext;
	}
}

template<class T>
inline  TLQueue<T>& TLQueue<T>::operator=(const TLQueue<T>& queue_object)
{
	if (queue_object.pFirst == nullptr)
	{
		ClearQueue();
	}
	else
	{
		ClearQueue();
		TNode<T>* tmp = queue_object.pFirst, * current;
		while (tmp != nullptr)
		{
			current = new TNode<T>;
			current->value = tmp->value;
			if (pFirst == nullptr)
			{
				pFirst = current;
				pLast = current;
			}
			else
			{
				pLast->pNext = current;
				pLast = current;
			}
			tmp = tmp->pNext;
		}
	}
	return *this;
}

template<class T>
inline bool TLQueue<T>::operator==(const TLQueue<T>& q)
{
	TNode<T>* pRight = q.pFirst, * pLeft = pFirst;
		while (pRight != nullptr || pLeft != nullptr) {
			if (pRight->value != pLeft->value) {
				return false;
			}
			pRight = pRight->pNext;
			pLeft = pLeft->pNext;
		}
		if ((pRight == nullptr && pLeft != nullptr)
			|| (pLeft == nullptr && pRight != nullptr)) {
			return false;
		}
		return true;
	
}

template<class T>
inline bool TLQueue<T>::operator!=(const TLQueue<T>& queue_object)
{
	return !(*this == queue_object);
}

template<class T>
inline bool TLQueue<T>::empty()
{
	return (pFirst == nullptr);
	
}


template<class T>
inline T TLQueue<T>::Pop()
{
	if (empty())
	{
		throw "Queue is empty, you can't pop";
	}

	TNode<T>* tmp = pFirst;
	T result = pFirst->value;
	pFirst = pFirst->pNext;
	delete tmp;
	return result;
}

template<class T>
inline void TLQueue<T>::Push(const T& element)
{
	TNode<T>* tmp = new TNode<T>;
	tmp->value = element;
	tmp->pNext = nullptr;
	if (empty())
	{
		pFirst = tmp;
		pLast = tmp;
	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
	}
}

template<class T>
inline T TLQueue<T>::Front()
{
	if (empty())
	{
		throw "Queue is empty, you can't get front";
	}
	return pFirst->value;
}

template<class T>
inline T TLQueue<T>::Back()
{
	if (empty())
	{
		throw "Queue is empty, you can't get back";
	}
	return pLast->value;
}

template<class T>
inline int TLQueue<T>::ElementsNumber()
{
	TNode<T>* tmp = pFirst;
	int i = 0;
	while (tmp != nullptr)
	{
		i++;
		tmp = tmp->pNext;
	}
	return i;
}

template<class T>
inline void TLQueue<T>::ClearQueue()
{
	while (!empty())
	{
		Pop();
	}
	//�� ������ ������
	pFirst = nullptr;
	pLast = nullptr;
}

template<class T>
inline void TLQueue<T>::output()
{
	if (empty())
	{
		std::cout << "(empty)";
	}
	else
	{
		TLQueue<T> current_queue(*this);
		std::cout << "( ";
		while (!current_queue.empty())
		{
			std::cout << current_queue.Pop() << " ";
		}
		std::cout << ")" << std::endl;
	}
}
