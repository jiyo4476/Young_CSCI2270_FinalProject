#include <string>
#include <vector>

#ifndef MAILSTORAGE_H
#define MAILSTORAGE_H

//Struct for Logged in
struct Loggedin {
    bool open;
    std::string userName;
    int index;
    int vecIndex;

    Loggedin(){};

    Loggedin(std::string in_userName, int in_index, int in_vecIndex){
        userName = in_userName;
        index = in_index;
        vecIndex = in_vecIndex;
        open = true;
    }


};

//Struct for mail
struct Mail {
    std::string sender;
    std::string message;
    Mail *next;

    Mail(){};

    Mail(std::string in_sender, std::string in_message){
        sender = in_sender;
        message = in_message;
        next = NULL;
    }
};

//struct for hash table
struct Account{
    std::string userName;
    std::string password;
    Mail *mailHead;

    Account(){};

    Account(std::string user_Name, std::string in_pass){
        userName = user_Name;
        password = in_pass;
        mailHead = NULL;
    }

};
/*
struct Loggedin {
    bool logged;
    std:string userName;

    Loggedin(){};

    Login(std:string in_userName){

    }
};*/

//Class for MailStorage header
class MailStorage {
    public:
        //Hash Table Functions
        MailStorage(); //constructor
        ~MailStorage(); //Deconstructor
        void insertAccount(std::string in_userName, std::string in_password); //Create a New Account
        void printAccounts(); //Prints All Accounts in Hash Table CHECK
        int findAccount(std::string in_name); //Finds Account in Vector and returns the I value
        void deleteAccount(std::string in_name); // Deletes Account Out of Hash Table Including its mail
        void deleteAllAccounts();
        //Mail Linked List Functions
        void printMail(); //post order transversal for printing all mail
        void printMail(int num); // Print out a Cretain Email in the Vector
        void deleteAllMail(); //Deletes all the mail out of a indiviuals mailbox
        void deleteMail(int num);
        void sendMail(std::string in_name, std::string message); // sends mail to another Account
        //Mail Linked List Functions
        int getNewMail(); //returns the ammount of mail in mailbox
        bool LogIn(std::string name, std::string password);
        void LogOut();
        std::string getUserName();

    protected:
    private:
        int tableSize = 10;
        std::vector<Account> *hashTable[10] = { NULL };
        Loggedin OpenSession = Loggedin();
        int hashVal(std::string name);
};

#endif // HASHTABLE_H
