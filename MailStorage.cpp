#include "MailStorage.h"
#include <iostream>

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
Account *MailStorage::findAccount(string in_name){
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
				//return temp;
				break;
			}
		}
	}
	if (found == false)
	{
		cout << "not found" << endl;
	}
	return;
}

void MailStorage::deleteAccount(){
	int index = hashVal(name,tableSize);
	bool found = false;

	// If there is a node at this hash location.
	if (hashTable[index] != NULL)
	{
		// Loop through every vector index at this hash location.
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			// If we find the movie in the vector, delete it.
			if ((*hashTable[index])[i].title == name)
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

void MailStorage::printMail(string in_Name){

}

void MailStorage::printMail(int ){

}

int MailStorage::getNewMail(){

}

void MailStorage::getNewMail(){

}

int MailStorage::hashVal(string name, int s){

}




