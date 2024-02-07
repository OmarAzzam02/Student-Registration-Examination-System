#ifndef U_H
#define U_H
#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include<Windows.h>
#include <sstream>
using namespace std;

class User {
protected:
    string UserName, Password, Major, FirstName, LastName, Email;
public:
    User(string user = "Unkown", string pass = "Unkown", string first = "Unkown", string last = "Unkown", string email = "Unkown", string major = "Unkown");
    static vector<string> split(string s, char delim);
    void SetUsertName(string name);
    void SetLastName(string last);
    void SetFirtName(string name);
    void SetEmail(string mail);
    void SetMajor(string major);
    void SetPassword(string pass);
    static  bool ValidUser(string user, string pass,int x);
    string GetFirstName();
    string GetUser();
    string GetPassword();
    string GetLastName();
    string GetEmail();
    string GetMajor();
    bool static CheckPassword(string pass);
    void static CreateProfile(int x); 



};

#endif