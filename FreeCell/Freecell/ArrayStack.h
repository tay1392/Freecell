/************************************************************************
* Class: ArrayStack
*
* Constructors:	
*	ArrayStack() 
*		m_Top set to 0
*	ArrayStack(const ArrayStack & obj)
*		copy ctor
*
* Mutators:
*	none
*
* Methods:		
*	ArrayStack & operator=(const LinkStack & rhs)
*		assignment operator
*	~ArrayStack()
*		dtor
*	void Push(T data)
*		Pushes data onto the stack
*	T Pop()
*		Pops and returns an element off top of stack
*	T Peek()
*		returns element on top of stack
*	int Size()
*		returns current size of stack
*	bool IsEmpty()
*		checks if stack is empty
*	bool IsFull()
*		checks if stack is full
*	void Display()
*		Displays current stack contents
*************************************************************************/
#ifndef MYSTACK_H
#define MYSTACK_H
#include "Array.h"

template <typename T>
class MyStack
{
	public:
		MyStack();
		MyStack(int size);
		MyStack(const MyStack & obj);
		MyStack & operator=(const MyStack & rhs);
		void Push(T data);
		void Display();
		T Pop();
		T Peek();
		int Size();
		Array<T> & GetArrayStack();
		int GetTop();
		bool IsEmpty();
		bool IsFull();
		~MyStack();
	private:
		int m_StackSize;
		int m_Top;
		Array<T> m_ArrayStack;
};

template <typename T>
MyStack<T>::MyStack():m_StackSize(0), m_Top(0)
{

}

template <typename T>
MyStack<T>::MyStack(int size)
	: m_ArrayStack(size), m_StackSize(size), m_Top(0)
{

}

template <typename T>
MyStack<T>::MyStack(const MyStack & obj)
{
	*this = obj;
	//cout << "Copy ctor called." << endl;
}

template <typename T>
int MyStack<T>::GetTop()
{
	return m_Top;
}

template <typename T>
Array<T> & MyStack<T>::GetArrayStack()
{
	return m_ArrayStack;
}

template <typename T>
MyStack<T> & MyStack<T>::operator=(const MyStack & rhs)
{
	m_ArrayStack = rhs.m_ArrayStack;
	m_StackSize = rhs.m_StackSize;
	m_Top = rhs.m_Top;
//	cout << "Assignment operator called." << endl;
	return * this;
}

template <typename T>
MyStack<T>::~MyStack()
{

}

template <typename T>
void MyStack<T>::Push(T data)
{
	if(IsFull() == false)
	{
		m_ArrayStack[m_Top] = data;
		m_Top++;
	}
	else
	{
		throw ("ERROR: CANNOT PUSH ONTO FULL STACK");
	}
}

template <typename T>
T MyStack<T>::Pop()
{
	if(IsEmpty() == false)
	{
		m_Top--;
		return m_ArrayStack[m_Top];
	}
	else
	{
		throw ("ERROR: CANNOT POP EMPTY STACK");
	}
}

template <typename T>
T MyStack<T>::Peek()
{
	if(IsEmpty() == false)
	{
		return m_ArrayStack[m_Top - 1];
	}
	else
	{
		throw ("ERROR: CANNOT PEEK EMPTY STACK");
	}
}

template <typename T>
int MyStack<T>::Size()
{
	return m_Top;
}

template <typename T>
bool MyStack<T>::IsEmpty()
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
bool MyStack<T>::IsFull()
{
	if(m_Top == m_StackSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void MyStack<T>::Display()
{
	if(IsEmpty() == false)
	{
		for(int i = 0; i < m_Top; i++)
		{
			cout << m_ArrayStack[i] << " ";
		}
	}
}

#endif
