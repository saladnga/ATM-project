#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<random>
#include<fstream>
#include<cstdlib>

#include"../Header Files/User.h"
#include"../Header Files/Menu.h"
using namespace std;


Menu::Menu(){
}

string Menu::CurrentID(string id){
    User user(id);
    return user.getID();
}

string currentID;

void Menu::mainMenu(){
    while(true){
        int option;
        cout << "\n";
        cout << "==============Welcome to the ATM==============" << endl;
        cout << "1.Login" << endl;
        cout << "2.Register" << endl;
        cout << "3.Exit" << endl;
        cout << "==============================================" << endl;
        cout << "Choose your option: ";
        cin >> option;
        if(option == 1){
            Login();
            continue;
        }
        else if(option == 2){
            Register();
            continue;
        }
        else if(option == 3){
            exit(0);
        }
        else{
            cout << "Enter your option again, please!" << endl;
            continue;
        }
    }
}

void Menu::Login(){
    cin.ignore();
    string id;
    string pin;
    cout << "Enter your ID: ";
    getline(cin,id);
    ifstream fi(id + ".txt");
    if(!fi){
        cout << "Invalid ID" << endl;
        mainMenu();
        return;
    }
    fi.close();
    User iUser(id);
    cout << "Enter your 6-digit PIN numbers: ";
    getline(cin, pin);
    string truePIN= iUser.getPIN();
    if(pin != truePIN){
        cout << "Invalid PIN" << endl;
        mainMenu();
        return;
    }
    this->user = &iUser;
    cout << "Login successfully!" << endl;
    ATM_Menu();
}

void Menu::Register(){
    cin.ignore();
    string new_id = generateID();
    cout << "Your new ID: " + new_id << endl;
    User user(new_id);
    string pin;
    int balance = 0;
    while(true){
        cout << "Enter your new 6-digit PIN numbers: ";
        getline(cin,pin);
        if(!validPIN(pin)){
            continue;
        }
        else {
            user.setPIN(pin);
            user.setBalance(balance);
            break;
        }
    }
    ofstream outFi(new_id+ ".txt");
    outFi << pin << " " << balance;
    outFi.close();
    cout << "Register successfully!" << endl;
}



string Menu::generateID(){
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

bool Menu::validID(string id){
    return id.length() == 10;
}

bool Menu::validPIN(string pin){
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

bool Menu::existAccount(string id){
    ifstream fi(id+".txt");
    return fi.good();
}

void Menu::ATM_Menu(){
    while(true){
        int choice;
        cout << "\n";
        cout << "==================ATM Menu================" << endl;
        cout << "1. Account Information" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Deposit money" << endl;
        cout << "4. Transfer money" << endl;
        cout << "5. Log out" << endl;
        cout << "==========================================" << endl;
        cout << "Chose your option: ";
        cin >> choice;
        if(choice == 1){
            cout << "Your Account information:" << endl;
            ShowInfo();
            continue;
        }

        if(choice == 2){
            while(true){
                cout << "Enter the amount of money you want to withdraw: ";
                int money;
                cin >> money;
                int value = user->getBalance();
                if(money <= 0){
                    cout << "Invalid Money" << endl;
                    break;
                }
                else if(value <= money){
                    cout << "Not Enough Money!" << endl;
                    break;
                }
                else {
                    Withdraw_money(money);
                    cout << "Withdraw Money Successfully!" << endl;
                    break;
                }
            }
            continue;
        }

        else if(choice == 3){
            while(true){
                cout << "Enter the amount of money you want to deposit: ";
                int money;
                cin >> money;
                if (money < 0) {
                    cout << "The amount of money you want to deposit cannot be negative. Please try again!" << endl;
                }
                else {
                    Deposit_money(money);
                    cout << "Deposit Money Successfully!" << endl;
                    break;
                }
            }
            continue;
        }

        else if(choice == 4){
            vector<string>listFriend = user->getFriends();
            for(int i = 0; i< listFriend.size(); i++){
                cout << listFriend[i] << endl;
            }
            cin.ignore();
            while(true){
                cout << "Who do you want to transfer money to? ";
                string friendID;
                getline(cin,friendID);
                if(existAccount(friendID)){
                    while(true){
                        int money;
                        cout << "What is the amount of money you want to transfer? ";
                        cin >> money;
                        if(user->getBalance() < money){
                            cout << "You do not have enough money!" << endl;
                            break;
                        } 
                        else if (money <= 0) {
                            cout << "Invalid Money" << endl;
                            break;
                        }
                        else {
                            Transfer_money(friendID,money);
                            cout << "Money Transferred Successfully" << endl;
                            break;
                        }
                    }
                    if(!user->isFriend(friendID)){
                        while(true){
                            cin.ignore();
                            string ans;
                            cout << "Do you want to add the ID as your friend?(y/n) ";
                            getline(cin,ans);
                            if(ans == "y"){
                                user->add_Friend(friendID);
                                cout << "Add Friend Successfully!" << endl;
                                return ATM_Menu();
                            }
                            else if(ans == "n"){
                                return ATM_Menu();
                            }
                            else continue;
                        }
                    }

                    else break;
                }
                else{
                    cout << "This account does not exist, please check again!" << endl;
                    continue;
                }
            }
            continue;
        }
        else if(choice == 5){
            break;
            mainMenu();
        }
        else{
            cout << "Choose again, please!" << endl;
            continue;
        }
    }
}

void Menu::ShowInfo(){
    cout << "Account ID: " << this->user->getID() << endl;
    cout << "Account Balance: " << this->user->getBalance() << endl;
    vector<string> listFriends = this->user->getFriends();
    cout << "Friendly Account IDs: ";
    if (listFriends.size() == 0){
        cout << "[]\n";
    }
    else{
        cout << "\n";
    }
    for (int i = 0; i < listFriends.size(); i++){
        cout << " - " << listFriends[i] << endl;
    }
}

void Menu::Withdraw_money(int money){
    user->setBalance(user->getBalance() - money);
    user->update();
}

void Menu::Deposit_money(int money){
    user->setBalance(user->getBalance() + money);
    user->update();
}

void Menu::Transfer_money(string friendID, int money){
    user->setBalance(user->getBalance() - money);
    user->update();
    string friend_id;
    int friend_balance;
    ifstream inFi(friendID + ".txt");
    inFi >> friend_id;
    inFi >> friend_balance;
    friend_balance += money;
    inFi.close();
    ofstream outFi(friendID + ".txt");
    outFi << friend_id << " " << friend_balance << endl; 
    outFi.close();
}

Menu::~Menu(){
}