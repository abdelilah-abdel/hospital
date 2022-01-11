//
// Created by abdel on 1/6/2022.
//

#ifndef SERVICE_H_FUNCTIONS_H
#define SERVICE_H_FUNCTIONS_H

#include "Sservice.h"

bool existance_service(service *Tabservices,service &S){

    for (int i = 0; i < sizeof (*Tabservices); i++) {  // either size of or nombre_services
         if(Tabservices[i].get_codeservice() ==S.get_codeservice())
             return true;
    }
        return false ;
}

bool Ajouter_service(service *Tabservices,service &SD){ // SDservice donnee
   if(existance_service(Tabservices,SD)){
       std::cout<<"service deja existe";
       return false;
   } else{
       nombre_service++;
       Tabservices[nombre_service]=SD; // = est surcharge( dans la class service)
       return true; // pour savoir que le service etait ajoute
   }

}
/*
void Modifier_nom_service(service *Tabservices,service &SD){ // modifeir le nom d'un service mais il faut deja verifier l'existance service dans un tableau Service ;
    if(!existance_service(Tabservices,SD)){
        cout<<"le service donne n'existe pas";
    } else {
        SD.modifier_nom_s();
        }
    }
*/
void Modifier_Medcin_chef(service *Tabservices,service &SD){
    if(!existance_service(Tabservices,SD)){
        cout<<"le service donne n'existe pas";
    } else{
        SD.modifier_med_c();
    }
}

// not sure if it will work
service&  Supprimer_service(service *Tabservices,service &SD){
  // int position ;
    for (int i = 0; i < nombre_service; i++) {
        if(Tabservices[i].get_codeservice() ==SD.get_codeservice())
        {
            for (int j = i; j <nombre_service-1 ; j++) {
                Tabservices[j] = Tabservices[j+1];
            }

         }
    }
    return *Tabservices;
}


void  Afficher_All_services(service *Tabservices) {
    for (int i = 0; i < nombre_service; i++) {
        Tabservices[i].Afficher_service();
    }
}


int  Service_10ans(service *Tabservices){
    string  id_temp;
    cout<< "entrer le code id service "; cin>>id_temp;
    for(int i=0; i<nombre_service; i++)
    {
        if(Tabservices[i].Age_service(id_temp)>10){
            cout <<"service n° "<<i<<endl;
            Tabservices->get_nomservice();
            cout<<endl<<endl;
        }
}
    return 0;
}

#endif //SERVICE_H_FUNCTIONS_H
