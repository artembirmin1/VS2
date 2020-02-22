#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>

using namespace std;

template<typename T >
class LinkedList
{
private:

	struct Item
	{
		T data;
		Item* next;
		Item* prev;
	};
	size_t size = 0;
	Item* first = NULL;
	Item* last = NULL;

public:

	/*
		Adds an item to the end of the list.
	*/
	void append(T);

	/*
		Adds an item to the top of the list.
	*/
	void prepend(T);

	/*
		Adds an element to the specified position.
		pos-position of the element 
		before which you want to insert the element. 
		x-element.
	*/
	void insert(size_t, T);
	
	/*
		Returns the first entry in the list. 
		Then deletes it.
		An exception can be thrown 
		if the method is called when the list is empty 
		or a position outside the list is entered.
	*/
	T dropFirst();

	/*
		Returns the last entered item in the list.
		Then deletes it.
		An exception can be thrown
		if the method is called when the list is empty.
	*/
	T dropLast();

	/*
		Returns the item and the specified position.
		Then deletes it. 
		An exception can be thrown 
		if the method is called when the list is empty.
	*/
	T remove(size_t);

	/*
		Inserts a new value in the element's data.
		An exception can be thrown
		if the method is called when the list is empty 
		or a position outside the list is entered.
	*/
	void replase(size_t, T);

	/*
		Displays the list items.
		It is of an auxiliary nature when debugging.
		An exception can be thrown 
		if the method is called when the list is empty
		or a position outside the list is entered.
	*/
	void print();

	/*
		Checks the list for emptiness.
		If empty - returns true.
		If not empty - returns false
	*/
	bool isEmpty();

	/*
		Returns the value of the last element without deleting it.
		An exception may be thrown 
		if the method is called when the list is empty.
	*/
	T getLast();

	/*
		Returns the value of the first element without deleting it.
		An exception may be thrown 
		if the method is called when the list is empty.
	*/
	T getFirst();

	/*
		Returns the number of elements.
	*/
	size_t getSize();

	/*
		Overloading the [] operator.
		Returns the element's data.
		Do not use as a left-hand value for the operator =
	*/
	T operator [](size_t x);
};

#include "LinkedList.cpp" 

#endif
