#include<bits/stdc++.h>
using namespace std;

class Menu{
public:
    Menu();
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
    void Transfer_money();
    void update();
    ~Menu();
};