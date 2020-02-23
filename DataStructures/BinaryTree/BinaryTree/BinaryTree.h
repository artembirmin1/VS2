#pragma once

#ifndef _BINARYTREE_H_ 
#define _BINARYTHEE_H_ 

#include <iostream> 

using namespace std;

template<typename T >
class Tree {
private:
struct Node
	{
		T data;
		Node* left;
		Node* right;
	};
	void printHelper(Node*&);
	void addHelper(T, Node*&);
	void createItem(T, Node*&);

public:Node* root = NULL;
	  void print();
	void add(T);

};
	

template<typename T >
void Tree<T>::add(T x)
{
	if (root != NULL)
	{
		addHelper( x, root);
	}
	else
	{
		root = new Node;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
}

template<typename T >
void Tree<T>::createItem(T x, Node*& item)
{
	item = new Node;
	item->data = x;
	item->left = NULL;
	item->right = NULL;
}

template<typename T >
void Tree<T>::addHelper(T x, Node*& item)
{
	if (x > item->data)
		if (item->right != NULL)
			addHelper(x, item->right);
		else
		{
			createItem(x, item->right);

		}
	else if (x < item->data)
		if (item->left != NULL)
			addHelper(x, item->left);
		else
		{
			createItem(x, item->left);
		}

}

template<typename T >
void Tree<T>::print()
{
	printHelper(root);
}

template<typename T >
void Tree<T>::printHelper(Node*& item)
{
	if (item != NULL)
	{
		printHelper(item->left);
		cout<<item->data;
		printHelper(item->right);
	}
}

#include"BinaryTree.cpp";
#endif 