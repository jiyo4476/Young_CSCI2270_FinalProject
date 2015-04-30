#include <iostream>

#include "MailStorage.h"

using namespace std;

/*
This function is the main function of the program
*/
int main(int argc, char*argv[]){

    int input;

    // Create a new communication network
    MailStorage mh;

    // Flag used for exiting menu
    bool quit = false;
    //Flag used for LogedIn
    bool loggedIn = false;
    bool checkMail = false;

    // Used for input
    string userNam;
    string input1;
    string input2;

    //used for which menu to display
    int menuNum;

    while(quit != true)
    {
        displayMenu(menuNum);
        cin >> input;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input){
            // Insert a movie
            case 1:
                if(loggedIn == false){
                    //Login
                    cout << "Enter UserName:" << endl;
                    getline(cin,input1);
                    cout <<"Enter Password:" << endl;
                    getline(cin,input2);
                    //if login successful
                    if(mh.checkPass(input1,input2) == true){
                        loggedin = true;
                        userNam = input1;
                    }
                } else if(loggedIn == true && checkMail == false){
                    //Log out
                    userNam = "";
                    loggedIn = false;
                } else if(loggedIn == true && checkMail == true){
                    //Delete all Mail

                }
                break;
            case 2:
                if(loggedIn == false){
                    //Register an Account
                    cout << "Enter UserName:" << endl;
                    getline(cin,input1);
                    cout <<"Enter Password:" << endl;
                    getline(cin,input2);
                    //if login successful
                    mh.insertAccount(input1, input2);
                    cout << input1 << " has been registered." << endl;
                } else if(loggedIn == true && checkMail == false){
                    //Check Email
                    checkMail == true;
                } else if(loggedIn == true && checkMail == true){
                    //save mail (This part basicly does nothing
                }
                break;

            // Quit
            case 3:
                cout << "Goodbye!" << endl;
                quit = true;
                break;

            //Send mail
            case 4:
                if(loggedIn == false){
                    cout << "Invalid Selection" << endl;
                } else if(loggedIn == true && checkMail == false){
                    //Register an Account
                    cout << "Enter the UserName you wish to send a message to:" << endl;
                    getline(cin,input1);
                    cout <<"Enter your message:" << endl;
                    getline(cin,input2);
                    sendMail(input1, input2);
                } else if(loggedIn == true && checkMail == true){
                    cout << "Invalid Input" << endl;
                }
                break;
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }

    return 0;
}

/*
This function Displays the menu
    Menu One
    Option 1:Log in
    Option 2: Create Account
    Option 3: Quit

    Menu Two - Logged in
    Option 1: Log out
    Option 2: Check Email ---- (Emails)
    Menu Three - Check Mail
        -Read mail off one by one
        Option 1: Delete
        Option 2: Save
        Option 3: Quit
    If Log out, show menu One
*/
int displayMenu(int menu){
    //Main Menu
    if(menu == 1){
        cout << "Main Menu" << endl;
        cout << "1 - Log In" << endl;
        cout << "2 - Create Account" << endl;
        cout << "3 - Quit" << endl;
    //loged in
    }else if(menu == 2){
        cout << "Logged in" << endl;
        cout << "1 - Log Out" << endl;
        cout << "2 - Check Email" << endl;
        cout << "3 - Quit" << endl;
        cout << "4 - Send Mail" << endl;
    }else if(menu == 3)){
        cout << "MailBox" << endl;
        cout << "1 - Delete All Messages" << endl;
        cout << "2 - Save" << endl;
        cout << "3 - Quit" << endl;
    }
}
