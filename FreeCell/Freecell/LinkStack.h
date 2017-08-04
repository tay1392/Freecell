/************************************************************************
* Class: LinkStack
*
* Constructors:	
*	LinkStack() 
*		m_Top set to 0
*	LinkStack(const LinkStack & obj)
*		copy ctor
*
* Mutators:
*	none
*
* Methods:		
*	LinkStack & operator=(const LinkStack & rhs)
*		assignment operator
*	~LinkStack()
*		dtor
*	void Push(T data)
*		Pushes data onto the stack
*	DoubleLinkedList<T> & GetStack()
*		Returns the m_Stack
*	T Pop()
*		Pops and returns an element off top of stack
*	T Peek()
*		returns element on top of stack
*	int Size()
*		returns current size of stack
*	bool IsEmpty()
*		checks if stack is empty
*	void Display()
*		Displays current stack contents
*************************************************************************/
#ifndef MY_LINK_STACK_H
#define MY_LINK_STACK_H

#include "doublelinkedlist.h"

template <typename T>
class LinkStack
{
	public:
		LinkStack();
		LinkStack(const LinkStack & obj);
		LinkStack & operator=(const LinkStack & rhs);
		~LinkStack();
		void Push(T data);
		DoubleLinkedList<T> & GetStack();
		T Pop();
		T Peek();
		int Size();
		bool IsEmpty();
		void Display();
	private:
		int m_Top;
		DoubleLinkedList<T> m_Stack;
};

template <typename T>
LinkStack<T>::LinkStack():m_Top(0)
{

}

template <typename T>
LinkStack<T>::LinkStack(const LinkStack & obj)
{
	*this = obj;
}

template <typename T>
LinkStack<T> & LinkStack<T>::operator=(const LinkStack & rhs)
{
	m_Top = rhs.m_Top;
	m_Stack = rhs.m_Stack;
	return * this;
}

template <typename T>
LinkStack<T>::~LinkStack()
{

}

template <typename T>
DoubleLinkedList<T> & LinkStack<T>::GetStack()
{
	return m_Stack;
}

template <typename T>
void LinkStack<T>::Push(T data)
{
	m_Stack.Append(data);
	m_Top++;
}

template <typename T>
T LinkStack<T>::Pop()
{
	if(m_Top == 0)
	{
		throw("EROOR: CANNOT POP EMPTY LIST");
	}
	else if(m_Top == 1)
	{
		T temp = m_Stack.Last();
		m_Top--;
		m_Stack.NumNodes--;
		delete m_Stack.m_Head;
		m_Stack.m_Head = nullptr;
		m_Stack.m_Tail = nullptr;
		return temp;
	}
	else
	{
		m_Top--;
		m_Stack.NumNodes--;
		T temp = m_Stack.Last();
		m_Stack.m_Tail = m_Stack.m_Tail->m_Previous;
		delete m_Stack.m_Tail->m_Next;
		m_Stack.m_Tail->m_Next = nullptr;
		return temp;
	}
}

template <typename T>
T LinkStack<T>::Peek()
{
	if(m_Top == 0)
	{
		throw("EROOR: CANNOT POP EMPTY LIST");
	}
	else
	{
		return m_Stack.Last();
	}
}

template <typename T>
int LinkStack<T>::Size()
{
	return m_Stack.NumNodes;
}

template <typename T>
bool LinkStack<T>::IsEmpty()
{
	if(m_Top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void LinkStack<T>::Display()
{
	Node<T> * travel = m_Stack.m_Head;

	for(int i = 0; i < m_Top; i++)
	{
		cout << travel->m_Data <<  " ";
		travel = travel->m_Next;
	}
}

#endif