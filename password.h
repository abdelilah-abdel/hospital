//
// Created by abdel on 1/9/2022.
//
#ifndef SERVICE_H_PASSWORD_H
#define SERVICE_H_PASSWORD_H
#include <iostream>
#include "string"
#include "Sservice.h"
#include "menus.h"

using namespace std;

class  login {
private:
    string identificateur;
    string motdepasse;
public:
    login(){
        identificateur="ADMIN";
        motdepasse="ADMIN123";
    }

    void Password();

    bool reLogin(login &user);
};

//login Tlogin[3];


void login::Password() {
    int choice ; string cle1 , cle2;

    cout << " \xB2\xB2\xB2  WELCOME ";
do {
  cout << "pour vous connecter entrez 0 => ";
  cin >> choice;
} while (choice < 0 || choice > 1);

if (choice == 0)
{
  cout << " \xB2\xB2\xB2   LOGIN ";
  I:
  cout << "\xB2\xB2\xB2\xB2 entrer l'identificateur :";  cin >> cle1;
  cout << "\n \xB2\xB2\xB2\xB2 entrer le mot de passe :";   cin >> cle2;

    if (cle1 != identificateur || cle2 != motdepasse)   // cas d'admin
    {
        cout << "l'identificateur / mot de passe est incorrects " << endl;
        Password();
    } // menu d'administrateur
    else
        menu_Principale();
}
}

bool login::reLogin(login &user){
     string cle;
    cout<<"confirmer le code d'utilisateur";
     cin>>cle;
     if(cle==motdepasse)
         return true;
    return false;
}
    #endif //SERVICE_H_PASSWORD_H
