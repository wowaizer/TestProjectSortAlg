#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

class UsersInfo
{
public:
	string firstName;
	string lastName;
	string phoneNumber;

	UsersInfo(const string &_firstName, const string &_lastName, const string &_phoneNumber) :
		firstName(_firstName),
		lastName(_lastName),
		phoneNumber(_phoneNumber)
	{
	}
};

int main(int argc, char**argv)
{
	
	SetConsoleOutputCP (CP_UTF8);
	ifstream file;

	file.open("Users.txt");
	if (!file.is_open())
	{
		cout << "Error opening file";
		return 0;
	}

	vector<UsersInfo> Users;
	string line;

	while (getline(file, line))
	{
		string firstName, lastName, phoneNumber;
		istringstream iss(line);
		iss >> firstName >> lastName >> phoneNumber;
		UsersInfo person(firstName, lastName, phoneNumber);
		Users.push_back(person);
	}

	sort(Users.begin(), Users.end(), [](const UsersInfo &a, const UsersInfo &b) { return a.lastName < b.lastName; });

	SetConsoleOutputCP(1251);
	int number;
	std::cout << "ƒл€ сортировки по именам введите Ц 1, по фамили€м введите - 2, по телефонам введите- 3"<< endl;
	std::cin >> number;

	SetConsoleOutputCP(65001);
	for (UsersInfo i : Users)
	{
		
		if(number == 1)
		{
			cout << i.firstName << " " << i.lastName << " "  << i.phoneNumber << endl;
		}

		if(number == 2)
		{
			cout << i.lastName << " " << i.firstName << " "  << i.phoneNumber << endl;
		}
		if(number == 3)
		{
			cout << i.phoneNumber << " " << i.lastName << " "  << i.firstName << endl;
		}


	}

	return 0;
}