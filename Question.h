#ifndef Q_H
#define Q_H
#include<iostream>
#include <string>
using namespace std;

class Question {
	string Q, A;
	
public:
	int static total;
	Question(string q = "", string a = "");
	void SetQuestion(string);
	void SetAnswer(string);
	string GetQuestion();
	string GetAnswer();
	static void displayQsInInstructor();
	static int NumOfQuestions();
	void static DisplayQuestion();


};


#endif