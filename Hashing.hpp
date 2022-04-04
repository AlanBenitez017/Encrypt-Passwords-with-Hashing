/**
  Student Name: Alan Benitez
  File Name: Hashing.hpp
  Assignment number 1

  This class is the header of Hashing.cpp
**/

#ifndef HASHING_HPP
#define HASHING_HPP
#include <list>
#include <iterator>
#include <iostream>
#include "Node.hpp"
//#include "FileReader.hpp"
using namespace std;

class Hashing{
	private:
		Node ** map;
		const int size = 88007;
		
	public:
		Hashing();
		int HashFunction(string username);
		void Insert(string username, string password);
		string Search(string username);
		friend class Node;
		
};
#endif

