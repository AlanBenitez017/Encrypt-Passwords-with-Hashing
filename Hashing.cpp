/**
  Student Name: Alan Benitez
  File Name: Hashing.cpp
  Assignment number 1

  This class creates the hash table, inserts and search for a bucket
**/
#include "Hashing.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

//Default constructor
Hashing::Hashing(){
	map = new Node*[size];
	for(int i = 0; i < size; i++){
		map[i] = nullptr;
	}
}

//Hash function to do the actual hashing
int Hashing::HashFunction(string username){
	int key = 0;
	for(int i = 0; i < username.length(); i++){
		key +=(i+1) + username.at(i);
	}
	return key;
}

//Inserting an user and a password in the hash table
void Hashing::Insert(string username, string password) {
	int index = HashFunction(username);
	Node * temp = new Node(username, password);
	temp->next = map[index];
	map[index] = temp;
} 
  
//Searching an user inside of the hash table
string Hashing::Search(string username){
	int index = HashFunction(username);
	Node * temp = map[index];
	while(temp!= nullptr && temp->name != username){
		temp = temp->next;
	}
	string found = temp->GetPassword();
	return found;
}


