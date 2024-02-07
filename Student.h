#ifndef S_H
#define S_H
#include <iostream>
using namespace std;
#include  <string>
#include "Instructor.h"
class Admin;
class Student :public User {
		

public:
	int static StdWhoPart;
	string static stName;
	Student(string name = "", string pass = "");
	void static SetMark(string ,double);
	int static displayStudentLogin();
	static void  displayStudentInAdmin();
	~Student();

};
#endif