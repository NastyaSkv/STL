#include<iostream>
#include<fstream>
#include<map>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------------------------\n"



const std::map<int, std::string> violation =
{
	{0, "Проезд на красный"},
	{1, "Превышение скорости"},
	{2, "Парковка в неположенном месте"},
	{3, "Езда по встречной полосе"},
	{4, "Оскорбление офицера"},
	{5, "Езда в нетрезвом состоянии"},
	{6, "Дрифт на перекрестке"},
};

class Crime
{
	int id;
	std::string place;
public:
	Crime(int violation, const std::string& place)
		:id(violation), place(place) {}
	~Crime() {}
	friend std::ostream& operator<<(std::ostream& os, const Crime& obj);
	friend void print(std::map<std::string, std::list<Crime>> base);
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << violation.at(obj.id) << " " << obj.place;
}

template<typename T>void print(std::map<std::string, std::list<Crime>> base);
template<typename T>void save(std::map<std::string, std::list<Crime>> base);

void main()
{
	setlocale(LC_ALL, "");

	//std::ofstream fout;               //создали поток
	//fout.open("File_base.txt", std::ios::app);     //открыли

	std::map<std::string, std::list<Crime>> base =
	{
		{"a777bb", {Crime(0, "ул. Ленина"), Crime(6, "ул. Космонавтов"), Crime(3, "ул. Октябрьская")}},
		{"m123ab", {Crime(2, "пл. Революции")}},
		{"a234bb", {Crime(5, "ул. Ленина"), Crime(4, "ул. Ленина")}},
	};
	
	print(base);
	//save(base);
}

template<typename T>void print(std::map<std::string, std::list<Crime>> base)
{
	for (std::map<std::string, std::list<Crime>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		//fout << it->first << ":\n";
		for (std::list<Crime>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << endl;
			//fout << *jt << endl;
		}
		cout << delimiter << endl;
		//fout << delimiter << endl;
	}
}
//template<typename T>void save(std::map<std::string, std::list<Crime>> base)
//{
//	std::ofstream fout;               //создали поток
//	fout.open("File_base.txt", std::ios::app);     //открыли
//	std::map<std::string, std::list<Crime>> base =
//	{
//		{"a777bb", {Crime(0, "ул. Ленина"), Crime(6, "ул. Космонавтов"), Crime(3, "ул. Октябрьская")}},
//		{"m123ab", {Crime(2, "пл. Революции")}},
//		{"a234bb", {Crime(5, "ул. Ленина"), Crime(4, "ул. Ленина")}},
//	};
//
//	for (std::map<std::string, std::list<Crime>>::iterator it = base.begin(); it != base.end(); ++it)
//	{
//		//cout << it->first << ":\n";
//		fout << it->first << ":\n";
//		for (std::list<Crime>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
//		{
//			//cout << *jt << endl;
//			fout << *jt << endl;
//		}
//		//cout << delimiter << endl;
//		fout << delimiter << endl;
//	}
//	fout.close();
//	system("notepad File_base.txt");
//}