#include<bits/stdc++.h>
using namespace std;

class User{
private:
    string id;
    string pin;
    long double balance;
public:
    User();
    vector<string>friendsID;
    User(string id_, int pin_ , long double balance_);
    User(string id_);
    string getID() const;
    void setID(string id_);
    string getPIN() const;
    void setPIN(int pin_);
    long double getBalance() ;
    void setBalance(long double balance_);
    void add_Friend(string friendID);
    bool isFriend(string friendID);
    ~User();
};