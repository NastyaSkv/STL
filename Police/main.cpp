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
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << violation.at(obj.id) << " " << obj.place;
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.id << " " << obj.place;
	return ofs;
}

void print(const std::map<std::string, std::list<Crime>> base);
void save(const std::map<std::string, std::list<Crime>> base, const std::string filename);
void load(std::map<std::string, std::list<Crime>> base, const std::string& filename);

void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string, std::list<Crime>> base/* =
	{
		{"a777bb", {Crime(0, "ул. Ленина"), Crime(6, "ул. Космонавтов"), Crime(3, "ул. Октябрьская")}},
		{"m123ab", {Crime(2, "пл. Революции")}},
		{"a234bb", {Crime(5, "ул. Ленина"), Crime(4, "ул. Ленина")}},
	};
	print(base);
	save(base, "base.txt");


	system("notepad base.txt")*/;

	load(base, "base.txt");
	print(base);

}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << endl;
		}
		cout << delimiter << endl;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename.c_str());

	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		fout << it->first << ":\t";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			fout << *jt << ",";
		}
		fout << endl;
	}
	fout.close();
}

void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ifstream fin(filename.c_str());
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;   //номерной знак
			std::getline(fin, licence_plate, ':');
			if (licence_plate.empty())continue;
			std::string all_crimes;
			std::getline(fin, all_crimes);
			all_crimes.erase(0, 1);   //удаляем табуляцию
			size_t start = 0;
			size_t end = 0;
			for (start = 0, end = all_crimes.find(',');
				end != std::string::npos;
				start = end, end = all_crimes.find(',', end);
				)
			{
				std::string buffer 
			}
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
}