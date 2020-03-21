#pragma once
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>

using namespace std;

template<typename T >
struct Node
{
		T key;
		Node* left;
		Node* right;
		Node* parent;
};

template<typename T >
class Tree {
private:
	Node<T>* root = NULL;
	void add(T, Node<T>*);
	void createItem(T, Node<T>*&, Node<T>*&);	
	Node<T>* takeOutSuccessor(Node<T>*);
	Node<T>* search(T x, Node<T>*& item);
	size_t getDepth(Node<T>*);
	void print(Node<T>* item);
	
public:
	void add(T);
	void remove(T k, bool d = false);
	void removeSubtree(Node<T>*);
	Node<T>* search(T);
	Node<T>* search(string);
	Node<T>* successor(T);
	Node<T>* predecessor(T);
	Node<T>* getMin();
	Node<T>* getMax();
	size_t getDepth();
	void print();
};

#include "BinaryTree.cpp"

#endif