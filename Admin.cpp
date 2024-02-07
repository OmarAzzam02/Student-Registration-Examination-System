#include"Admin.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
int passed = 0, failed = 0;

static vector<string> split(string s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		result.push_back(item);
	}
	return result;
}

string Admin::Name = "admin";
string Admin::Password = "12@#6*^7";
Admin::Admin() {}


int Admin::displayAdminMenu()
{
	std::string attemptLoginUser, attemptLoginPass;
	do {
		std::cout << "Enter UserName:  ";
		std::cin >> attemptLoginUser;
		std::cout << "password: ";
		std::cin >> attemptLoginPass;
	} while (!CheckAdmin(attemptLoginUser, attemptLoginPass));

	system("cls");
	std::cout << "--------Welcome Admin--------\n Choose type of User You want to create: \n";
	std::cout << "1- Student  \n";
	std::cout << "2- Instructor\n";   int createUserchoice;
	std::cout << "3- return to the MainMenu \n";
	std::cin >> createUserchoice;
	return createUserchoice;
}

bool Admin::CheckAdmin(string user, string pass) {
	bool flag = false;
	if (Name != user || Password != pass) {
		std::cout << "Username Or Password is InValid!please try again. \n";
		return flag;
	}

	else { flag = true;  return flag; }

}
