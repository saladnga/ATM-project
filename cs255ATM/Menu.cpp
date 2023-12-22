#include<bits/stdc++.h>
#include"Menu.h"
#include"User.h"
using namespace std;

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
    outFi << pin << " " << balance;
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

void Menu::ATM_Menu(){
    cout << "1.Account Information" << endl;
    cout << "2.Withdraw money" << endl;
    cout << "3.Deposit money" << endl;
    cout << "4.Transfer money" << endl;
    cout << "5.Log out" << endl;
}