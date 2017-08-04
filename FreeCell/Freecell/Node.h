/************************************************************************
* Class: Node
*
* Constructors:	
*	Node() 
*		no arg ctor
*	Node(T data)
*		1 arg ctor
*	Node(const Node & obj)
*		copy ctor
*
* Mutators:
*	void SetNext(Node * next)
*		Sets Next pointer
*	void SetPrevious(Node * previous)
*		Sets Previous pointer
*	void SetData(T data)
*		Sets Data
*
* Methods:		
*	Node<T> & operator=(const Node & rhs)
*		assignment operator
*	~Node()
*		Dtor
*	Node<T> * GetNext()
*		returns next pointer
*	Node<T> * GetPrevious()
*		returns previous pointer
*	T GetData()
*		Returns Data
*************************************************************************/
#ifndef NODE_H
#define NODE_H

template <typename T>
class LinkStack;

template <typename T>
class DoubleLinkedList;

template <typename T>
class Node
{
	friend class DoubleLinkedList<T>;
	friend class LinkStack<T>; //necessary for pop function

	public:
		//Canonical Methods
		Node();
		Node(T data);
		Node(const Node & obj);
		Node<T> & operator=(const Node & rhs);
		~Node();
		//Mutators/Accessors
		void SetNext(Node * next);
		void SetPrevious(Node * previous);
		Node<T> * GetNext();
		Node<T> * GetPrevious();
		void SetData(T data);
		T GetData();
	private:
		T m_Data;
		Node<T> * m_Next;
		Node<T> * m_Previous;
};

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
Node<T>::Node():m_Next(nullptr), m_Previous(nullptr), m_Data(0)
{

}

template <typename T>
Node<T>::Node(T data):m_Data(data)
{
	
}

template <typename T>
Node<T>::Node(const Node & obj)
{
	*this = obj;
}

template <typename T>
Node<T> & Node<T>::operator=(const Node & rhs)
{
	if(this != &rhs)
	{
		m_Data = rhs.m_Data;
		m_Next = rhs.m_Next;
		m_Previous = rhs.m_Previous;
	}
	else
	{
		cout << "Error: Self assignment." << endl;
	}
	return * this;
}

template <typename T>
T Node<T>::GetData()
{
	return m_Data;
}

template <typename T>
void Node<T>::SetData(T data)
{
	m_Data = data;
}

template <typename T>
void Node<T>::SetNext(Node * next)
{
	m_Next = next;
}
template <typename T>
void Node<T>::SetPrevious(Node * previous)
{
	m_Previous = previous;
}
template <typename T>
Node<T> * Node<T>::GetNext()
{
	return m_Next;
}
template <typename T>
Node<T> * Node<T>::GetPrevious()
{
	return m_Previous;
}
template <typename T>
Node<T>::~Node()
{

}
#endif
