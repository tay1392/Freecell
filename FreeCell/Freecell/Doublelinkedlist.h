/************************************************************************
* Class: DoubleLinkedList
*
* Constructors:	
*	DoubleLinkedList() 
*		default / no arg
*	DoubleLinkedList(const DoubleLinkedList & obj)
*		copy ctor
*
* Mutators:
*	none
*
* Methods:		
*	DoubleLinkedList & operator=(const DoubleLinkedList & rhs)
*		assignment operator
*	~DoubleLinkedList()
*		dtor
*	bool IsEmpty()
*		checks if linked list is empty
*	Node<T> * getHead()
*		returns Head Node
*	Node<T> * getTail()
*		returns Tail Node
*	T & First() const;
*		returns data in head
*	T & Last() const;
*		returns data in tail
*	void Append(T data)
*		Adds a node to the end list
*	void Prepend(T data)
*		Adds a node Before the head
*	void Purge()
*		deallocates all memory nodes
*	void Extract(T position)
*		Deletes a Node at given position
*	void InsertBefore(T data, T position)
*		Inserts a Node Before a position
*	void InsertAfter(T data, T position)
*		Inserts a Node after a position
*	void PrintForwards();
*		displays list contents forward 
*	void PrintBackwards()
*		Displays list contents backwards
*************************************************************************/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
template <typename T>
class Node;

template <typename T>
class LinkStack;

template <typename T>
class DoubleLinkedList
{
	friend class LinkStack<T>;
	friend class PlayCells;

	public:
		//Canonical Methods
		DoubleLinkedList();
		DoubleLinkedList(const DoubleLinkedList & obj);
		DoubleLinkedList & operator=(const DoubleLinkedList & rhs);
		~DoubleLinkedList();
		//Mutators/Accessors
		bool IsEmpty();
		Node<T> * getHead();
		Node<T> * getTail();
		T & First() const;
		T & Last() const;
		void Append(T data);
		void Prepend(T data);
		void Purge();
		void Extract(T position);
		void InsertBefore(T data, T position);
		void InsertAfter(T data, T position);
		void PrintForwards();
		void PrintBackwards();
	private:
		int current;
	    int NumNodes;
		Node<T> * m_Head;
		Node<T> * m_Tail;
};

#include <iostream>
using std::cout;
using std::cin;

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
	:m_Head(nullptr), m_Tail(nullptr),
	NumNodes(0), current(0)
{
	/*cout << "1 arg . " << endl;*/
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList & obj)
	:NumNodes(obj.NumNodes), current(obj.current)
{
	if(NumNodes > 0)
	{
		Node<T> * temp = obj.m_Head;
		int i = 0;
		while(temp != nullptr)
		{
			if(i == 0)
			{
				Node<T> * NN = new Node<T>(temp->m_Data);
				m_Head = NN;
				m_Tail = NN;

				NN->m_Next = nullptr;
				NN->m_Previous = nullptr;
			}
			else
			{
				Node<T> * NN = new Node<T>(temp->m_Data);
				m_Tail->m_Next = NN;
				NN->m_Previous = m_Tail;
				m_Tail  = NN;
				NN->m_Next = nullptr;
			}
			temp = temp->m_Next;
			i++;
		}
	}
}

template <typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList & rhs)
{
	if(this != &rhs)
	{
		Node<T> * travel = rhs.m_Head;
		if(IsEmpty() == true)
		{
			while(travel != nullptr)
			{
				Append(travel->m_Data);
				travel = travel->m_Next;
			}
		}
		else
		{
			Purge();
			while(travel != nullptr)
			{
				Append(travel->m_Data);
				travel = travel->m_Next;
			}
		}
	}
	else
	{
		cout << "Error: Self Assignment." << endl;
	}
	NumNodes = rhs.NumNodes;
	return * this;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	if(NumNodes > 0)
	{
		Purge();
	}
	/*cout << "Dtor" << endl;*/
}

template <typename T>
void DoubleLinkedList<T>::PrintForwards()
{
	Node<T> * travel = m_Head;
	while(travel!= nullptr)
	{
		cout << travel->m_Data << " ";
		travel = travel->m_Next;
	}
	cout << endl;
}

template <typename T>
void DoubleLinkedList<T>::PrintBackwards()
{
	Node<T> * travel = m_Tail;
	while(travel!= nullptr)
	{
		cout << travel->m_Data << " ";
		travel = travel->m_Previous;
	}
}

template <typename T>
void DoubleLinkedList<T>::Append(T x)
{
	if(NumNodes == 0)
	{
		Node<T> * NN = new Node<T>(x);
		m_Head = NN;
		m_Tail = NN;

		NN->m_Next = nullptr;
		NN->m_Previous = nullptr;
		NumNodes++;
	}
	else
	{
		Node<T> * NN = new Node<T>(x);
		m_Tail->m_Next = NN;
		NN->m_Previous = m_Tail;
		m_Tail  = NN;
		NN->m_Next = nullptr;
		NumNodes++;
	}
}

