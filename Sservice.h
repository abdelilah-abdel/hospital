//
// Created by abdel on 1/11/2022.
//
#ifndef SERVICE_H_SSERVICE_H
#define SERVICE_H_SSERVICE_H
#include <string>
#include <iostream>

#include "Medcin.h"
#include "infirmier .h"



using  namespace std;
int nombre_service =0;

class service {
private:
    string code_service;
    string nom_service;
    Medcin Med_chef;
    string secretaire;
    int nbr_infermier;  // initialisation par le nombre d'infermiers prenants en consediration l'insertion
    infirmier *Tabinfermiers;  // tableau de Medcin
    date date_lancement_S; // date lancement de service

public:

    service() {
        code_service = " ";
        nom_service = " ";
        Med_chef.reset_Medcin();
        Tabinfermiers = new infirmier[20]; // initialisation de tableau et reservation de 20 position dans la memoire  de type infermier ;
        secretaire = "";
        nbr_infermier = cpt_Inf;
        date_lancement_S.resetdate();
        nombre_service++;
    }


    service(service &S) {
        code_service = S.code_service;
        nom_service = S.nom_service;
        Med_chef = S.Med_chef;
        secretaire = S.secretaire;
        nbr_infermier = S.nbr_infermier;
        for (int i = 0; i <cpt_Inf ; i++) {
            Tabinfermiers[i].copy_infirmier(S.Tabinfermiers[i]);
        }
        date_lancement_S = S.date_lancement_S;  // surcharge d'operateur sur date
        cout << "constructeur de copie est bien effectuer";
        nombre_service++;
    };

    // GETERS
    string get_codeservice() { return code_service; } // we used it in ->
    string get_nomservice() { return nom_service; } // we used it in ->

    // methode pour affiche les services ayant moins de 5ans


    // methode qui verifie si un infermier existe dans un service ou non : il faut donne un code de service
    bool verifier_existance_Inf(string code) {
        int cpt = 0;
        for (int i = 0; i < cpt_Inf; i++) {
            if (Tabinfermiers[i].getId_inf() == code) {
                cpt++;
                cout << "l'infirmier [id = " << code << " ] existe" << endl;
            }
        }
        if (cpt > 0)
            return false;
        else
            return true;
    }

// methode qui verifier si le nombre des infermiers est >20
    bool verifier_nbr_inf() {
        if (nbr_infermier > 20) {
            return false;
        } else
            return true;
    }

    // pour ajouter un infirmier ; to improve , cin and cout outside the methode

    void ajouter_inf() {
        string id_temporaire;
        cout << "entrer l'id d'infermier : ";
        cin >> id_temporaire;

        if (!verifier_nbr_inf()) // si le nombre d'inf est sup a 20
        {
            cout << "la liste des infermiers est sature";
        }
        if (verifier_existance_Inf(id_temporaire)) { // l'id deja existe
            cout << "erreur: l'infirmier " << id_temporaire << "deja existe";
            //  ajouter_inf();   only works if cout cin are inside the methode
        } else if (!verifier_existance_Inf(id_temporaire)) {
            nbr_infermier++;
            Tabinfermiers[nbr_infermier].Ajouter_infermier();
            cout << "les donnees sont bien enregistrer" << endl;
        }
    }


// methode verifies if infirmier have   // improve ajouter un capteur qui calcul nombre dinf
    void inf_5exp() {
        int cpt = 0;
        for (int i = 0; i < nbr_infermier; i++) {
            if (Tabinfermiers[i].getDA_Inf().comparer_date() < -5) {
                cpt++;
                Tabinfermiers[i].Afficher_infermier();
            }
        }
        if (cpt > 0)
            cout << "aucun infirmier qui a experience < 5ans" << endl;
    }


