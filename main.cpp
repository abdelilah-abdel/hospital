#include "service.h"
using namespace std;
#include "functions.h"
date date_Aujourdui;



int menu_Principale()
{
    int c=0;
do {

    cout <<"---------MENU PRINCIPALE - GESTION DES HOPITAUX - PAR AIT HAMOU ABDELILAH"<<endl;
    cout <<"---------"; date_Aujourdui.date_Aujourdhui();cout <<"---------";
    cout<<"\n \n";
    cout << "1- pour Afficher le menu_infermier \n";
    cout << "2- pour afficher menu Medcin  \n";
    cout << "3-  pour afficher menu service  \n";
    cout << "4-  pour afficher menu fonctions\n";
    cout << "5- pour quitter \n";
    cout<<  "choisir parmis les choix [1-5] :";
    cin >> c;
} while (c<1|| c>5);

    return c;
}



 int  menu_infermier(){
    system("clear");
    int c;
    do {
    cout <<"1- pour Ajouter un infermier"<<endl;
    cout <<"2- pour Afficher les donnees d'un infirmier"<<endl ;
    cout <<"3- pour comparer entre deux infermiers "<< endl ;
    cout <<"4- pour comparer avec l'infermier courant "<<endl;
    cout <<"5- pour revenir au Menu principale"<< endl;
    cout<<  "choisir parmis les choix [1-5] :";
    cin >> c;
 } while (c<1|| c>5);
     return c;
}

int   menu_Medcin(){
    system("clear");
    int c;
 do{cout <<"1- pour Ajouter un medcin"<<endl;
    cout <<"2- pour Afficher les donnees de Medcin courant"<<endl ;
    cout <<"3- pour revenir au Menu principale"<< endl;
     cout<<  "choisir parmis les choix [1-3] :";
    cin>>c;
 }while (c<1 || c>3);
    return c ;
 }

int  menu_fonctions(){
    system("clear");
    int c=0;
   do{cout<<"etant donne un tableau de N services , tapper "<< endl ;
    cout << "1- pour Verifier si un service deja existe ou non \n";
    cout << "2- pour Ajouter un service \n";
    cout << "3- pour Modifier les informations du Medcin chef d'un service\n";
    cout << "4- pour Supprimer un service donné du tableau  \n";
    cout << "5- pour Afficher mes informations de tous les services  \n";
    cout << "6- pour Retourner les services qui ont ete lance plus de 10ans\n";
    cout<< " 7-pour revenir au Menu principale"<<endl;
    cout<<  "choisir parmis les choix [1-5] :";
    cin >> c;
} while (c<1|| c>7);
    return c;
}

int  menu_service(){
    system("clear");
    int c=0;
 do{cout<< "pour manipuler les donnees d'un service  "<< endl ;
    cout << "1- pour Afficher les infermiers avec experience < 5ans  \n";
    cout << "2- pour verifier l'existance d'un Infirmier \n";
    cout << "3- pour verifier l'existance d'un Infirmier dans un serveur donne \n";
    cout << "4- pour affiche l'age d'un service  \n";
    cout << "5- pour Supprimer les donnes d'un infermier dans service   \n";
    cout << "6- pour Modifier le nom de service (courant) \n";
    cout << "7- pour Modifier le nom d'un service ( il faut donner le quel service )";
    cout << "8- pour Afficher toutes les informations d'un service";
    cout<<  "choisir parmis les choix [1-8] :";
    cin>>c;
  } while (c<1|| c>8);
    return c;
}


int main() {
    date date1;
    infirmier inf1,inf2;
    inf2.Ajouter_infermier();
    Medcin med1;
    service service1;
    service *Tabservices ;
    Tabservices= new service[nombre_service];


/*
    infirmier inf1;
    std::cout<<" hehehehe";
    inf1.Ajouter_infermier();
    inf1.Afficher_infermier();
*/
    // menu();

    switch (menu_Principale()){
        case 1 :
            menu_infermier();
            break;
        case 2:
            menu_Medcin();
            break ;
        case 3 :
            menu_service();
            break;
        case 4:
            menu_fonctions();
        case 5 :
            exit(0);
    }



    switch (menu_infermier()) {
        case 1 :
            inf1.Ajouter_infermier();
            break;
        case 2:
            inf1.Afficher_infermier();
            break ;
        case 3 :
            inf1.comparer_Inf(inf2);
            break;
        case 4:
        {
            cout<< "entrer un id d'infirmier pour comparer : "; string id ; cin>>id ;
            inf1.comparer_Inf(id);
            break;
        }
        case 5:
            menu_Principale();
            break;
        case 6:
            exit(0);
    }


    switch (menu_Medcin()) {
        case 1 :
            med1.saisir_Med();
            break;
        case 2:
            med1.afficher_med();
            break ;
        case 3 :
           exit(0);
    }

    switch (menu_fonctions()) {
        // il fault remplir deja un service ;
        case 1 :
            existance_service(Tabservices,service1);
            break;
        case 2:
            Ajouter_service(Tabservices,service1);
            break ;
        case 3 :
            Modifier_nom_service(Tabservices,service1);
            break;
        case 4:
            Supprimer_service(Tabservices,service1);
        case 5:
            Afficher_All_services(Tabservices);
            break;
        case 6:
            cout<<"not done yet";
            break;
        case 7:
            menu_Principale();
    }



     return 0;



}
