#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<random>
#include<fstream>
#include<cstdlib>
#pragma once
#include "User.h"

using namespace std;

class Menu{
public:
    User* user; 
    Menu();
    string CurrentID(string id);
    void mainMenu();
    void Login();
    void Register();
    void ATM_Menu();
    string generateID();
    bool validID(string id);
    bool validPIN(string pin);
    bool existAccount(string id);
    void ShowInfo();
    void Withdraw_money(long double money);
    void Deposit_money(long double money);
    void Transfer_money(string friendID, long double money);
    void Transfer_friend();
    void Transfer_guest();
    void Transfer_menu();
    // void update();
    ~Menu();
};