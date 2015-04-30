#include "MailStorage.h"
#include <iostream>
#include <vector>

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

//Print All Accounts
void MailStorage::printAccounts(){
    bool emptyTable = true;

    for(int i = 0; i < tableSize; i++){
        if(hashTable[i] != NULL){
            for(int j = 0; j < hashTable[i]->size(); j++){
                cout << (*hashTable[i])[j].userName << endl;
                emptyTable = false;
            }
        }
    }

    if(emptyTable == true){
        cout << "empty" << endl;
        return;
    }
}

//Insert Account into tree
void MailStorage::insertAccount(string name, string password){
	int index = hashVal(name,tableSize);
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

//searches for Account and returns node pointer
int MailStorage::findAccount(string in_name){
//void MailStorage::findAccount(string in_name){
	int index = hashVal(in_name,tableSize);
	bool found = false;

	// If there is a node at this hash location.
	if (hashTable[index] != NULL)
	{
		// Loop through every vector index at this hash location.
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			// If we find the Account in the vector, return it.
			if ((*hashTable[index])[i].userName == in_name)
			{
				cout << index << ":" << (*hashTable[index])[i].userName << endl;
				found = true;
				//Account *temp;
				//temp = (*hashTable[index])[i];
				return i;
				break;
			}
		}
	}
	if (found == false)
	{
		cout << "not found" << endl;
	}
	return -1;
}

void MailStorage::deleteAccount(string in_name){
	int index = hashVal(in_name,tableSize);
	bool found = false;

	// If there is a node at this hash location.
	if (hashTable[index] != NULL)
	{
		// Loop through every vector index at this hash location.
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			// If we find the movie in the vector, delete it.
			if ((*hashTable[index])[i].userName == in_name)
			{
				hashTable[index]->erase(hashTable[index]->begin() + i);
				found = true;
				break;
			}
		}
		// If this was the last element in this chain, delete the vector.
		if (hashTable[index]->size() == 0)
		{
			delete hashTable[index];
			hashTable[index] = NULL;
		}
	}
	if (found == false)
	{
		cout << "not found" << endl;
	}
	return;
}

int MailStorage::getNewMail(string in_Name){
    //Find index of the Account
	int index = hashVal(in_Name,tableSize);
	//find where the Account is in Chaining
	int i = findAccount(in_Name);
	//go to Account and count mail
	Mail *node = ((*hashTable[index])[i].mailHead;
	int c = 0; // counting variable
	//counts the mail until the node is finished
	while(node != NULL){
        c++;
        node = node->next;
	}
	//return ammount of mail
	return c;
}

void MailStorage::printMail(string in_Name){
    //Find index of the Account
	int index = hashVal(in_Name,tableSize);
	//find where the Account is in Chaining
	int i = findAccount(in_Name);
	//go to Account at index and i
	//Checks if there is mail
	if(getNewMail((*hashTable[index])[i]) > 0){
        //If there is mail
        Mail *node = (*hashTable[index])[i]->mailHead;
        //Mail counter
        int c = 1;
        while(node != NULL){
            cout << "Message " << c << ":" << endl << node->message << endl;
        }
	}


}

void MailStorage::printMail(int s){
    //Find index of the Account
	int index = hashVal(in_Name,tableSize);
	//find where the Account is in Chaining
	int i = findAccount(in_Name);
	//go to Account at index and i
	//Checks if there is mail
	if(getNewMail((*hashTable[index])[i]) > 0){
        //If there is mail
        Mail *node = (*hashTable[index])[i]->mailHead;
        //Mail counter
        int c = 1;
        while(node != NULL){
            cout << "Message " << c << ":" << endl << node->message << endl;
        }
	}
}

int MailStorage::hashVal(string name, int s){
	int sum = 0;

    for (int i = 1; i < name.length(); i++)
    {
    	sum = sum + name[i];  //ascii value of ith character in the string
    }

    sum = sum % s;
    return sum;
}

//Private Function that Checks the Password against the password on file
bool MailStorage::checkPass(string name, string pass){
    //Find index of the Account
	int index = hashVal(name,tableSize);
	//find where the Account is in Chaining
	int i = findAccount(name);
	if(i >= 0){
        if((*hashTable[index])[i]->password == pass){
            cout << "Logged in. Successful" << endl;
            return true;
        }else{
            cout << "Incorrect UserName or Password" << endl;
            return false;
	}
	} else {
        cout << "User Not Found" << endl;
	}
}

//Deletes all mail occuring in an account
void MailStorage::deleteAllMail(string in_name){
    //Find index of the Account
	int index = hashVal(name,tableSize);
	//find where the Account is in Chaining
	int i = findAccount(name);
	if(getNewMail((*hashTable[index])[i]) > 0){
        //If there is mail
        Mail *node = (*hashTable[index])[i]->mailHead;
        //Mail counter
        while(node != NULL){
            node = node->next;
        }
}

//sends mail from one account to another
void MailStorage::sendMail(string name, string message){
    //Find index of the Account
	int index = hashVal(name,tableSize);
	//find where the Account is in Chaining
	int i = findAccount(name);
	if(i >= 0){
        //Found recipient
        Mail node = (*hashTable[index])[i]->mailHead;
        if((*hashTable[index])[i]->mailHead == NULL){
            //Add Message
            temp = new Mail;
            temp.message = message;
            temp.next = NULL;
            (*hashTable[index])[i]->mailHead = temp;
        } else {
            //go through list til the end
            while(node->next != NULL){
                node = node->next;
            }
            temp = new Mail;
            temp.message = message;
            temp.next = NULL;
            node->next = temp;
        }
	}else {
	    //Account doesnt exist
        cout << "Recipient " << name << "  was not found."<< endl;
	}
}
