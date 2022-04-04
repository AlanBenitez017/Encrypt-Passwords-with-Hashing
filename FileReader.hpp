/**
  Student Name: Alan Benitez
  File Name: FileReader.hpp
  Assignment number 1

  This class is the header of the FileReader.cpp
**/

#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <string>
#include "Hashing.hpp"
using namespace std;

class FileReader{
    private:
        
    public:
        FileReader();
        string encryptPassword(string password);
        string generateKey(string key, string str);
        string cipherText(string key, string str);
        string originalText(string, string);
        void LegalTest();
		void IllegalTest();
        string createPassword();
        Hashing * h1 = nullptr;

};

#endif