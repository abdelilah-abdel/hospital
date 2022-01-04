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
        code_service=" ";
        nom_service=" ";
        Med_chef.reset_Medcin();
        Tabinfermiers = new infirmier[20]; // initialisation de tableau et reservation de 20 position dans la memoire  de type infermier ;
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

        }

        if (verifier_existance_Inf(id_temporaire)) { // l'id deja existe
            cout << "erreur: l'infirmier " << id_temporaire << "deja existe";

        }

         else if(!verifier_existance_Inf(id_temporaire))
         { nbr_infermier ++ ;
             Tabinfermiers[nbr_infermier].Ajouter_infermier();
           }
    }
//3.10 ----------------------------1
void inf_5exp() {
    for (int i; i < nbr_infermier ; i++) {

       if (Tabinfermiers[i].getDA_Inf().comparer_date()<-5)
           Tabinfermiers[i].Afficher_infermier();
    }
        cout<<"aucun infirmier qui a experience < 5ans"<< endl ;
}
// 2
    void inf_5exp(infirmier *tabinf) {
        for (int i; i < nbr_infermier ; i++) {

            if (tabinf[i].getDA_Inf().comparer_date()<-5)
                tabinf[i].Afficher_infermier();
        }
        cout<<"aucun infirmier qui a experience < 5ans"<< endl ;
    }
//----------------------------------1

int  Age_service(service *tabs, string idservice){
      int position , A, B,C ;
       for(int i;i<nbr_infermier; i++) {
           if (tabs[i].code_service == idservice) {
               position=i;  // trouver la position(indice) de service dans un tableau service
               break;
           }
                A = tabs[position].date_lancement_S.comparer_date();
                B = tabs[position].date_lancement_S.comparer_mois();
                C = tabs[position].date_lancement_S.comparer_jour();
       }
    cout<<"Age de service :"<<A<<"an"<<B<<"mois"<<C<<"jours"<< endl;
    return  A  ;
       }

//bool Supprimer_inf_service(){

 //   }


bool  Supprimer_inf_service(string codeinf){
        if(verifier_existance_Inf(codeinf))
        {
            // instructions de suppressions
            for (int i = 0; i < nbr_infermier; i++)
            {  if (Tabinfermiers[i].getId_inf() == codeinf )
                {
                for (int j = i; j < nbr_infermier-1; j++)
                {
                    Tabinfermiers[j]=Tabinfermiers[j+1];
                  }
                }

            }
            cout<<"les donnees bien enregistrer !";
            return true;
        }
        else
        {
            cout<<"erreur , verifier le id d'infermier et verifier une autre fois";
            return false;
        }
    }
    void Modier_nom_service(){
        std::cout << "entrer le nouveau nom de service" << '\n';
        std::cin >> nom_service;
        std::cout << "le changement est bien effectuer" << '\n'<<"nouveau nom de service est :"<< nom_service<<std::endl;
    }
    void Modier_nom_service(service &S){
        std::cout << "entrer le nouveau nom pour service :" <<S.nom_service<<'\n';
        std::cin >> S.nom_service;
        std::cout << "le changement est bien effectuer" << '\n'<<"nouveau nom de service est :"<< S.nom_service<<std::endl;
    }


    void Afficher_service(){
        cout<<"-------------------------SERVICE :"<<nom_service<<":" << code_service<<"---------------------";
        date_lancement_S.Afficher_date();
        cout<<"Medcin chef de service: [ "<<Med_chef.getnom_Med() <<"-id:"<<Med_chef.getId_Med();
        cout<<" secretaire de service : "<< secretaire;
        cout<<"nombre d'ifirmiers"<<nbr_infermier;
        cout<<"-----Liste d'infermiers -----------" ;
        cout<<"id \t nom \t prenom \t adress \t date d'affectation \t salaire \t type de contrat"<<endl;
        for (int i = 0; i < nbr_infermier; i++)
        {
         cout<<Tabinfermiers[i].getId_inf();
         cout<<Tabinfermiers[i].getNom_Inf();
         cout<<Tabinfermiers[i].getPrenom_Inf();
         cout<<Tabinfermiers[i].getAdress_Inf();
         Tabinfermiers[i].getDA_Inf().Afficher_date();
         cout<<Tabinfermiers[i].getSalaire_Inf();
         cout<<Tabinfermiers[i].getTypecontrat_Inf();
        }

    }


};