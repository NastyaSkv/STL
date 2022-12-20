#include<iostream>
#include<list>
using std::cin;
using std::cout;
using std::endl;


template<typename T>void print(std::list<T>& lt);

void main()
{
	setlocale(LC_ALL, "");
	std::list<int> lt = { 0,1,1,2,3,5,8,13,21,34,55 };
	print(lt);


}

template<typename T>void print(std::list<T>& lt)
{

	for (std::list<int>::iterator it = lt.begin(); it != lt.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
}