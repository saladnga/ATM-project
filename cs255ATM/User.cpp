#include<bits/stdc++.h>
#include"User.h"


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

bool User::validID(string id){
    return id.length() == 10;
}


bool User::validPIN(string pin){
    if(pin.length() != 6){
        return false;
    }
    for(int i=0; i < pin.length(); i++){
        if(!isdigit(int(pin[i]))){
            return false;
        }
        else continue;
    }
        return true;
}

string User:: generateID(){
    const int len = 10;
    string randomString;
    randomString.reserve(len);

    srand(time(0));
    for(int i = 0; i < len; ++i){
        char randomChar;
        while(true){ 
            randomChar = rand() % (122-48+1)+48;
            if(isalnum(randomChar)){
                break;
            }
        }
        randomString.push_back(randomChar);
    }

    return randomString;
}


bool User::existAccount(string id){
    ifstream inFile(id + ".txt");
    return inFile.good();
}








