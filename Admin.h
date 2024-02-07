#ifndef A_H
#define A_H
#include <iostream>
#include<string>
#include"Student.h"
#include"Instructor.h"
using namespace std;

class Admin {
	
	static string Name, Password;
public:
	Admin();
	int static displayAdminMenu();
	bool static CheckAdmin(string user, string pass);
};




#endif