/**
  Student Name: Alan Benitez
  File Name: Node.cpp
  Assignment number 1

  This class creates the necessary nodes to use in the Hash table
**/

#include "Node.hpp"
using namespace std;

//Default Constructor, initializing the variables
Node::Node(){
	name = "";
	password = "";
	next = nullptr;	
}

//Overloaded constructor
Node::Node(string name, string password){
	this->name = name;
	this->password = password;
	next = nullptr;
}

//Getter
string Node::GetPassword(){
	return password;
}