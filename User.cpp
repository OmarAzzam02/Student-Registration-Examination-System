#include "User.h"
vector<string>  User::split(string s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

User::User(string user, string pass , string first , string last, string email ,string major ) {
    UserName = user;
    Password = pass;
    Major = major;
    FirstName = first;
    LastName = last;
    Email = email;
}

void User::SetUsertName(string name) { UserName = name; }
void User::SetLastName(string last) { LastName = last; }
void User::SetFirtName(string name) { FirstName = name; }
void User::SetEmail(string mail) { Email = mail; }
void User::SetMajor(string major) { Major = major; }
void User::SetPassword(string pass) {}
   


 bool User::ValidUser(string user, string pass,int x) {
    string line;
    fstream MyReadFile;
    MyReadFile.open("User.txt", std::ios::in);
    bool flag = false;
    switch (x) {

    case 1:{

        while (getline(MyReadFile, line)) {

            string str = line;
            vector<string> v = split(str, ',');

            if (v[0] == user && v[1] == pass && v[2] == "1")
                flag = true;
            //cout << "Student found ";
            
        }
       
    }break; // end of switch case 1 (student)
 ///----------------------------------------------------------

    case 2: {

        while (getline(MyReadFile, line)) {

            string str = line;
            vector<string> v = split(str, ',');

            if (v[0] == user && v[1] == pass && v[2] == "2")
                flag = true;
            //cout << "Instructor found ";
            
        }
     

    }break; // end of switch case 2(Instructor)

    } // end of switch case

    MyReadFile.close();

    if (flag) std::cout << "User Found\n"; else std::cout << "\nyour username or password is incorrect\n";
    return flag;
}

 string User::GetFirstName()
 {
     return FirstName;
 }

 string User::GetUser()
 {
     return UserName;
 }

 string User::GetPassword()
 {
     return Password;
 }

 string User::GetLastName()
 {
     return LastName;
 }

 string User::GetEmail()
 {
     return Email;
 }

 string User::GetMajor()
 {
     return Major;
 }

 bool User::CheckPassword(string pass)
 {
     int sepecials = 0;

     for (int i = 0; i < pass.length(); i++) {

         if (pass[i] > 33 && pass[i] < 127)
             sepecials++;
     }
     if (pass.length() > 8 && sepecials != 0) return true;
     else {
         std::cout << "\n Your Password Must Be Atleast 8 Chatecters Long And Have Symbols  \n";
         return false;
     }

 }
 void User::CreateProfile(int x) {
     switch (x) {
     case 1: {
         string FirstName, LastName, Major, Email;
         cout << "Enter the Firs tName: "; cin >> FirstName;
         cout << "Enter the Last tName: "; cin >> LastName;
         cout << "Enter your Major: "; cin >> Major;
         cout << "Enter your Email: "; cin >> Email; 
         ofstream file;
             file.open("StudentInfo.txt");
             file << FirstName << "," << LastName << "," << Major << "," << Email << endl;
             file.close();
     }break; 
     case 2: {
         string FirstName, LastName, Major, Email;
         cout << "Enter the Firs tName: "; cin >> FirstName;
         cout << "Enter the Last tName: "; cin >> LastName;
         cout << "Enter your Major: "; cin >> Major;
         cout << "Enter your Email: "; cin >> Email;
         ofstream file;
         file.open("InstructorInfo.txt");
         file << FirstName << "," << LastName << "," << Major << "," << Email << endl;
         file.close();
     }break;
         
         
     }
 }