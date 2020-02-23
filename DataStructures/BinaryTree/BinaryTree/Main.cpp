

#include "BinaryTree.h" 
#include <iostream> 

using namespace std;

int main()
{
	Tree <int> a;
	a.add(5);
	a.add(3);
	a.add(0);
	a.add(4);
	a.add(2);
	a.add(8);
	a.add(6);

	/*cout << a.root->left->data;
	cout << a.root->data;
	cout << a.root->left->left->data;*/
	a.print();


}
