#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define STL_ARRAY
//#define MY_EXCEPTION
#define STL_VECTOR

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

	for (std::vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it)
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

	vec.insert(vec.begin()+index,number, value);
	print(vec);

#endif //STL_VECTOR

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