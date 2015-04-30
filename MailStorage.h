#include <string>
#include <vector>

#ifndef MAILSTORAGE_H
#define MAILSTORAGE_H

//Struct for mail
struct Mail {
    std::string message;
    Mail *next;
};

//struct for hash table
struct Account{
    std::string userName;
    std::string password;
    Mail *mailHead;

    Account(){};

    Account(std::string user_Name, std::string in_pass)
    {
        userName = user_Name;
        password = in_pass;
        Mail *mailHead = NULL;
    }

};

//Class for MailStorage header
class MailStorage {
    public:
        //Hash Table Functions
        MailStorage();
        ~MailStorage();
        void printAccounts();
        void insertAccount(std::string in_userName, std::string in_password);
        Account* findAccount(std::string in_title);
        void deleteAccount(std::string in_title);
        //Mail Linked List Functions
        void printMail(); //post order transversal for printing all mail
        void printMail(int num);


        //Mail Linked List Functions
        int getNewMail();

    protected:
    private:
        int tableSize = 10;
        std::vector<Account> *hashTable[10] = { NULL };
        int hashVal(std::string name, int s);


};

#endif // HASHTABLE_H
