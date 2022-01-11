#ifndef SERVICE_H_Medcin_H
#define SERVICE_H_Medcin_H

#include <string>
#include <iostream>
#include "date.h"


using namespace std ;

int cpt_Med =0;  // variable globale


class Medcin{
private:
    string   id_Medcin ;
    string   nom_Med, prenom_Med , address_Med , specialite_Med ;
    double   salaire_Med ;
    date     date_affectation_Med;                                       // should add the date class

public:

   Medcin(){};

   void reset_Medcin(){
       id_Medcin=" ";
       salaire_Med=0;
       nom_Med = prenom_Med = address_Med = specialite_Med= " ";
       date_affectation_Med.resetdate();
   }

   Medcin(Medcin &Med){
       id_Medcin = Med.id_Medcin;
       nom_Med =Med.nom_Med;
       prenom_Med = Med.prenom_Med;
       address_Med = Med.address_Med;
       specialite_Med = Med.specialite_Med;
       date_affectation_Med= Med.date_affectation_Med;  // date class , figure it out
   }

   void afficher_med(){
       system("clear");
       cout<<"MEDCIN Numero : " << cpt_Med<<endl;
       cout<<"id :"<< id_Medcin << endl ;
       cout<<"nom:"<<nom_Med << endl;
       cout<<"prenom :"<< prenom_Med<< endl;
       cout<<"adress :"<<address_Med<<endl ;
       cout<<"specialite:"<<specialite_Med<<endl;
       date_affectation_Med.resetdate();
   }

   void saisir_Med() {
       system("clear");
       cout<<"id :";cin>>id_Medcin;
       cout<<"nom :"; cin>>nom_Med;
       cout<<"prenom:"; cin>>prenom_Med;
       cout<<"adress:"; cin>>address_Med;
       cout<<"specialite :";cin>>specialite_Med;
       cout<<"date d'affectation"; date_affectation_Med.Ajouter_date();
         cpt_Med++;
       cout<<"les donnes sont bien enregistrer";
   }

   string getId_Med(){
       return  id_Medcin ;
   }
   string  getnom_Med(){
       return nom_Med;
   }
   string getPrenom_Med(){
       return prenom_Med ;
   }
   string getSpec_Med(){
       return  specialite_Med;
   }

  //  friend ostream& operator << (ostream  &output , const Medcin &M);

friend ostream& operator << (ostream &,Medcin &);
};
// la surcharge des operateurs:

ostream& operator << (ostream  &output ,  Medcin &M) {
    output<<"MEDCIN Numero : " << cpt_Med<<endl;
    output<<"id :"<< M.id_Medcin << endl ;
    output<<"nom:"<<M.nom_Med << endl;
    output<<"prenom :"<< M.prenom_Med<< endl;
    output<<"adress :"<<M.address_Med<<endl ;
    output<<"specialite:"<<M.specialite_Med<<endl;
    M.date_affectation_Med.Afficher_date();
    return  output;
}


#endif