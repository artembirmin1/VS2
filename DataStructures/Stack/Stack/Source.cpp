

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Stack <string>  a;
	a.Push("AAAAAAAAA");
	string x;
	x = a.GetTop();
	cout << x << endl;
	a.Print();
	string y= a.Pop();
	cout << y << endl;
	
	cout<<a.isEmpty();
	//a.GetTop();
} 