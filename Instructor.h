#ifndef I_H
#define I_H
#include <fstream>
#include<iostream>
#include "User.h"
#include "Question.h"
class Admin;
using namespace std;

class Instructor :public User {
	float min, max, avg;
	int NumOfQuestions;
	Question* Q;

public:
	static int ID;
	static int NOQTD;
	Instructor(string name = "", string pass = "");
	static double GetMax();
	static double GetMin();
	static double GetAvg();
	void static PrintExamResults();
	void static displayInstructorInAdmin();//done
	int static displayInstructorLogin();//done
	void static PassFail();
};

#endif