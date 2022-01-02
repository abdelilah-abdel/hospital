#include <iostream>
#include <cstring>
#include <string>

int cpt_Inf=0 ;
class  infirmier{
private:
    string id_infirmier;
    string nom_infirmier;
    string prenom_infirmier;
    string adress_infirmier ;
    double  salaire_infirmier ;
    string type_contrat;
    string date_affectation_Inf; // need the date class
public:
    infirmier(); // constructeur par default
    // constructeur par copie :
    infirmier(infirmier &I){
        id_infirmier=I.id_infirmier;
        nom_infirmier=I.nom_infirmier;
        prenom_infirmier=I.nom_infirmier;
        adress_infirmier=I.id_infirmier;
        salaire_infirmier=I.salaire_infirmier;
        type_contrat= I.type_contrat;
        date_affectation_Inf=I.date_affectation_Inf;
        cout<<"the data is copied";
    };




    void Ajouter_infermier (){
        cpt_Inf ++ ;
        cout<<"id :"; cin>>id_infirmier;
        cout<<"nom :"; cin>>nom_infirmier ;
        cout<<"prenom:"; cin>>prenom_infirmier;
        cout<<"adress"; cin>>adress_infirmier;
        cout<<"salaire_infirmier";cin>>salaire_infirmier;
        cout<<"type contrat :"; cin>>type_contrat;
        cout<<"date d'affectation"; cin>>date_affectation_Inf;
    }
 //les methodes get
    string getId_inf(){ return  id_infirmier; }
    string getNom_Inf(){ return  nom_infirmier;}
    string getDA_Inf(){return  date_affectation_Inf;}

    // methode de comparaison :
    // avec un seul parametre
    bool  comparer_Inf(infirmier &A){
        if(A.id_infirmier == id_infirmier)
            return true;
        return false ;
    }
    // avec deux parametres : surchage
    bool  comparer_Inf(infirmier &A , infirmier& B){
        if (A.id_infirmier == B.id_infirmier)
            return true;
        else false;
    }

    // we can add operator overloadings for menu and stuff like that ;


};