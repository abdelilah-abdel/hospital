#ifndef SERVICE_H_INFERMIER_H
#define SERVICE_H_INFERMIER_H

 int cpt_Inf=0;


#include <string>
#include <iostream>
#include "date.h"
#include "stuff.h"

using namespace std;



class  infirmier{

private:
    string id_infirmier;
    string nom_infirmier;
    string prenom_infirmier;
    string adress_infirmier ;
    double  salaire_infirmier ;
    string type_contrat;
    date date_affectation_Inf; // need the date class
public:
    // constructeur par default
    infirmier(){
        id_infirmier=" ";
        nom_infirmier=" ";
        prenom_infirmier=" ";
        adress_infirmier= " ";
        salaire_infirmier=0;
        type_contrat=" ";
        date_affectation_Inf.resetdate();
    };

    // constructeur par copie :
    infirmier(infirmier &I){
        id_infirmier=I.id_infirmier;
        nom_infirmier=I.nom_infirmier;
        prenom_infirmier=I.nom_infirmier;
        adress_infirmier=I.id_infirmier;
        salaire_infirmier=I.salaire_infirmier;
        type_contrat= I.type_contrat;
        date_affectation_Inf=I.date_affectation_Inf; // not sure if it will work // should add overloading operator
        cout<<"the data is copied";
    };
 // afficher le
    void Afficher_infermier (){
        cout<<"id :"<<id_infirmier<<endl;
        cout<<"nom :"<<nom_infirmier <<endl;
        cout<<"prenom:"<<prenom_infirmier<<endl;
        cout<<"adress"<<adress_infirmier<<endl;
        cout<<"salaire_infirmier"<<salaire_infirmier<<endl;
        cout<<"type contrat :"<<type_contrat<<endl;
        date_affectation_Inf.Afficher_date(); // not sure if it will work
    }
    void Afficher_infermier (infirmier &e){
        cout<<"id :"<<e.id_infirmier<<endl;
        cout<<"nom :"<<e.nom_infirmier <<endl;
        cout<<"prenom:"<<e.prenom_infirmier<<endl;
        cout<<"adress"<<e.adress_infirmier<<endl;
        cout<<"salaire_infirmier"<<salaire_infirmier<<endl;
        cout<<"type contrat :"<<type_contrat<<endl;
        date_affectation_Inf.Afficher_date(); // not sure if it will work
    }
    void Ajouter_infermier (){
        cpt_Inf ++ ;
        cout<<"nombre d'inf : "<<cpt_Inf;
        cout<<"id :";    cin>>id_infirmier;
        cout<<"nom :";   cin>>nom_infirmier ;
        cout<<"prenom:"; cin>>prenom_infirmier;
        cout<<"adress";  cin>>adress_infirmier;
        cout<<"salaire_infirmier";cin>>salaire_infirmier;
        cout<<"type contrat :"; cin>>type_contrat;
        cout<<"date d'affectation"; date_affectation_Inf.Ajouter_date();
        cout<<"les donnees sont bien enregistrer"<<endl ;
    }
    //les methodes get
    string getId_inf() { return  id_infirmier; }
    string getNom_Inf(){ return  nom_infirmier;}
    string getPrenom_Inf(){  return  prenom_infirmier;}
    date   getDA_Inf() { return  date_affectation_Inf;}
    string getTypecontrat_Inf(){ return  type_contrat;}
    double getSalaire_Inf(){ return salaire_infirmier; }
    string getAdress_Inf(){return adress_infirmier;}

    // methode de comparaison :
         // comparer avec l'infermier courant
    bool  comparer_Inf(infirmier &A){
        if(id_infirmier == A.id_infirmier)
            return true;
        return false ;
    }
    // avec deux parametres : surchage
    bool  comparer_Inf(infirmier& A,infirmier &B){
        if (A.getId_inf() == B.getId_inf())
            return true;
        return false;
    }

    // we can add operator overloadings for menu and stuff like that ;

/*
    ostream& operator << (ostream  &output //,  infirmier &M ){
        output<<"id :"<<id_infirmier;
        output<<"nom :"<<nom_infirmier ;
        output<<"prenom:"<<prenom_infirmier;
        output<<"adress"<<adress_infirmier;
        output<<"salaire_infirmier"<<salaire_infirmier;
        output<<"type contrat :"<<type_contrat;
        return  output;
    }
*/
};
#endif