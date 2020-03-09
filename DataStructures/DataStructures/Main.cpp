

#include "BinaryTree.h" 
#include <iostream> 

using namespace std;

int main()
{
	Node <int> *b;
	Tree <int> a;
	a.add(5);
	a.add(7);
	

	a.add(15);
	a.add(30);
	a.add(32);
	a.add(29);
	a.add(27);
	a.add(28);
	a.add(13);
	
	

	a.print();
	
	
	
	cout << endl;
	a.print();
	cout << endl << a.successor(15)->key;
	cout << endl << a.predecessor(30)->key;


}
