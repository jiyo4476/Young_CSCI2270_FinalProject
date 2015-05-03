#include <iostream>

#include "MailStorage.h"

using namespace std;


void displayMenu(int menu);
/*
This function is the main function of the program
*/
int main(int argc, char*argv[]){

    int input;
    int menuNum = 1;

    // Create a new communication network
    MailStorage Post;

    // Flag used for exiting menu
    bool quit = false;

    // Used for input
    string input1;
    string input2;
    int input3;

    while(quit != true){
        displayMenu(menuNum);
        cin >> input;

        cin.clear();
        cin.ignore(10000,'\n');

        if(menuNum == 1){
                switch (input) {
                    case 1:{ // Log In
                        cout << "-----Log In------" << endl;
                        cout << "UserName: " << endl;
                        getline(cin, input1);
                        cout << "Password: " << endl;
                        getline(cin, input2);
                        if(input1 == "admin" && input2 == "admin"){
                            cout << "You Have Entered Administrator Mode." << endl;
                            menuNum = -1;
                        }else {
                            bool logged = Post.LogIn(input1 ,input2);
                            //Change Menu to Logged in Menu
                            if(logged == true){
                                menuNum = 2;
                            }
                        }
                        break;
                    }
                    case 2: {// Create Account
                        cout << "-----Create Account------" << endl;
                        cout << "UserName: " << endl;
                        getline(cin, input1);
                        cout << "Password: " << endl;
                        getline(cin, input2);
                        Post.insertAccount(input1 ,input2);
                        break;
                    }
                    case 3: //Quit
                        cout << "GoodBye!" << endl;
                        quit = true;
                        break;
                    default:{
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                        break;
                    }
                }
            }else if(menuNum == 2){
                switch(input) {
                    case 1:{ //Log Out
                        Post.LogOut();
                        menuNum = 1;
                        break;
                    }
                    case 2:{ //Show All Mail
                        Post.printMail();
                        break;
                    }
                    case 3: {//print Mail Number
                        cout << "Print Mail #: " << endl;
                        cin >> input3;
                        Post.printMail(input3);
                        break;
                    }
                    case 4:{ //Send Mail
                        cout << "Recipeint Name: " << endl;
                        getline(cin, input1);
                        cout << "Message: " << endl;
                        getline(cin, input2);
                        Post.sendMail(input1, input2);
                        break;
                    }
                    case 5:{
                        cout << "Closing Account..." << endl;
                        Post.deleteAccount(Post.getUserName());
                        break;
                    }
                    case 6:{ // Quit
                        quit = true;
                        break;
                    }
                    default:{
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                        break;
                    }
                }
        }else if(menuNum == -1){
                switch(input) {
                    case 1:{ //Print Accounts
                        Post.printAccounts();
                        break;
                    }
                    case 2:{ //Delete Account
                        cout << "Print Mail #: " << endl;
                        getline(cin, input1);
                        Post.deleteAccount(input1);
                        break;
                    }
                    case 3: {//Delete all Accounts
                        Post.deleteAllAccounts();
                        break;
                    }
                    case 4: {//Return to main Menu
                        menuNum = 1;
                        break;
                    }
                    case 5: {
                        quit = true;
                        break;
                    }
                    default:{
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                        break;
                    }
                }
        }
        cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
    }
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
void displayMenu(int menu){
    //Main Menu
    if(menu == 1){
        cout << "-------Main Menu---------" << endl;
        cout << "1 - Log In" << endl;
        cout << "2 - Create Account" << endl;
        cout << "3 - Quit" << endl;
    //loged in
    }else if(menu == 2){
        cout << "---------Logged in----------" << endl;
        cout << "1 - Log Out" << endl;
        cout << "2 - Show All Mail" << endl;
        cout << "3 - Open Mail #: " << endl;
        cout << "4 - Send Mail" << endl;
        cout << "5 - Close(Delete) Account" << endl;
        cout << "6 - Quit" << endl;
    }else if(menu == -1){
        cout << "----ADMINISTRATOR MENU----" << endl;
        cout <<"1- Print Accounts" << endl;
        cout <<"2- Delete Account" << endl;
        cout <<"3- Delete All Accounts" << endl;
        cout <<"4- Return to Main Menu" << endl;
        cout <<"5-Quit" << endl;
    }
}
