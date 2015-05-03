#include "MailStorage.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//Counstructor
MailStorage::MailStorage(){
    //Read in file

}

//Deconstructor
MailStorage::~MailStorage(){
    for(int i = 0; i <tableSize; i++){
        if(hashTable[i] != NULL){
            //Save Account

            //delete Account
            delete hashTable[i]; // Delete node
        }
    }
}

//Hash Function
int MailStorage::hashVal(string name){
	int sum = 0;

    for (int i = 1; i < name.length(); i++)
    {
    	sum = sum + name[i];  //ascii value of ith character in the string
    }

    sum = sum % tableSize;
    return sum;
}

//Insert Account into tree
void MailStorage::insertAccount(string name, string password){
	int index = hashVal(name);
	// If there is nothing in this location.
	if (hashTable[index] == NULL)
	{
		hashTable[index] = new vector<Account>;
		hashTable[index]->push_back(Account(name,password));
	}

	// If we need to add to a chain.
	else
	{
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			if ((*hashTable[index])[i].userName == name)
			{
				cout << "duplicate" << endl;
				return;
			}
		}
		hashTable[index]->push_back(Account(name,password));
	}

	return;
}

//Print All Accounts
void MailStorage::printAccounts(){
    bool emptyTable = true;

    for(int i = 0; i < tableSize; i++){
        if(hashTable[i] != NULL){
            emptyTable = false;
            for(int j = 0; j < hashTable[i]->size(); j++){
                cout << (*hashTable[i])[j].userName << endl;
            }
        } else {
                break; // break out of for loop if There are no Accounts
        }
    }

    if(emptyTable == true){
        cout << "empty" << endl;
        return;
    }
}

//searches for Account and returns node pointer
int MailStorage::findAccount(string in_name){
//void MailStorage::findAccount(string in_name){
	int index = hashVal(in_name);
	bool found = false;

	// If there is a node at this hash location.
	if (hashTable[index] != NULL){
		// Loop through every vector index at this hash location.
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			// If we find the Account in the vector, return it.
			if ((*hashTable[index])[i].userName == in_name)
			{
				cout << index << ":" << (*hashTable[index])[i].userName << endl;
				found = true;
				return i;
			}
		}
	}
	//Return -1 if false
	if (found == false)
	{
		cout << "not found" << endl;
        return -1;
	}
}

void MailStorage::deleteAccount(string in_name){

	int index = hashVal(in_name);
	int found = findAccount(in_name);

	if(found >= 0) {//If Account is found
        //Delete Account
        hashTable[index]->erase(hashTable[index]->begin() + found);
    }else { //Account is not found
		cout << "not found" << endl;
    }
}

void MailStorage::deleteAllAccounts(){
    //Delete all mail
    for(int i = 0; i < tableSize; i++){
        if(hashTable[i] != NULL){
            while(hashTable[i] != NULL){
                delete hashTable[i];
            }
        }
    }
}


void MailStorage::printMail(){
    if(OpenSession.open == true){
        //Checks if there is mail
        if(getNewMail() > 0){
            int input; //For Menu Options After
            //If there is mail
            Mail *node = (*hashTable[OpenSession.index])[OpenSession.vecIndex].mailHead;
            //Mail counter
            int c = 1;
            while(node != NULL){
                cout << "Message " << c << ":" << endl << node->message << endl << endl;
                c++;
                node = node->next;
            }
            cout << "1- Delete All Mail? " << endl;
            cout << "2- OpenMail" << endl;
            cout << "3- Main Menu" << endl;
            cin >> input;
            switch (input){
                case 1:
                    cout << "Deleteing....." << endl;
                    deleteAllMail();
                    break;
                case 2:
                    int input1;
                    cout << "Enter The Message Number that you wish to open." << endl;
                    cin >> input1;
                    printMail(input1);
                    break;
                case 3:
                    //leaving the function
                    break;
            }

        }
    } else{    //If Not Logged in
        cout << "You are Not Logged in." << endl;
    }
}

