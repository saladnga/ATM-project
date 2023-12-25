#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<random>
#include<fstream>
#include<cstdlib>
#pragma once

using namespace std;

class User {
private:
    string id;
    string pin;
    long double balance;
public:
    vector<string> friendsID;
    User();
    User(string id_, string pin_ , long double balance_);
    User(string id_);
    string getID() const;
    void setID(string id_);
    string getPIN() const;
    void setPIN(string pin_);
    long double getBalance() ;
    void setBalance(long double balance_);
    void add_Friend(string friendID);
    bool isFriend(string friendID);
    ~User();
};