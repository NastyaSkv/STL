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
	{0, "������ �� �������"},
	{1, "���������� ��������"},
	{2, "�������� � ������������ �����"},
	{3, "���� �� ��������� ������"},
	{4, "����������� �������"},
	{5, "���� � ��������� ���������"},
	{6, "����� �� �����������"},
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

	//std::ofstream fout;               //������� �����
	//fout.open("File_base.txt", std::ios::app);     //�������

	std::map<std::string, std::list<Crime>> base =
	{
		{"a777bb", {Crime(0, "��. ������"), Crime(6, "��. �����������"), Crime(3, "��. �����������")}},
		{"m123ab", {Crime(2, "��. ���������")}},
		{"a234bb", {Crime(5, "��. ������"), Crime(4, "��. ������")}},
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
//	std::ofstream fout;               //������� �����
//	fout.open("File_base.txt", std::ios::app);     //�������
//	std::map<std::string, std::list<Crime>> base =
//	{
//		{"a777bb", {Crime(0, "��. ������"), Crime(6, "��. �����������"), Crime(3, "��. �����������")}},
//		{"m123ab", {Crime(2, "��. ���������")}},
//		{"a234bb", {Crime(5, "��. ������"), Crime(4, "��. ������")}},
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