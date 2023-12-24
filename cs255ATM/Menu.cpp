#include<bits/stdc++.h>
#include"Menu.h"
#include"User.h"
using namespace std;


Menu::Menu(){
    //Constructor Implementation
}

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
            cout << "Login successfully!" << endl;
            ATM_Menu();
        }
        else if(option == 2){
            Register();
            cout << "Register successfully!" << endl;
            continue;
        }
        else if(option == 3){
            system("cls");
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
    getline(cin,id);
    ifstream fi(id+".txt");
    if(!fi){
        cout << "Invalid ID" << endl;
        mainMenu();
    }
    
    else{
        cout << "Enter your 6-digit PIN numbers: ";
        string pin;
        getline(cin, pin);
        string truePIN;
        fi >> truePIN;
        if(pin != truePIN){
            cout << "Invalid PIN" << endl;
            mainMenu();
        }
    }

}

void Menu::Register(){
    cin.ignore();
    string new_id = generateID();
    cout << "Your new ID: " + new_id << endl;
    string pin;
    while(true){
        cout << "Enter your new 6-digit PIN numbers: ";
        getline(cin,pin);
        if(!validPIN(pin)){
            continue;
        }
        else {
            break;
        }
    }

    long double balance = 0;

    ofstream outFi(new_id+".txt");
    outFi << pin << endl;
    outFi << balance << endl;
    outFi.close();
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

        else if(choice == 2){
            while(true){
                User* user;
                cout << "What is the amount of money you want to withdraw? ";
                long double money;
                cin >> money;
                if(user->getBalance() < money){
                    cout << "You do not have enough money!" << endl;
                    break;
                }
                else {
                    Withdraw_money(money);
                    cout << "Withdraw money successfully" << endl;
                    break;
                }
            }
            continue;
        }

        else if(choice == 3){
            while(true){
                User* user;
                cout << "What is the amount of money you want to deposit? ";
                long double money;
                cin >> money;
                Deposit_money(money);
                cout << "Deposit money successfully" << endl;
                break;
            }
            continue;
        }

        else if(choice == 4){
            User* user;
            cin.ignore();
            while(true){
                cout << "Who do you want to transfer money to? ";
                string friendID;
                getline(cin,friendID);
                if(existAccount(friendID)){
                    while(true){
                        long double money;
                        cout << "What is the amount of money you want to transfer? ";
                        cin >> money;
                        if(user->getBalance() < money){
                            cout << "You do not have enough money!" << endl;
                            break;
                        }
                        else {
                            Transfer_money(friendID,money);
                            cout << "Transfer money successfully" << endl;
                            break;
                        }
                    }
                    if(!user->isFriend(friendID)){
                        while(true){
                            string ans;
                            cout << "Do you want to add friend?(y/n) ";
                            getline(cin,ans);
                            if(ans == "y"){
                                user->add_Friend(friendID);
                                break;
                            }
                            else if(ans == "n"){
                                break;
                            }
                            else continue;
                        }
                    }
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

void Menu::update(){
    User* user;
    ofstream outFi(user->getID() + ".txt");
    outFi << user->getPIN() << endl;
    outFi << user->getBalance() << endl;
    outFi.close();
}

void Menu::ShowInfo(){
    User* user;
    ifstream inFi(user->getID() + ".txt");
    string pin, balance;
    getline(inFi,pin);
    cout << "PIN numbers: " << pin << endl;
    getline(inFi,balance);
    cout << "Balance: " << balance << endl;
    inFi.close();
}

void Menu::Withdraw_money(long double money){
    User* user;
    user->setBalance(user->getBalance() - money);
    update();
}

void Menu::Deposit_money(long double money){
    User* user;
    user->setBalance(user->getBalance() + money);
    update();
}

void Menu::Transfer_money(string friendID, long double money){
    User* user;
    user->setBalance(user->getBalance() - money);
    update();
    string friend_id;
    string friend_balance;
    ifstream inFi(friendID + ".txt");
    inFi >> friend_id;
    inFi >> friend_balance;
    friend_balance += money;
    inFi.close();
    ofstream outFi(friendID + ".txt");
    outFi << friend_id << endl;
    outFi << friend_balance << endl;
    outFi.close();
}


Menu::~Menu(){
    // Destructor Implementation
}





