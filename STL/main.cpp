#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define STL_ARRAY
//#define MY_EXCEPTION
//#define STL_VECTOR

template<typename T>void print(const std::vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	const int SIZE = 5;
	std::array<int, SIZE> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	//std::vector<int> vec(10000);
	for (int i = 0; i < vec.size(); i++)vec[i] = rand();
	print(vec);
	vec.push_back(123);
	print(vec);

	vec.resize(7);
	print(vec);
	//vec.resize(10); 
	//vec.shrink_to_fit();
	//print(vec);

	vec.reserve(12);
	print(vec);

	try                //отслеживает исключени€
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	int index;
	int number;
	int value;
	do
	{
		cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
		if (index >= vec.size())cout << "Out of range" << endl;
	} while (index >= vec.size());
	cout << "¬ведите количество добавл€емых значений: "; cin >> number;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;

	vec.insert(vec.begin() + index, number, value);
	print(vec);

	do
	{
		cout << "¬ведите индекс удал€емого значени€: "; cin >> index;
		if (index >= vec.size())cout << "Out of range" << endl;
	} while (index >= vec.size());
	cout << "¬ведите количество удал€емых элементов: "; cin >> index;
	vec.erase(vec.begin() + index, vec.begin() + index + number);
	for (int i : vec)cout << i << tab; cout << endl;


#endif //STL_VECTOR

	std::list<int> list = { 0,1,1,2,3,5,8,13,21,34,55,89 };
	for (int i : list)cout << i << tab; cout << endl;
	int value;
	int index;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)++position;
	std::advance(position, index);  //то же самое что и for
	list.insert(position, value);
	for (int i : list)cout << i << tab; cout << endl;

}

template<typename T>void print(const std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size: " << vec.size() << endl;
	cout << "Max size: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
}