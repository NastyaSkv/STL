#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a, b;
	cout << "������� ��� �����: "; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Error: something happend" << endl;
	}
}