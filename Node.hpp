/**
  Student Name: Alan Benitez
  File Name: Node.cpp
  Assignment number 1

  This class is the header of the Node.cpp class
**/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

using namespace std;

class Node{
	
	private:
                string name;
                string password;
	public:
                Node();
                Node(string name, string password);
                Node * next;
                friend class Hashing;
                string GetPassword();
};
#endif

