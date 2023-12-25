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
    void ShowInfo();
    ~Menu();
};