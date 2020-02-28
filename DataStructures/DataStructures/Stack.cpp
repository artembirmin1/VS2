
#ifndef _STACK_CPP_
#define _STACK_CPP_

#include "Stack.h"
#include <iostream>

using namespace std; 
	
template<typename T >
void Stack<T>::Push(T d)
{
	Item* q;
	q = new Item;
	q->data = d;
	if (isEmpty())
	{
		top = q;
		q->next = 0;
	}
	else
	{
		q->next = top;
		top = q;
	}
}
	
template<typename T >
T  Stack<T>::Pop()
{	
	T x;
	Item* q = top;
	if (!isEmpty())
	{			
		x = top->data;
		top = q->next;
		delete q;
		return x;
	}	
	else 
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
void Stack<T>::Print()
{
	if (!isEmpty())
	{
		Item* q = top;
		do
		{
			cout << q->data << endl;
			q = q->next;
		} while (q != 0);
	}
}

template<typename T >
bool Stack<T>::isEmpty()
{
	return top==NULL;
}

template<typename T >
T Stack<T>::GetTop()
{
	if (!isEmpty())
		return top->data;
	else
		throw std::out_of_range("EMPTY!!!");
}

#endif 
