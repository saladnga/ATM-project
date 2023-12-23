#include<bits/stdc++.h>
#include"User.h"

User::User(string id_){
    this->id = id_;
}

User::User(string id_, int pin_, long double balance_){
    this->id = id_;
    this->pin = pin_;
    this-> balance = balance_;
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

User::~User() {
    
}















