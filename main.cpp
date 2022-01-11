#include "functions.h"
#include "menus.h"
#include "password.h"
#include "Sservice.h"

using namespace std;

int main() {

    login user;
    user.Password();

    date date1, date2;

  /*
    date1.date_Aujourdhui();
    date1.Ajouter_date();
    date1.Afficher_date();
    date1.comparer_date();
    date1.comparer_date(date2);
*/

    infirmier inf1,inf2;
    cout<<"inserez un infermier pour tester le code "<<endl;
    inf1.Ajouter_infermier();


    // inf2.Ajouter_infermier();
    Medcin med1;
    service service1,service2;
    service *Tabservices ;
    Tabservices= new service[nombre_service];


    inf1.Ajouter_infermier();
    inf1.Afficher_infermier();


    switch (menu_infermier()) {
        case 1 :
            inf1.Ajouter_infermier();
            break;
        case 2:
            inf1.Afficher_infermier(inf1);
            break ;
        case 3 :
            inf1.comparer_Inf(inf2);
            break;
        case 4:
        {
            cout<< "entrer un id d'infirmier pour comparer : "; string id ; cin>>id ;
            inf1.comparer_Inf(inf1);
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
        case 1 :
            existance_service(Tabservices,service1);
            break;
        case 2:
            Ajouter_service(Tabservices,service1);
            break ;
        case 3 :
            Modifier_Medcin_chef(Tabservices,service1);
            break;
        case 4:
            Supprimer_service(Tabservices,service1);
        case 5:
            Afficher_All_services(Tabservices);
            break;
        case 6:
            Service_10ans(Tabservices);
            break;
        case 7:
            menu_Principale();
    }


    switch (menu_service()) {
        case 1 :
            service1.inf_5exp();
            break;
        case 2:
        { string code ;
            cout<<"entrer le code de service";cin>>code;
            service1.verifier_existance_Inf(code);
            break ;
        }

        case 3:
        { string id; cout<<"entrer le id de service :";cin>>id;
           service1.Age_service(Tabservices,id);
            break;
        }
        case 4:
        {string id; cout<<"entrer le id de service :";cin>>id;
             service1.Supprimer_inf_service(id);
            break;
        }
        case 5:
            service1.Modier_nom_service();
            break;
        case 6:
            service1.Modier_nom_service(service2);
            break;
        case 7:
        {
            if(user.reLogin(user))
            {service1.Afficher_service(); }
            break;
        }
    }





    return 0;



}
