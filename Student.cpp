#include"Admin.h"
int Student::StdWhoPart = 0;

string Student::stName = "";
Student::Student(string name, string pass) :User(name, pass)
{
	
}


void Student::SetMark(string name, double mark)
{
	fstream file;
	file.open("Marks.txt", ios::out | ios::app);
	file << name << "," << mark << endl;
	file.close();
	

}


int Student::displayStudentLogin()
{
	string name, pass;
	int studentMenu = 0;
	int Try = 0;
	bool flag = false;
	std::cout << "you have a max of 3 tries!!!!! \n";
	Sleep(500);

	while (!flag && Try < 3) {

		std::cout << "Enter your  username: ";
		cin >> name;
		std::cout << "password: ";
		cin >> pass;
		flag = User::ValidUser(name, pass, 1);
		Try++;
	}
	if (Try >= 3) {
		std::cout << "You have Ranout Of Tries please check your login Info \n"; Sleep(5000); system("cls"); studentMenu = 7;
	}

	Sleep(500);
	system("cls");
	if (studentMenu != 7) {
		stName = name; // for Grades File (save student mark + his\her user)
		std::cout << "------welocome " << name << "------ \n";
		std::cout << "1- Create Profile \n";
		std::cout << "2- change password \n";
		std::cout << "3- Start Exam\n";
		std::cout << "4- return to Main Menu\n";
		std::cin >> studentMenu;
	}
	return studentMenu;
}

Student::~Student() {}

void Student::displayStudentInAdmin() {

	std::cout << "How Many Accounts you want to make for Students:  ";
	int StudentArraySize; string user, pass;
	cin >> StudentArraySize;

	Student* student = new Student[StudentArraySize];

	fstream file;

	file.open("User.txt", std::ios::out | std::ios::app);

	for (int i = 0; i < StudentArraySize; i++) {
		std::cout << "\nEnter Username for student Number: " << i + 1 << endl;
		cin >> user;
		do {
			std::cout << "Enter Password: \n";
			cin >> pass;
		} while (!User::CheckPassword(pass));
		student[i] = Student(user, pass);
		file << student[i].GetUser() << "," << student[i].GetPassword() << "," << "1" << endl;
		
	}
}

