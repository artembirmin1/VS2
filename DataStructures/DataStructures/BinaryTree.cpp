
#ifndef _BINARYTREE_CPP_
#define _BINARYTREE_CPP_

#include "BinaryTree.h" 
#include <iostream> 

template<typename T >
void Tree<T>::add(T x)
{
	
	Node<T>* item = root;
	if (root != NULL)
	{
		if (x > item->key)
			if (item->right != NULL)
			{	
				add(x, item->right);
			}
			else
			{
				createItem(x, item->right, item);
			}
		else if (x < item->key)
			if (item->left != NULL)
			{
				add(x, item->left);
			}
			else
			{
				createItem(x, item->left, item);
			}
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
void Tree<T>::add(T x, Node<T>* item)
{
	if (root != NULL)
	{
		if (x > item->key)
			if (item->right != NULL)
			{	
				add(x, item->right);
			}
				
			else
			{
				createItem(x, item->right, item);
			}
		else if (x < item->key)
			if (item->left != NULL)
			{	
				add(x, item->left);
			}
				
			else
			{
				createItem(x, item->left, item);
			}
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
void Tree<T>::remove(T x, bool d)
{
	Node<T>* item = search(x);
	if (item->left == NULL && item->right == NULL)
	{
		Node<T>* p = item->parent;
		delete item;
		p->left = NULL;
		p->right = NULL;
	}
	else if (item->left == NULL || item->right == NULL)
	{
		if (d == false) 
		{
			Node<T>* p = item->parent;
			Node<T>* v;
			item->left != NULL ? v = item->left : v = item->right;
			p->left == item ? p->left = v : p->right = v;
			delete item;
		}
		else
		{
			item->parent->key > item->key ? item->parent->left = NULL : item->parent->right = NULL;
			removeSubtree(item);
		}
	}
	else if (item->left != NULL && item->right != NULL)
	{
		if (d == false)
		{
			Node<T>* v = takeOutSuccessor(successor(x));
			v->left = item->left;
			v->right = item->right;
			v->parent = item->parent;
			item->parent->key > item->key ? item->parent->left = v : item->parent->right = v;
			delete item;
		}
		else
		{
			item->parent->key > item->key ? item->parent->left = NULL : item->parent->right = NULL;
			removeSubtree(item);
		}
	}

		
}

template<typename T >
void Tree<T>::removeSubtree(Node<T>* item)
{	
	
	if(item->left!=NULL)
		removeSubtree(item->left);
	if (item->right != NULL)
		removeSubtree(item->right);
	delete item;
}

template<typename T >
Node<T>* Tree<T>::takeOutSuccessor(Node<T>* item)
{	
	Node<T>* p = item->parent;
	if (item->left != NULL || item->right != NULL) 
	{
		Node<T>* r = item->right;
		item->right = NULL;
		p->left = r;
	}
	else
	{
		p->left = NULL;
	}
	return item;
}

template<typename T >
Node<T>* Tree<T>::search(T x)
{
	Node<T>*  item= root;
	if (x == item->key)
		return item;
	else if (x > item->key)
	{
		search(x, item->right);
	}
	else if (x < item->key)
	{
		search(x, item->left);
	}
}

template<typename T >
Node<T>* Tree<T>::search(T x, Node<T>*& item)
{	
	if(x == item->key)
		return item;
	else if (x > item->key)
	{
		search(x, item->right);
	}
	else if (x < item->key)
	{
		search(x, item->left);
	}
}

template<typename T >
Node<T>* Tree<T>::successor(T x)
{
	Node<T>* v = search(x);
	if (v->left == NULL && v->right == NULL)
		return v;
	else
	{
		v = v->right;
		if (v->left == NULL)
			return v;
		while (v->left != NULL )
		{
			v = v->left;
		}
		return v;
	}

}

template<typename T >
Node<T>* Tree<T>::predecessor(T x)
{
	Node<T>* v = search(x);
	if (v->left == NULL && v->right == NULL)
		return v;
	else
	{
		v = v->left;
		if (v->right == NULL)
			return v;
		while (v->left != NULL || v->right != NULL)
		{
			v = v->right;
		}
		return v;
	}
}

template<typename T >
Node<T>* Tree<T>::search(string x)
{
	Node<T>* item = root;
	if (x == "min")
		item = getMin();
	else if (x == "max")
		item = getMax();
	return item;
}
template<typename T >
Node<T>* Tree<T>::getMin()
{
	Node<T>* item = root;
	while (item->left != NULL)
	{
		item = item->left;
	}
	return item;
}

template<typename T >
Node<T>* Tree<T>::getMax()
{
	Node<T>* item = root;
	while (item->right != NULL)
	{
		item = item->right;
	}
	return item;
}

template<typename T >
size_t Tree<T>::getDepth()
{
	Node<T>* item = root;
	if (item == NULL)
		return 0;
	if (item->left == NULL && item->right == NULL)
		return 1;
	if (getDepth(item->left) > getDepth(item->right))
		return 1 + getDepth(item->left);
	else
		return 1 + getDepth(item->right);
	if (item->left != NULL)
		return 1 + getDepth(item->left);
	if (item->right != NULL)
		return 1 + getDepth(item->right);
}

template<typename T >
size_t Tree<T>::getDepth(Node<T>* item)
{
	if (item == NULL)
		return 0;
	if (item->left == NULL && item->right == NULL)
		return 1;
	if (getDepth(item->left) > getDepth(item->right))
		return 1 + getDepth(item->left);
	else
		return 1 + getDepth(item->right);
	if (item->left != NULL)
		return 1 + getDepth(item->left);
	if (item->right != NULL)
		return 1 + getDepth(item->right);
}

template<typename T >
void Tree<T>::print()
{
	if (root != NULL)
	{
		cout << root->key <<" ";
		print(root->left);
		print(root->right);
	}
}

template<typename T >
void Tree<T>::print(Node<T>* item)
{
	if (item != NULL)
	{
		cout << item->key<<" ";
		print(item->left);	
		print(item->right);
	}
}
#endif