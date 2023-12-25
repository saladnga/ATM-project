#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<random>
#include<fstream>
#include<cstdlib>

#include"Menu.h"
#include"User.h"
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
        cout << "MENU before getting in the bank online" << endl;
        cout << "1.Login" << endl;
        cout << "2.Register" << endl;
        cout << "3.Exit" << endl;
        cout << "Choose your option: ";
        cin >> option;
        if(option == 1){
            Login();
        }
        else if(option == 2){
            Register();
            cout << "Register successfully!" << endl;
            continue;
        }
        else if(option == 3){
            system("cls");
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
    cout << "Enter your ID: ";
    string id;
    string pin;
    getline(cin,id);
    ifstream fi(id+".txt");
    if(!fi){
        cout << "Invalid ID" << endl;
        mainMenu();
        return;
    }

    User iUser(id);
    cout << "Enter your 6-digit PIN numbers: ";
    getline(cin, pin);
    string truePIN= iUser.getPIN();
    if(pin != truePIN){
        cout << "Invalid PIN" << endl;
        mainMenu();
        return;
    }

    fi.close();
    cout << "Login successfully!" << endl;
    
    this->user = &iUser;
    ATM_Menu();

}

void Menu::Register(){
    cin.ignore();
    string new_id = this->user->generateID();
    cout << "Your new ID: " + new_id << endl;
    User user(new_id);
    string pin;
    long double balance = 0;
    while(true){
        cout << "Enter your new 6-digit PIN numbers: ";
        getline(cin,pin);
        if(!this->user->validPIN(pin)){
            continue;
        }
        else {
            user.setPIN(pin);
            user.setBalance(balance);
            break;
        }
    }

    ofstream outFi(new_id+".txt");
    outFi << pin << " " << balance;
    outFi.close();
}






void Menu::ATM_Menu(){
    while(true){
        int choice;
        cout << "1.Account Information" << endl;
        cout << "2.Withdraw money" << endl;
        cout << "3.Deposit money" << endl;
        cout << "4.Transfer money" << endl;
        cout << "5.Log out" << endl;
        cout << "What is your option: " ;
        cin >> choice;
        if(choice == 1){
            cout << "Your Account information" << endl;
            ShowInfo();
            continue;
        }

        if(choice == 2){
            while(true){
                cout << "What is the amount of money you want to withdraw? ";
                long double money;
                cin >> money;
                long double value = user->getBalance();
                if(value <= money){
                    cout << "You do not have enough money!" << endl;
                    break;
                }
                else {
                    this->user->Withdraw_money(money);
                    cout << "Withdraw money successfully" << endl;
                    break;
                }
            }
            continue;
        }

        else if(choice == 3){
            while(true){
                cout << "What is the amount of money you want to deposit? ";
                long double money;
                cin >> money;
                this->user->Deposit_money(money);
                cout << "Deposit money successfully" << endl;
                break;
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
                if(this->user->existAccount(friendID)){
                    while(true){
                        long double money;
                        cout << "What is the amount of money you want to transfer? ";
                        cin >> money;
                        if(user->getBalance() < money){
                            cout << "You do not have enough money!" << endl;
                            break;
                        }
                        else if(money <= 0 || !isdigit(money)){
                            cout << "Invalid money!" << endl;
                            break;
                        }
                        else {
                            this->user->Transfer_money(friendID,money);
                            cout << "Transfer money successfully" << endl;
                            break;
                        }
                    }
                    if(!user->isFriend(friendID)){
                        while(true){
                            cin.ignore();
                            string ans;
                            cout << "Do you want to add friend?(y/n) ";
                            getline(cin,ans);
                            if(ans == "y"){
                                user->add_Friend(friendID);
                                cout << "Add friend successfully!" << endl;
                                return;
                            }
                            else if(ans == "n"){
                                return;
                            }
                            else continue;
                        }
                    }

                    else break;
                }
                else{
                    cout << "This account does not exist, please check again!";
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
    vector<string> listFriends = this->user->getFriends();

    cout << "PIN numbers: " << this->user->getPIN() << endl;
    cout << "Balance: " << this->user->getBalance() << endl;
    cout << "Friends:";

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



Menu::~Menu(){
    // Destructor Implementation
}

