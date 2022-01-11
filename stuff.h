//
// Created by abdel on 1/8/2022.
//
#ifndef SERVICE_H_STUFF_H
#define SERVICE_H_STUFF_H
#include <string>
#include <iostream>
#include "date.h"
#include "infirmier .h"
using namespace std ;

int cpt_stuff;

class  stuff{
private:
    string id ;
    string nom ;
    string prenom;
    string adress ;
    double salaire ;
    date date_affectation;
public:
    stuff(){
        id=" ";
        nom=" ";
        prenom=" ";
        adress= " ";
        salaire=0;
        date_affectation.resetdate();
    }
    stuff(stuff &s){
        id=s.id;
        nom=s.nom;
        prenom=s.prenom;
        adress=s.salaire;
        salaire=s.salaire;
        date_affectation=s.date_affectation;
    }

    void Afficher_stuff (){
        cout<<"id :"<<id;
        cout<<"nom :"<<nom ;
        cout<<"prenom:"<<prenom;
        cout<<"adress"<<adress;
        cout<<"salaire_infirmier"<<salaire;
        date_affectation.Afficher_date(); // not sure if it will work
    }


    void Ajouter_stuff (){
        cpt_stuff++;
        cout<<"id :";    cin>>id;
        cout<<"nom :";   cin>>nom ;
        cout<<"prenom:"; cin>>prenom;
        cout<<"adress";  cin>>adress;
        cout<<"salaire_infirmier";cin>>salaire;
        cout<<"date d'affectation"; date_affectation.Ajouter_date();
    }

    double getSalaire_Inf(){ return salaire; }
    string getAdress_Inf(){return adress;}
    string getId_inf() { return  id; }
    string getNom_Inf(){ return  nom;}
    string getPrenom_Inf(){  return  prenom;}
    date   getDA_Inf() { return  date_affectation;}




};

























#endif //SERVICE_H_STUFF_H
