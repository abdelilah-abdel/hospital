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
    string date_lancement_S ; // date lancement de service

public:

    service(){
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
         date_lancement_S = S.date_lancement_S;
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
    bool verifier_nbr_inf(){
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

         else
         { nbr_infermier ++ ;
             Ajouter_infermier(); // fix this shit
           }
    }




    }
}
