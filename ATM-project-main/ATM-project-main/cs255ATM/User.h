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
    vector<string> friendsID ;
public:
    User();
    User(string id_, string pin_ , long double balance_);
    User(string id_);
    vector<string> getFriends();
    string getID() const;
    void setID(string id_);
    string getPIN() const;
    void setPIN(string pin_);
    long double getBalance() ;
    void setBalance(long double balance_);
    string generateID();
    bool validID(string id);
    bool validPIN(string pin);
    bool existAccount(string id);
    void add_Friend(string friendID);
    bool isFriend(string friendID);
    void Withdraw_money(long double money);
    void Deposit_money(long double money);
    void Transfer_money(string friendID, long double money);
    void update();
    ~User();
};