
#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using namespace std;
template<typename T >
class Stack {
private:
	struct Item {
		T data;
		Item* next;
	};
	Item* top = NULL;
public:
	/*
		Adds an element to the top of the stack.
	*/
	void Push(T);	

	/*
		Takes an item from the stack and then deletes it. 
		An exception may be thrown if the method is called when the stack is empty.
	*/	
	T Pop();		

	/*
		The Print method displays stack elements on the screen
	*/
	void Print();

	/*
		The isEmpty method checks the stack for emptiness.
		If empty - returns true. If not empty - returns false
	*/
	bool isEmpty();	

	/*
		Returns the value of the top element without deleting it.
		An exception may be thrown if the method is called when the stack is empty.
	*/
	T GetTop();	
						
};
#include "Stack.cpp" 
#endif
 

