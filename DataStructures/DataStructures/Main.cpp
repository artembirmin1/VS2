
#include "BinaryTree.h" 
#include <iostream> 

using namespace std;

int main()
{
	Tree <int> a;
	a.add(5);
	a.add(7);
	a.add(4);
	a.add(3);
	a.add(2);
	a.add(1);
	a.add(-1);
	a.add(-2);
	a.add(-3);
	a.add(15);
	a.add(30);
	a.add(32);
	a.add(29);
	a.add(27);
	//a.add(3);
	//a.add(13);
	a.print();
	cout << a.getDeep();
}
