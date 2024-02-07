#include <iostream>
#include<windows.h>
#include<string>
#include"Admin.h"

int  dispalyMainMenu();

int main() {
    
    bool move = true;
    int choice = dispalyMainMenu();

    while (choice > 0) {   //Student -> Chang PassWord


        switch (choice) {//main menu
        default: {std::cout << "\nYou Exited The System \n"; std::exit(0); }  break;
        case 1: {
            // if  User choose Admin
            system("cls");
            while (true) {
                int adminChoice = Admin::displayAdminMenu();
                system("cls");
                switch (adminChoice) {

                case 1: {     /* if Admin Choose Student (1) */
                    Student::displayStudentInAdmin();
                    std::cout << "Enter (0) to return to main menu or Enter (1) to admin menu";
                    std::cin >> move;
                    system("cls");
                    if (!move) main();


                } break; // break for admin choice case 1


                case 2: {                                                       /* if Admin Choose Instructor (2) */
                    Instructor::displayInstructorInAdmin();
                    std::cout << "Enter (0) to return to main menu or Enter (1) to admin menu";
                    std::cin >> move;
                    system("cls");
                    if (move == false) main();


                }  break;
                default: main(); break;
                } // end the inside switch for admin  inside menu

            } // end inside while loop 

        } break; // end switch case for admin
        case 2: { /*if User Choose Student*/
            system("cls");
            while (true) {

                int studentChoice = Student::displayStudentLogin();
                system("cls");
                switch (studentChoice) {
                case 1: {                                                    /*If Studetn Choose Change Info*/
                    User::CreateProfile(1);

                } break; // break for change info
                case 2: { /*student --> change paassword*/
                    system("cls");
                    std::cout << "Enter Current Password: ######### \n";
                    std::cout << "Enter New Password: $$$$$$ \n";
                    std::cout << "Re-Enter New Password: $$$$$$ \n";
                } break;  /*Start Of student -> Sart Exam */
                case 3: {
                    system("cls");
                    Question::DisplayQuestion();
                } break; // End Of Student --> Start Exam
                default: main(); break;

                }// end of switch case student  

                std::cout << "Enter (0) to return to main menu and Enter (1) return to previous  menu";
                std::cin >> move;
                system("cls");
                if (move == false) main();
            } // end of Student case 2: loop       

        }break; //end switch case for Student 
        case 3: {
            system("cls");
            while (true) {
                int instructorChoice = Instructor::displayInstructorLogin();
                system("cls");
                switch (instructorChoice) {
                case 1: {             /* Instructor->changeInfo*/
                    system("cls");
                    User::CreateProfile(2);
                }break;    /*End Of Instructor->changeInfo*/
                case 2: {
                    system("cls");
                    std::cout << "Enter Current Password: ######### \n";
                    std::cout << "Enter New Password: $$$$$$ \n";
                    std::cout << "Re-Enter New Password: $$$$$$ \n";
                } break;  //End Of Instructor -> Change Password 
                case 3: {
                    system("cls");
                    Question::displayQsInInstructor();
                }break; // End Of Create Quastions
                case 4: {
                    system("cls");
                    Instructor::PrintExamResults();
                } break; // End Of Shoe Results 
                default: main(); break;

                } //End Of instructor Choice switch case
                std::cout << "Enter (0) to return to main menu and Enter (1) return to previous  menu";
                std::cin >> move;
                system("cls");
                if (move == false) main();
            } //End of Instructor Loop

        }break;  // End switch case for Instructor
        } // end of Main Menu Switch Case
    } // End For Main While loop


}// end main
//-----------------------------------------------------------
int  dispalyMainMenu() {
    int mainMenu;
    std::cout << "------------------Welcome to our Online Examanation System------------------- \n";
    std::cout << "Please Enter Your User Type:  \n";
    std::cout << "1- Admin\n";
    std::cout << "2- Student  \n";
    std::cout << "3- Instructor\n";
    std::cout << "4- exit system \n\n";
    std::cin >> mainMenu;
    return mainMenu;
}