template <typename T>
void DoubleLinkedList<T>::Prepend(T x)
{
	if(NumNodes == 0)
	{
		Node<T> * NN = new Node<T>(x);
		m_Head = NN;
		m_Tail = NN;
		NN->m_Next = nullptr;
		NN->m_Previous = nullptr;
		NumNodes++;
	}
	else
	{
		Node<T> * NN = new Node<T>(x);
		NN->m_Next = m_Head;
		m_Head->m_Previous = NN;
		m_Head = NN;
		NN->m_Previous = nullptr;
		NumNodes++;
	}
}

template <typename T>
void DoubleLinkedList<T>::Purge()
{
		Node<T> * trail;
		while(m_Head != nullptr)
		{
			trail = m_Head;
			m_Head = m_Head->m_Next;
			delete trail;
		}

		m_Head = nullptr;
		m_Tail = nullptr;
		NumNodes = 0;
}

template <typename T>
T & DoubleLinkedList<T>::First() const 
{
	if(NumNodes > 0)
	{
		return m_Head->m_Data;
	}
	else
	{
		throw("NO DATA");
	}
}

template <typename T>
T & DoubleLinkedList<T>::Last() const 
{
	if(NumNodes > 0)
	{
		return m_Tail->m_Data;
	}
	else
	{
		throw("NO DATA");
	}
}

template <typename T>
void DoubleLinkedList<T>::InsertAfter(T data, T pos)
{
	Node<T> * NN = new Node<T>(data);

	if(IsEmpty() == true)//empty list
	{
		m_Head = NN;
		m_Tail = NN;
		NumNodes++;
		current = 0;
	}
	else if(m_Head->m_Next == m_Tail && m_Tail->m_Previous == m_Head)//head and tail are = 
	{
		NN->m_Previous = m_Tail;
		m_Tail->m_Next = NN;
		m_Tail = NN;
		NN->m_Next = nullptr;
		current++;
		NumNodes++;
	}
	else if(pos == 1 && data > 2)//after tail
	{
		NN->m_Previous = m_Tail;
		m_Tail->m_Next = NN;
		m_Tail = NN;
		NN->m_Next = nullptr;
		current++;
		NumNodes++;
	}
	else if(pos > 0 && pos < NumNodes)//middle
	{
		m_Tail->m_Previous->m_Next = NN;
		NN->m_Previous = m_Tail->m_Previous;
		NN->m_Next = m_Tail;
		m_Tail->m_Previous = NN;
	}
	else if(pos > NumNodes)//node doesn't exist
	{
		delete NN;
		throw("Error: Node does not exist.");
	}
}
template <typename T>
void DoubleLinkedList<T>::InsertBefore(T data, T pos)
{
	Node<T> * NN = new Node<T>(data);

	if(IsEmpty() == true)//empty list
	{
		m_Head = NN;
		m_Tail = NN;
		NumNodes++;
		current = 0;
	}
	else if(m_Head->m_Next == m_Tail && m_Tail->m_Previous == m_Head)//head and tail are = 
	{
		NN->m_Next = m_Head;
		m_Head->m_Previous = NN;
		m_Head = NN;
		current--;
		NumNodes++;
	}
	else if(pos == -1 && data < -2)//before head
	{
		NN->m_Next = m_Head;
		m_Head->m_Previous = NN;
		m_Head = NN;
		current--;
		NumNodes++;
	}
	else if(pos < 0)//middle
	{
		m_Head->m_Next->m_Previous = NN;
		NN->m_Next = m_Head->m_Next;
		NN->m_Previous = m_Head;
		m_Head->m_Next = NN;
	}
	else if(pos > NumNodes)//node doesn't exist
	{
		delete NN;
		throw("Error: Node does not exist.");
	}
}

template <typename T>
Node<T> * DoubleLinkedList<T>::getHead()
{
	return m_Head;
}

template <typename T>
Node<T> * DoubleLinkedList<T>::getTail()
{
	return m_Tail;
}
template <typename T>
bool DoubleLinkedList<T>::IsEmpty()
{
	if(m_Head == nullptr && m_Tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void DoubleLinkedList<T>::Extract(T pos)
{
	if(NumNodes == 0)
	{
		throw("Error: Cannot extract from empty list.");
	}

	if(m_Head == m_Tail && m_Tail == m_Head)
	{
		delete m_Head;
		NumNodes--;
	}

	if(NumNodes > 0 && pos == 0)
	{
		delete m_Head;
		m_Tail->m_Previous = nullptr;
		m_Tail->m_Next = nullptr;
		m_Head = m_Tail;
		NumNodes--;
	}

	if(NumNodes > 0 && pos == 1)
	{
		delete m_Tail;
		m_Head->m_Next = nullptr;
		m_Head->m_Previous= nullptr;
		m_Tail = m_Head;
		NumNodes--;
	}
}
#endif