#ifndef _LINKEDLIST_CPP_
#define _LINKEDLIST_CPP_

#include "LinkedList.h"
#include <iostream>

template<typename T >
void LinkedList<T>::append(T d)
{
	Item* q;
	q = new Item;
	q->data = d;
	size++;
	if (isEmpty())
	{
		last = q;
		q->prev = 0;
		first = q;
	}
	else
	{
		last->next = q;
		q->prev = last;
		last = q;
	}
}

template<typename T >
void LinkedList<T>::prepend(T d)
{
	if (size)
	{
		Item* q;
		q = new Item;
		q->data = d;
		first->prev = q;
		q->next = first;
		first = q;
		size++;
		q->prev = 0;
	}
	else append(d);
}

template<typename T >
void LinkedList<T>::insert(size_t pos, T x)
{
	if (!isEmpty())
	{
		if (pos < size && pos>0)
		{
			size++;
			Item* f; Item* h;
			f = new Item;
			f->data = x;
			Item* g = first;
			for (int i = 1; i < pos; i++)
			{
				g = g->next;
			}
			f->prev = g;
			h = g->next;
			g->next = f;
			g = h;
			f->next = g;
			g->prev = f;
		}
		else if (pos == size)
			append(x);
		else if (pos == 0)
			prepend(x);
		else
			throw std::out_of_range("Went beyond size");
	}
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
T LinkedList<T>::dropFirst()
{
	T x;
	Item* q = first;
	if (!isEmpty())
	{
		x = first->data;
		first = q->next;
		delete q;
		first->prev = NULL;
		size--;
		return x;
	}
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
T LinkedList<T>::dropLast()
{
	T x;
	Item* q = last;
	if (!isEmpty())
	{
		size--;
		x = last->data;
		last = q->prev;
		delete q;
		return x;
	}
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
T LinkedList<T>::remove(size_t pos)
{
	if (!isEmpty())
	{
		if (pos < size - 1 && pos>0)
		{
			Item* f;
			Item* h;
			Item* g = first;
			for (int i = 1; i < pos; i++)
			{
				g = g->next;
			}
			f = g;
			h = g->next;
			g = h->next;
			T x = h->data;
			delete h;
			size--;
			f->next = g;
			g->prev = f;
			return x;
		}
		else if (pos == size - 1)
			dropLast();
		else if (pos == 0)
			dropFirst();
		else
			throw std::out_of_range("Went beyond size");
	}
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
void LinkedList<T>::replase(size_t pos, T x)
{
	if (!isEmpty())
	{
		if (pos < size - 1 && pos > 0)
		{
			Item* q = first;
			for (int i = 0; i <= pos; i++)
			{
				q = q->next;
			}
			q->data = x;
		}
		else if (pos == size - 1)
			last->data = x;
		else if (pos == 0)
			first->data = x;
		else
			throw std::out_of_range("Went beyond size");
	}
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
void LinkedList<T>::print()
{
	if (!isEmpty())
	{
		size_t c = size;
		Item* q = first;
		do
		{
			cout << q->data << " ";
			q = q->next;
			c--;
		} while (c);
	}
}

template<typename T >
bool LinkedList<T>::isEmpty()
{
	return first == NULL;
}

template<typename T >
T LinkedList<T>::getLast()
{
	if (!isEmpty())
		return last->data;
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
T LinkedList<T>::getFirst()
{
	if (!isEmpty())
		return first->data;
	else
		throw std::out_of_range("EMPTY!!!");
}

template<typename T >
size_t LinkedList<T>::getSize()
{
	return size;
}

template<typename T>
T LinkedList<T>::operator[](size_t x)
{
	if (!isEmpty())
	{
		int i = 0; Item* q = first;
		if (x < size - 1 && x>0)
		{
			while (i < x)
			{
				q = q->next;
				i++;

			}
			return q->data;
		}
		else if (x == size - 1)
			return last->data;
		else if (x == 0)
			return first->data;
		else
			throw std::out_of_range("Went beyond size");
	}
	else
		throw std::out_of_range("EMPTY!!!");
}

#endif