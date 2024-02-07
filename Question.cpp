#include "Admin.h"

int Question::total = 0;
Question::Question(string q, string a) :Q(q), A(a) {}
void Question::SetQuestion(string q)
{
	Q = q;
}
void Question::SetAnswer(string a)
{
	A = a;
}

string Question::GetQuestion() { return Q; }
string Question::GetAnswer() { return A; }
void Question::displayQsInInstructor() {
	std::cout << "How Many Questions you want to write?  ";
	int QArraySize; string ques, answer;
	cin >> QArraySize;
	Question* question = new Question[QArraySize];
	fstream file;
	file.open("Questions.txt", std::ios::out | std::ios::app);

	for (int i = 0; i < QArraySize; i++) {
		std::cout << "\bWrite Question number " << i + 1 << endl;
		getline(cin, ques, '?');
		std::cout << "Write the Answer of Q" << i + 1 << endl;
		cin >> answer;
		question[i] = Question(ques, answer);
		file << question[i].GetQuestion() + "," + question[i].GetAnswer() + ",";
		Question::total++;
	}
	file.close();

	std::cout << "Enter the total Number of Questions you want to display for the exam: ";
	cin >> Instructor::NOQTD;

	fstream reset;
	reset.open("Marks.txt", ios::out);
	reset << "";
	reset.close();
}
int Question::NumOfQuestions() {
	string line; fstream File;
	total = 0;
	File.open("Questions.txt", std::ios::in);
	while (getline(File, line)) {

		total++;
	}
	File.close();
	return total;
}


void Question::DisplayQuestion() {
	Question* TQ = new Question[NumOfQuestions()];
	string line; int x = 0; ;
	ifstream MyReadFile("Questions.txt");
	string str = "";
	while (getline(MyReadFile, line)) {

		str = line;
		vector<string> v = User::split(str, ',');
		TQ[x].SetQuestion(v[0]); 
		TQ[x].SetAnswer(v[1]);
		x++;
	}
	MyReadFile.close();

	double mark = 0.0;
	double point = 100 / (double)Instructor::NOQTD;
	srand(time(0));
	for (int i = 0; i < Instructor::NOQTD; i++) { // answer Questions 

		int num = rand() % total + 1;
		std::string answer;
		std::cout << "\nQ" << i + 1 << ":" << TQ[num].GetQuestion() + '?' << std::endl; 
		std::cin >> answer;
		if (answer == TQ[num].GetAnswer()) mark += point;

	}
	std::cout << "\nGrade: " << mark << "/100";
	Student::SetMark(Student::stName, mark);
	delete[] TQ;
}