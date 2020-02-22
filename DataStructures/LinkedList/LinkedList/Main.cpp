#include <iostream>
#include "LinkedList.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	LinkedList <int>  a;
	
	a.append(1);
	a.append(2);
	a.append(3);
	a.print();
	cout << endl;
	cout << "Добавим 4 в конец и 5 в начало  ";
	a.append(4);
	a.prepend(5);
	a.print();
	cout << endl << "Добавим 6 на 3е место  ";
	a.insert(3, 6);
	a.print();

	cout << endl << "Достанем 2й элемент  ";
	a.remove(2);
	a.print();
	cout << endl;

	cout << "Поменяем значение в 0м элементе ";
	a.replase(0, 12);
	a.print();
	cout << endl << a.getSize();



}