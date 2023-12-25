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
    void Withdraw_money(int money);
    void Deposit_money(int money);
    void Transfer_money(string friendID, int money);
    void Transfer_friend();
    void Transfer_guest();
    void Transfer_menu();
    ~Menu();
};