    // methode qui calcule l'age d'un service  courant ; il faut donner l'id ( return : nombres d'annes)
    int Age_service(string idservice) {
        int A, B, C;
        if (code_service == idservice) {
            A = date_lancement_S.comparer_date();
            B = date_lancement_S.comparer_mois();
            C = date_lancement_S.comparer_jour();
        }
        cout << "Age de service :" << A << "an" << B << "mois" << C << "jours" << endl;
        return A;
    }


    // methode qui calcul l'age d'un service donne ; il faut donne un tableau de service
    int Age_service(service *Tabservice, string idservice) {
        int pos, A, B, C;
        for (int i = 0; i < nombre_service; i++) {
            if (Tabservice[i].code_service == idservice)
                pos = i;  // trouver la position(indice) de service dans un tableau service
        }
        A = Tabservice[pos].date_lancement_S.comparer_date();
        B = Tabservice[pos].date_lancement_S.comparer_mois();
        C = Tabservice[pos].date_lancement_S.comparer_jour();

        cout << "Age de service :" << A << "an" << B << "mois" << C << "jours" << endl;
        return A;
    }

    // age d'un service courant donne =
    int Age_service(service &s) {
        int A;
        A = s.date_lancement_S.comparer_date();
        cout << "Age de service :" << A << "ans" << endl;
        return A;
    }

    bool Supprimer_inf_service(string codeinf) {
        if (verifier_existance_Inf(codeinf)) // l'inf dans ce service existe deja '
        {// instructions de suppressions
            for (int i = 0; i < nbr_infermier; i++) {
                if (Tabinfermiers[i].getId_inf() == codeinf) {
                    for (int j = i; j < nbr_infermier - 1; j++) {
                        Tabinfermiers[j] = Tabinfermiers[j + 1];
                    }
                    nbr_infermier--;
                }

            }
            cout << "les donnees bien enregistrer !";
            return true;
        } else {
            cout << "erreur , verifier le id d'infermier et verifier une autre fois";
            return false;
        }
    }

    //Modifier le nom de service courant
    void Modier_nom_service(service *Tabservice,string code) {
        for(int i=0; i<nombre_service;i++)
        {
            if(Tabservice[i].code_service == code){
                std::cin >> Tabservice[i].nom_service;
                std::cout << "le changement etait bien effectuer" << '\n' << "nouveau nom de service est :" << Tabservice[i].nom_service
                          << std::endl;
            } else{
                cout<<"le service de l'id : "<<code<<"n existe pas sur la liste des services ";
                break;
            }
        }
    }

    //we suppose the service already existed

    void Modier_nom_service(service &S) {
        std::cout << "entrer le nouveau nom pour service :" << S.nom_service << '\n';
        std::cin >> S.nom_service;
        std::cout << "les changements sont effectués correctement. " << '\n' << "nouveau nom de service est :"
                  << S.nom_service << std::endl;
    }

    void Afficher_service() {
        cout << "\xB2\xB2\xB2 SERVICE :" << nom_service << ":" << code_service << "\xB2\xB2\xB2";
        cout << "\xB2\xB2\xB2"; date_lancement_S.Afficher_date();
        cout << "Medcin chef de service: [ " << Med_chef.getnom_Med() << "-id:" << Med_chef.getId_Med();
        cout << "Secretaire de service : " << secretaire;
        cout << "Nombre d'ifirmiers" << nbr_infermier;

        cout << "\xB2\xB2\xB2Liste d'infermiers -----------";
        for (int i = 0; i < nbr_infermier; i++) {
            Tabinfermiers[i].Afficher_infermier();
        }
    }



    void modifier_med_c() {
        Med_chef.saisir_Med();
    }

    service  operator=(service &S) {
        this->code_service = S.code_service;
        this->nom_service = S.nom_service;
        this->Med_chef = S.Med_chef;
        this->secretaire = S.secretaire;
        this->nbr_infermier = S.nbr_infermier;
        this->date_lancement_S = S.date_lancement_S; // needs an operator surcharge ,
        this->Tabinfermiers = S.Tabinfermiers; // needs a surcharge or a methode
        return  *this;
    }
};
#endif //SERVICE_H_SSERVICE_H
