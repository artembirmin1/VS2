#pragma once

#ifndef _BINARYTREE_H_ 
#define _BINARYTHEE_H_ 

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
	void printHelper(Node<T>*&);
	void printHelper2(Node<T>*&);
	void addHelper(T, Node<T>*&);
	void createItem(T, Node<T>*&, Node<T>*&);
	Node<T>* searchHelper(T x, Node<T>*& item);
	void print(Node<T>* item);

public:	
	void print();
	
	void add(T);
	Node<T>* search(T);
	

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
		root = new Node<T>;
		root->parent = NULL;
		root->key = x;
		root->left = NULL;
		root->right = NULL;
	}
}

template<typename T >
void Tree<T>::createItem(T x, Node<T>*& item, Node<T>*& par)
{
	item = new Node<T>;
	item->parent = par;
	item->key = x;
	item->left = NULL;
	item->right = NULL;
}

template<typename T >
void Tree<T>::addHelper(T x, Node<T>*& item)
{
	if (x > item->key)
		if (item->right != NULL)
			addHelper(x, item->right);
		else
		{
			createItem(x, item->right,item);
		}
	else if (x < item->key)
		if (item->left != NULL)
			addHelper(x, item->left);
		else
		{
			createItem(x, item->left,item);
		}

}

template<typename T >
void Tree<T>::print()
{
	if (root!= NULL)
	{
		cout << root->key;
		print(root->left);
		print(root->right);
	}
}

template<typename T >
void Tree<T>::print(Node<T>* item)
{
	if (item != NULL)
	{
		cout << item->key;
		print(item->left);
		print(item->right);
	}
}

template<typename T >
void Tree<T>::printHelper(Node<T>*& item)
{
	if (item != NULL)
	{
		printHelper(item->left);
		cout<<item->data;
		printHelper(item->right);
	}
}

template<typename T >
void Tree<T>::printHelper2(Node<T>*& item)
{
	if (item != NULL)
	{
		cout << item->key;
		printHelper2(item->left);
		printHelper2(item->right);
	}
}

template<typename T >
Node<T>* Tree<T>::search(T x)
{
	Node<T>*  item;
	item = searchHelper(x, root);
	return item;
}

template<typename T >
Node<T>* Tree<T>::searchHelper(T x, Node<T>*& item)
{	
	if(x == item->key)
		return item;
	else if (x > item->key)
	{
		searchHelper(x, item->right);
	}
	else if (x < item->key)
	{
		searchHelper(x, item->left);
	}
}

#include"BinaryTree.cpp";

#endif
