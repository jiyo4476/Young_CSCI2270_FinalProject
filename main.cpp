#include <iostream>

#include "MailStorage.h"

using namespace std;

/*
This function is the main function of the program
*/
int main(){

}


/*
This Function handles the login of the user.
*/
int login(std::string userName, std::string password){
    //Search for User
    //
    //Check if password is correct
    if(password == user.pass){
        cout << "Log In successfull" << endl;
        //change boolean logined in to true
        //
    } else {
        cout << "Invalid Username or Password." << endl;
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
int displayMenu(int menu){
    //Main Menu
    if(menu == 1){
        cout << "Main Menu" << endl;
        cout << "1 - Log In" << endl;
        cout << "2 - Create Account" << endl;
        cout << "3 - Quit" << endl;
    }else if(menu == 2){
        cout << "Logged in" << endl;
        cout << "1 - Log Out" << endl;
        cout << "2 - Check Email" << endl;
        cout << "3 - Quit" << endl;
    }else if(menu == 3)){
        cout << "MailBox" << endl;
        cout << "1 - Delete" << endl;
        cout << "2 - Save" << endl;
        cout << "3 - Quit" << endl;
    }
}
