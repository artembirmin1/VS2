

#include "BinaryTree.h" 
#include <iostream> 

using namespace std;

int main()
{
	Node <int> *b;
	Tree <int> a;
	a.add(5);
	a.add(3);
	a.add(0);
	a.add(4);
	a.add(2);
	a.add(8);
	a.add(6);
	a.add(9);
	a.add(10);
	a.add(7);

	a.print();
	
	
	a.remove(3);
	cout << endl;
	a.print();


}
