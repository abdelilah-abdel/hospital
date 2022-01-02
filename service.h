#include <iostream>
#include <string>
#include <cstring>
#include "Medcin.h"
#include "infirmier .h"
#include "date.h"


using  namespace std;


class  service{
private:
    string code_service ;
    string nom_service;
    Medcin Med_chef ;
    string secretaire ;
    int    nbr_infermier = cpt_Inf;  // initialisation par le nombre d'infermiers prenants en consediration l'insertion
    infirmier *Tabinfermiers ;  // tableau de Medcin
    date date_lancement_S ; // date lancement de service

public:

    service(){
        code_service=0;
        nom_service=" ";
        Med_chef.reset_Medcin();
        Tabinfermiers = new string[20]; // initialisation de tableau et reservation de 20 position dans la memoire ;
         // not sure a verifier
     };
    service(service& S ){
         code_service = S.code_service;
         nom_service = S.nom_service;
         Med_chef = S.Med_chef;
         secretaire = S.secretaire;
         nbr_infermier = S.nbr_infermier;
         for(int i ; i<nbr_infermier; i++){
             Tabinfermiers[i]=S.Tabinfermiers[i];
         }
         date_lancement_S = S.date_lancement_S;  // constructeur de date par copie
        cout<<"constructeur de copie est bien effectuer";
     };

    bool verifier_existance_Inf(string code){
        for(int i ; i< nbr_infermier; i++){
            if(Tabinfermiers[i].getId_inf() ==code)
                cout<<"l'infirmier [id = "<<code<<" ] existe"<< endl;
            return true ;
            break;
        }
        else
            return false ;
    }
 // surcharge de methode
    bool verifier_existance_Inf(service &S, string code){
        for(int i ; i< S.nbr_infermier; i++){
            if(S.Tabinfermiers[i].getId_inf() ==code)
                cout<<"l'infirmier [id= :"<<code<<"] existe"<< endl;
            return true ;
            break;
        }
        else
        return false ;
    }
    bool verifier_nbr_inf() const{
        if (nbr_infermier>20){
            return false ;
        } else return true ;
    }

void  ajouter_inf(){
        string id_temporaire ;
        cout<<"entrer l'id d'infermier : "; cin>> id_temporaire;
        if (!verifier_nbr_inf())
        {   cout<<"la liste des infermiers est sature";
            break;
        }

        if (verifier_existance_Inf(id_temporaire)) { // l'id deja existe
            cout << "erreur: l'infirmier " << id_temporaire << "deja existe";
            break;
        }

         else if(!verifier_existance_Inf(id_temporaire))
         { nbr_infermier ++ ;
             Ajouter_infermier(); // fix this shit
           }
    }
//3.10 ----------------------------1
void inf_5exp() {
    for (int i; i < nbr_infermier ; i++) {

       if (Tabinfermiers[i].getDA_Inf().comparer_date()<-5)
           cout<<Tabinfermiers[i].Afficher_infermier();
    }
        cout<<"aucun infirmier qui a experience < 5ans"<< endl ;
}
// 2
    void inf_5exp(infirmier *tabinf) {
        for (int i; i < nbr_infermier ; i++) {

            if (tabinf[i].getDA_Inf().comparer_date()<-5)
                cout<<tabinf[i].Afficher_infermier();
        }
        cout<<"aucun infirmier qui a experience < 5ans"<< endl ;
    }
//----------------------------------1

int  Age_service(service *tabs, string idservice){
       for(int i ;i<nbr_infermier; i++) {
           if (tabs[i].code_service = idservice) {
               int A = tabs[i].date_lancement_S.comparer_date();
               int B = tabs[i].date_lancement_S.comparer_mois();
               int C = tabs[i].date_lancement_S.comparer_jour();
               break;
           }
       }
    cout<<"Age de service :"<<A<<"an"<<B<<"mois"<<C<<"jours"<< endl;
    return  A  ;
       }

bool  Supprimer_inf_service(string codeinf){
    for (int i = 0; i < nbr_infermier; i++) {
       if (Tabinfermiers[i].getId_inf() == codeinf )
    }

    }



};