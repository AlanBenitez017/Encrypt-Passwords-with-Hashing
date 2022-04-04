/**
  Student Name: Alan Benitez
  File Name: FileReader.cpp
  Assignment number 1

  This class reads the lastNames.txt, and basically, encrypts the password and executes
**/

#include "FileReader.hpp"
#include "Hashing.hpp"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//Default Constructor, creates raw.txt and creates encrypted.txt
//Here I am doing pretty much all the work, calling the functions that I need
//in order to run the program
FileReader::FileReader(){

    ofstream encryptedtxt;
    ofstream os;
    ifstream is;
    h1 = new Hashing();
    is.open("lastNames.txt");
    os.open("raw.txt");
    encryptedtxt.open("encrypted.txt");
    if(is.is_open()){
        int i = 0;
        string input;
        srand(time(NULL));
        while(!is.eof()){
            is >> input;
            if(i % 4 == 0){
                string password = "";
                password = createPassword();
                os << input + " " + password << endl;
                string encrypt = encryptPassword(password);
                encryptedtxt << input << " " << encrypt << endl;
                h1->Insert(input, encrypt);
            }
            i++;
        }
    }
    LegalTest();
    IllegalTest();
}

//In this method I am generating a key that will be used to encrypt the passwords
string FileReader::generateKey(string str, string key){
    int x = str.size(); 

    for (int i = 0; ; i++) 
    { 
        if (x == i) 
            i = 0; 
        if (key.size() == str.size()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key; 
}

//The purpose of this method is to cipher the text and is where it actually encrypts the password
string FileReader::cipherText(string str, string key){
    string cipher_text; 

    for (int i = 0; i < str.size(); i++) { 
        // converting in range 0-25 
        char x = (str[i] + key[i]) %26; 

        // convert into alphabets(ASCII) 
        x += 'a'; 
        cipher_text.push_back(x); 
    } 
    return cipher_text; 
}

//Here's where I encrypt the password
string FileReader::encryptPassword(string password){
    string str = password; 
    string keyword = "MOGE";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    string key = generateKey(str, keyword); 
    string cipher_text = cipherText(str, key);
    string ogtxt = originalText(cipher_text, key);
    transform(ogtxt.begin(), ogtxt.end(), ogtxt.begin(), ::tolower);
    return cipher_text;
}

//Just for testing purposes, to see if the unecrypted file matches with the original text
string FileReader::originalText(string cipher_text, string key){
    string orig_text; 
    for (int i = 0 ; i < cipher_text.size(); i++) 
    { 
        // converting in range 0-25 
        char x = (cipher_text[i] - key[i] + 26) %26; 

        // convert into alphabets(ASCII) 
        x += 'a'; 
        orig_text.push_back(x); 
    } 
    return orig_text; 
}

//Here I am creating a password
string FileReader::createPassword(){
    char c;
    int r;
    string password;
    for(int i = 0; i < 9; i++){
        r = rand() % 26;
        c = 'a' + r;
        password = password + c;
    }
    return password;
}

//Here I am testing if the encrypted passwords are the llegal
void FileReader::LegalTest(){

    ifstream is;
    is.open("raw.txt");
    string name = " ";
    string line = " ";
    string password  = "";
    string encrypted = "";
    int count = 0;
    cout << "Legal:" << endl;
    cout << "UserId" << "\t" << "\t" << "Password" << "\t" << "Result" << endl;
    if(is.is_open()){
        while(count < 5){
            getline(is, line, '\n');
            name = line.substr(0, line.find(" "));
            password = line.substr(line.find(" ") + 1, line.length());
            password = encryptPassword(password);
            encrypted = h1->Search(name);
            if(password.compare(encrypted) == 0){
                cout << name << "\t" << "\t" << password << "\t" << "match" << endl;
            }
            count++;
        }
    }
    cout << endl;
}

//Here I am testing if the encrypted passwords are the illegal
void FileReader::IllegalTest(){
    ifstream is;
    is.open("raw.txt");
    string name = " ";
    string line = " ";
    string password  = "";
    string encrypted = "";
    int count = 0;
    cout << "Illegal:" << endl;
    cout << "UserId" << "\t" << "\t" << "Password" << "\t" << "Result" << endl;
    if(is.is_open()){
        while(count < 5){
            getline(is, line, '\n');
            name = line.substr(0, line.find(" "));
            password = line.substr(line.find(" ") + 1, line.length());
            password = encryptPassword(password);
            password.at(0) = 'x';
            encrypted = h1->Search(name);
            if(password.compare(encrypted) != 0){
                cout << name << "\t" << "\t" << password << "\t" << "no match" << endl;
            }
            count++;
        }
    }
    cout << endl;
}
