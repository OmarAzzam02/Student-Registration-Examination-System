#include"Admin.h"

int Instructor::ID = 0;
int Instructor::NOQTD = 0;
Instructor::Instructor(string name, string pass) :User(name, pass)
{
	NumOfQuestions = 0;
	Q = nullptr;
	min = 0.0;
	max = 0.0;
	avg = 0.0;
}
void Instructor::PrintExamResults() {
	std::cout << "Avg: " << GetAvg() << std::endl;
	std::cout << "Max: " << GetMax() << std::endl;
	std::cout << "Min: " << GetMin() << std::endl;
	PassFail();

}
void Instructor::displayInstructorInAdmin() {
	std::cout << "How Many Accounts you want to make for Instructors :  ";

	int InstArraySize; string user, pass;
	cin >> InstArraySize;

	Instructor* instructor = new Instructor[InstArraySize];

	fstream file;

	file.open("User.txt", std::ios::out | std::ios::app);


	for (int i = 0; i < InstArraySize; i++) {
		std::cout << "\nEnter Username for instructor Number: " << i + 1 << endl;
		cin >> user;
		do {
			std::cout << "Enter Password: \n";
			cin >> pass;
		} while (!User::CheckPassword(pass));

		instructor[i] = Instructor(user, pass);
		file << instructor[i].GetUser() << "," << instructor[i].GetPassword() << "," << "2" << std::endl;

		Instructor::ID++;
	}

	//file.close();

}


int Instructor::displayInstructorLogin() {
	int instructorChoice = 0;
	string name, pass;
	int Try = 1;
	bool flag = false;
	std::cout << "you have a max of 3 tries!!!!! \n";
	Sleep(500);

	while (!flag && Try <= 3) {

		std::cout << "Enter your username: ";
		cin >> name;
		std::cout << "password: ";
		cin >> pass;
		flag = User::ValidUser(name, pass, 2);
		Try++;
	}
	if (Try == 4) {
		std::cout << "You have Ranout Of Tries please check your login Info \n"; Sleep(5000);  system("cls");  instructorChoice = 7;
	}

	Sleep(500);
	system("cls");

	Sleep(500);
	if (instructorChoice != 7) {
		std::cout << "------welocome Dr." << name << "----- \n";
		std::cout << "1- Create Profile \n";
		std::cout << "2- change password \n";
		std::cout << "3- Write Exam \n";
		std::cout << "4- View last Exam Results\n";
		std::cout << "5- return To main Menu\n";
		std::cin >> instructorChoice;
	}


	return instructorChoice;
}

void Instructor::PassFail()
{
	string line;
	ifstream file; int pass = 0, fail = 0;
	file.open("Marks.txt");
	while (getline(file, line)) {
		string str = line;
		vector<string> v = split(str, ',');
		if (stoi(v[1]) >= 50) pass++;
		else fail++;
	}
	cout << "number of students who passes: " << pass;
	cout << endl << "number of students who failled: " << fail << endl;
}

double Instructor::GetMax() {
	string line;
	fstream file;
	file.open("Marks.txt", std::ios::in);
	double max = 0;

	while (getline(file, line)) {
		string str = line;
		vector<string> v = split(str, ',');
		double num = stoi(v[1]);
		if (max < num) max = num;
	}
	file.close();
	return max;

}
double Instructor::GetMin() {
	string line;
	fstream file;
	file.open("Marks.txt", std::ios::in);
	double Min = 101;

	while (getline(file, line)) {
		string str = line;
		vector<string> v = split(str, ',');
		double num = stoi(v[1]);
		if (Min > num) Min = num;
	}

	file.close();
	return Min;

}
double  Instructor::GetAvg() {//total/StdWhoPart
	string line;
	fstream file;
	file.open("Marks.txt", std::ios::in);
	double total = 0.0;

	while (getline(file, line)) {
		string str = line;
		vector<string> v = User::split(str, ',');
		double num = stoi(v[1]);
		total += num; Student::StdWhoPart++;
	}
	file.close();
	double avg = total / Student::StdWhoPart;
	return avg;
}