void MailStorage::printMail(int num){
    if(OpenSession.open == true){
        if(num > getNewMail() || num < getNewMail()) {
                cout << "Invalid Selection" << endl;
        } else {
        //sets C to the index of the mail
        int input;
        int c = num - 1;
        Mail *node = (*hashTable[OpenSession.index])[OpenSession.vecIndex].mailHead;
        for(int i =0; i < c; i++){
            node=node->next;
        }

        cout << "Message " << num << ":" << endl << node->message << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1- Delete Message? " << endl;
        cout << "2- Main Menu" << endl;
        cin >> input;
        switch (input){
            case 1:
                cout << "Deleteing....." << endl;
                deleteMail(c);
                break;
            case 2:
                //leaving the function
                break;
            default:{
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
            }
        }
        }
    }else {  //If Not Logged in
        cout << "You are Not Logged in." << endl;
    }
}

void MailStorage::deleteMail(int num){
    if(OpenSession.open == true){
        //sets C to the index of the mail
        int c = 1;
        Mail *node = (*hashTable[OpenSession.index])[OpenSession.vecIndex].mailHead;
        Mail *prvNode;

        while(c < num){
            prvNode = node;
            node = node->next;
            c++;
        }
        //if next node doesnt exist
        if(node->next == NULL){
            delete[] node;
        //Next node does exist
        } else {
            prvNode->next = node->next;
            delete[] node;
        }
    }else {   //If Not Logged in
        cout << "You are Not Logged in." << endl;
    }
}

int MailStorage::getNewMail(){
    if(OpenSession.open == true){
        //go to Account and count mail
        Mail *node = ((*hashTable[OpenSession.index])[OpenSession.vecIndex].mailHead);
        int c = 0; // counting variable
        //counts the mail until the node is finished
        while(node != NULL){
            c++;
            node = node->next;
        }
        return c;
    } else {
        cout << "Your are not logged in." << endl;
    }
}

//Public Function that Checks the Password against the password on file
bool MailStorage::LogIn(string name, string in_pass){
    //Find index of the Account
	int index = hashVal(name);
	//find where the Account is in Chaining
	int i = findAccount(name);

	//If Account is Found
	if(i >= 0){
        if((*hashTable[index])[i].password == in_pass){
            OpenSession.userName = (*hashTable[index])[i].userName;
            OpenSession.index = index;
            OpenSession.vecIndex = i;
            OpenSession.open = true;
            cout << "Logged in. Successful" << endl;
            return true;
        }else{
            cout << "Incorrect UserName or Password" << endl;
            return false;
        }
	} else {
        cout << "User Not Found" << endl;
        return false;
	}
}

//Deletes all mail occuring in an account
void MailStorage::deleteAllMail(){
    Mail *temp;
    //if Session is Open
    if(OpenSession.open == true){
        //if has mail
        if(getNewMail() > 0){
            //If there is mail
            Mail *node = (*hashTable[OpenSession.index])[OpenSession.vecIndex].mailHead;
            //Mail counter
            while(node != NULL){
                temp = node->next;
                delete []node;
                node = temp;
            }
        } else {
            cout << "No Mail to delete" << endl;
        }
    }
}

//sends mail from one account to another
void MailStorage::sendMail(string in_rec, string message){
    if(OpenSession.open == true){
        //Find index of the Recipiant
        int index = hashVal(in_rec);
        //find where the Account is in Chaining
        int i = findAccount(in_rec);
        //If Found Recipient
        if(i >= 0){
            //Found recipient
            Mail *node = (*hashTable[index])[i].mailHead;
            if((*hashTable[index])[i].mailHead == NULL){
                //Add Message
                Mail *temp = new Mail(OpenSession.userName, message);
                (*hashTable[index])[i].mailHead = temp;
                cout << "Your Mail has been sent." << endl;
            } else {
                //go through list til the end
                while(node->next != NULL){
                    node = node->next;
                }
                //place message at the end.
                Mail *temp = new Mail(OpenSession.userName, message);
                node->next = temp;
                cout << "Your Mail has been sent." << endl;
            }
        } else {
	    //Account doesnt exist
        cout << "Recipient " << in_rec << "  was not found."<< endl;
        }
    } else {
	    //Account doesnt exist
        cout << "You are not Logged in."<< endl;
	}
}

//Log Out of Account
void MailStorage::LogOut(){
    OpenSession.open = false;
}

//Returns UserName
string MailStorage::getUserName(){
    return OpenSession.userName;
}
