#include<bits/stdc++.h>
#include"User.h"

User::User(){
    //Constructor Implementation
}


User::User(string id_, int pin_, long double balance_){
    this->id = id_;
    this->pin = pin_;
    this-> balance = balance_;
}

User::User(string id_){
    this->id = id_;
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

void User::setPIN(int pin_){
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













