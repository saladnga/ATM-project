#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<random>
#include<fstream>
#include<cstdlib>

#include "User.h"

User::User(){
}


User::User(string id_, string pin_, long double balance_){
    this->id = id_;
    this->pin = pin_;
    this-> balance = balance_;
}

User::User(string id_){
    this->id = id_;
    ifstream inFi(id_+".txt");
    inFi>>this->pin;
    inFi>>this->balance;
    string friendID;
    while (inFi >> friendID) {
        this->friendsID.push_back(friendID);
    }
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

vector<string> User::getFriends(){
    return this->friendsID;
}

void User::update(){
    ofstream outFi(getID() + ".txt");
    outFi << getPIN() << " " << getBalance() << endl;
    for(int i = 0; i < getFriends().size(); i++){
        outFi << getFriends()[i] << endl;
    }
    outFi.close();
}

void User::add_Friend(string friendID){
    for (int i = 0; i < friendsID.size(); i++)
    {
        if (friendsID[i] == friendID)
            return;
    }
    this->friendsID.push_back(friendID);
    update();

    // this->friendsID.push_back(friendID);
}

bool User:: isFriend(string friendID){
    for(int i = 0; i < friendsID.size();i++){
        if(friendsID[i] == friendID){
            return true;
        }
    }
    return false;
}

string User::generateID(){
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

bool User::existAccount(string id){
    ifstream fi(id+".txt");
    return fi.good();
}

User::~User(){
}












