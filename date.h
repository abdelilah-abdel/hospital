#ifndef SERVICE_H_DATE_H
#define SERVICE_H_DATE_H



#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class date {

private:
    int jr;
    int ms;
    int an;
    int hr;
    int min;
    int sec;

public:
    time_t now = time(NULL);                   // pour stocker le temps de systm de type time_ t --> nbr de sec   // affectation le temps de  system a la variable time ;
    struct tm nowlocal = *localtime(
            &now);   // pour transformer la variable now(nbrdesec) a une variable type tm qui est strecture est differencies les chiifre entre min sec month year days ....etc
public:

    date() {
        jr = 01;
        ms = 01;
        an = 1900;
        hr=nowlocal.tm_hour;
        min=nowlocal.tm_min;
        sec=nowlocal.tm_sec;
    }

    void Afficher_date() const {
        cout << "La date :" << jr << "/" << ms << "/" << an << "/" << endl;
        cout << "Le Temps(" << hr << ":" << min << ":" << sec << endl;
    }

    void  resetdate(){
        jr = 01;
        ms = 01 ;
        an = 1900;
        heure_Automatique();
    }
    bool  controle_date(){
        if(jr<0 || jr>31 || ms<1 || ms>12 || an<1900 || an>2021)
            return false;
        return true;
    }
    bool  controle_heure(){
        if(hr<0 || hr>24 || min<00 ||min>59 || sec<<00 ||sec>59 )
            return false;
        return true;
    }

    void Ajouter_date(){
        do {
        cout<<"entrer la date [JJ MM AAAA ] :"; cin>>jr>>ms>>an;
        } while (!controle_date());
        cout<<"tapez [1 - 2] pour entrer l'heure :"<<endl;
        Ajouter_heure();
        cout<<"les donnes bien enregistrer"<<endl;

    }

    void Ajouter_heure(){
        int choix;
   I:   cout<<"1- Automatiquement [temps de system]"<<endl;
        cout<<"2- Manuellement :"<< endl;
        cin>>choix;

        if(choix == 1){
            heure_Automatique();
        }
        else if(choix == 2){
            heure_Manuelle();
        } else{
            cout<<" verifier le choix";
            goto I;
        }
    }

    int comparer_date() {  // pour afficher l'age d'objet courant
        return (nowlocal.tm_year + 1900) - an;
    }
    int comparer_mois(){  // retourne difference de mois
        return (nowlocal.tm_mon+1)-ms ;
    }
    int comparer_jour(){   // retourne difference de jours
        return nowlocal.tm_mday-jr;
    }


    // optional ;
    int comparer_date(date &d){  // cette methode return l'age entre deux date en annees
        cout<<"diffirence de jours :"<<   nowlocal.tm_mday-d.jr<< endl;
        cout<<"diffirence de mois :"<<   (nowlocal.tm_mon+1)-d.ms<<endl;
        cout<<"diffirence d'annees :"<<   (nowlocal.tm_year+1900)-d.an<<endl;
        cout<<"difference d'heurs " <<   nowlocal.tm_hour- d.hr<<endl ;
         return   d.an - nowlocal.tm_year;
    }




    void date_Aujourdhui() const{
        // cout<<now<<endl;      // show the system time in sec : 1641142455
        cout<<"\xB2\xB2\xB2 date d'Ajourd'hui : "<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon+1<<"/"<<nowlocal.tm_year+1900<<endl;
        cout<<"\xB2\xB2\xB2 Time :"<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<":"<<nowlocal.tm_sec<<endl;
        cout<<"\xB2\xB2\xB2 "<<endl;
    }

    void heure_Automatique(){
        while (true){
            hr=nowlocal.tm_hour;
            min=nowlocal.tm_min;
            sec=nowlocal.tm_sec;
            break;
        }

    }
    bool heure_Manuelle(){
        do {
        cout<<"entrer l'heure[h:m:s]";cin>>hr>>ms>>sec;
        } while (!controle_heure());
        cout<<"l'heure est effectuer"<<endl;
        return true;
    }

/*

    date& operator = (date date1){
        this->jr=date1.jr;
        this->ms=date1.ms;
        this->an=date1.an;
        this->hr=date1.hr;
        this->min=date1.min;
        this->sec=date1.sec;
        return *this;
    }
    */
};

#endif