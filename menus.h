//
// Created by abdel on 1/9/2022.
//

#ifndef SERVICE_H_MENUS_H
#define SERVICE_H_MENUS_H


date date_Aujourdui;


int  menu_infermier();
int   menu_Medcin();
int  menu_fonctions();
int  menu_service();




void menu_Principale()
{
    int c=0;
    do {

        cout <<"\xB2\xB2\xB2MENU PRINCIPALE - GESTION DES HOPITAUX - PAR AIT HAMOU ABDELILAH \xB2\xB2\xB2 "<<endl;
        cout <<"\xB2\xB2\xB2"; date_Aujourdui.date_Aujourdhui();cout <<"\xB2\xB2\xB2";
        cout<<endl<<endl;
        cout << "1- pour Afficher le menu_infermier \n";
        cout << "2- pour afficher menu Medcin  \n";
        cout << "3- pour afficher menu service  \n";
        cout << "4- pour afficher menu fonctions\n";
        cout << "5- pour quitter \n";
        cout<<  "choisir parmis les choix [1-5] :";
        cin >> c;
    } while (c<1|| c>5);

    switch (c){

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
}

int  menu_infermier(){
    int c;
    do {
        cout<<"\xB2\xB2\xB2 MENU INFIRMIER \xB2\xB2\xB2"<<endl;
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

    int c;
    do{ cout<<"\xB2\xB2\xB2 MENU MEDCIN \xB2\xB2\xB2"<<endl;
        cout <<"1- pour Ajouter un medcin"<<endl;
        cout <<"2- pour Afficher les donnees de Medcin courant"<<endl ;
        cout <<"3- pour revenir au Menu principale"<< endl;
        cout<<  "choisir parmis les choix [1-3] :";
        cin>>c;
    }while (c<1 || c>3);
    return c ;
}

int  menu_fonctions(){
    int c=0;
    do{
        cout<<" etant donne un tableau de N services , tappez "<< endl ;
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
    system("cls");
    int c=0;
    do{ cout<<"\xB2\xB2\xB2 MENU SERVICES  \xB2\xB2\xB2"<<endl;
        cout<< " pour manipuler les donnees d'un service  "<< endl ;
        cout << "1- pour Afficher les infermiers avec experience < 5ans  \n";
        cout << "2- pour verifier l'existance d'un Infirmier dans un service donne \n";
        cout << "3- pour affiche l'age d'un service  \n";
        cout << "4- pour Supprimer les donnes d'un infermier dans le service   \n";
        cout << "5- pour Modifier le nom de service (courant) \n";
        cout << "6- pour Modifier le nom d'un service ( il faut donner le quel service )";
        cout << "7- pour Afficher toutes les informations d'un service";
        cout<<  "choisir parmis les choix [1-7] :";
        cin>>c;
    } while (c<1|| c>7);
    return c;
}


#endif //SERVICE_H_MENUS_H
