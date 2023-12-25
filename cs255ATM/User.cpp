#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<random>
#include<fstream>
#include<cstdlib>

#include "User.h"

User::User(){
    //Constructor Implementation
}


User::User(string id_, string pin_, long double balance_){
    this->id = id_;
    this->pin = pin_;
    this-> balance = balance_;
}

User::User(string id_){
    this->id = id_;
    ifstream inFi(id_+".txt");
    getline(inFi,this->id);
    string balance;
    getline(inFi,balance);
}

string User:: getID() const{
    return this->id;
}

void User:: setID(string id_){
    this->id = id_;
}

string User:: getPIN() const{
    return this->pin;
}

void User::setPIN(string pin_){
    this->pin = pin_;
}

long double User::getBalance(){
    return this->balance;
}

void User::setBalance(long double balance_){
    this->balance = balance_;
}

void User::add_Friend(string friendID){
    friendsID.push_back(friendID);
}

bool User:: isFriend(string friendID){
    for(int i = 0; i < friendsID.size();i++){
        if(friendID == friendsID[i]){
            return true;
        }
    }
    return false;
}

User::~User(){
    //Destructor Implementation
}













