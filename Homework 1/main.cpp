#include<iostream>
#include<list>
using std::cin;
using std::cout;
using std::endl;


//template<typename T>void print(std::list<T>& lt);

void main()
{
	setlocale(LC_ALL, "");
	int index;
	int value;
	std::list<int> lt = { 0,1,1,2,3,5,8,13,21,34,55 };
	std::list<int>::iterator it;
	//print(lt);
	
	for (it = lt.begin(); it != lt.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	lt.insert(it,index, value);
	for (it = lt.begin(); it != lt.end(); it++)
	{
		cout << *it << "\t";
	}
}

//template<typename T>void print(std::list<T>& lt)
//{
//
//	for (std::list<int>::iterator it = lt.begin(); it != lt.end(); it++)
//	{
//		cout << *it << "\t";
//	}
//	cout << endl;
//	it.insert(index, value);
//}