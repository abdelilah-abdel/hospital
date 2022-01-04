#include <iostream>
#include <string>
#include <time.h>

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
    time_t now = time(
            NULL);                   // pour stocker le temps de systm de type time_ t --> nbr de sec   // affectation le temps de  system a la variable time ;
    struct tm nowlocal = *localtime(
            &now);   // pour transformer la variable now(nbrdesec) a une variable type tm qui est strecture est differencies les chiifre entre min sec month year days ....etc
public:

    date() {
        jr = 01;
        ms = 01;
        an = 1900;
        heure_Automatique();
    }

    void Afficher_date() {
        cout << "date [jj/mm/aaaa/h] :" << jr << "/" << ms << "/" << an << "/" << endl;
        cout << "Temps(" << hr << ":" << min << ":" << sec << endl;
    }

    void  resetdate(){
        jr = 01;
        ms = 01 ;
        an = 1900;
        heure_Automatique();
    }

    void Ajouter_date(){
        cout<<"entrer la date [JJ MM AAAA ] :"; cin>>jr>>ms>>an;
        cout<<"les donnes bien enregistrer"<<endl<<endl<<endl ;
        Ajouter_heure();
    }

    void Ajouter_heure(){
        int choix;
        I:    cout<<"1 - Automatic[temps de system]"<<endl;
        cout<<"2- Manuelle:"<< endl;
        cout<<"3- choisisez entre les deux"; cin>>choix;
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

    int getjour(){ return  jr;}
    int getmois(){ return  ms;}
    int getannee(){return  an;}

    int comparer_date(date &d){
        //   Afficher_date();
        cout<<"diffirence de jours :"<<   nowlocal.tm_mday-d.jr<< endl;
        cout<<"diffirence de mois :"<<   (nowlocal.tm_mon+1)-d.ms<<endl;
        cout<<"diffirence d'annees :"<<   (nowlocal.tm_year+1900)-d.an<<endl ;
        cout<<"difference d'heurs " <<   nowlocal.tm_hour- d.hr<<endl ;
        return   d.an - nowlocal.tm_year;
    }

    int comparer_date(){
        //   Afficher_date();
        cout<<"diffirence de jours :"<<   nowlocal.tm_mday-jr<< endl;
        cout<<"diffirence de mois :"<<   (nowlocal.tm_mon+1)-ms<<endl;
        cout<<"diffirence d'annees :"<<   (nowlocal.tm_year+1900)-an<<endl ;
        cout<<"difference d'heurs " <<   nowlocal.tm_hour- hr<<endl ;

        return    (nowlocal.tm_year+1900)-an;
    }
    int comparer_mois(){
        return (nowlocal.tm_mon+1)-ms ;
    }
    int comparer_jour(){
        return nowlocal.tm_mday-jr;
    }

    void date_Aujourdhui(){
        // cout<<now<<endl;      // show the system time in sec : 1641142455
        cout<<"date d'Ajourd'hui :"<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon+1<<"/"<<nowlocal.tm_year+1900<<endl;
        cout<<"Time :"<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<":"<<nowlocal.tm_sec<<endl;
    }

    bool heure_Automatique(){

        hr=nowlocal.tm_hour;
        min=nowlocal.tm_min;
        sec=nowlocal.tm_sec;
        cout<<"l'heure est effectuer"<<endl;
        return true;
    }
    bool heure_Manuelle(){
        cout<<"entrer l'heure[h:m:s]";cin>>hr>>ms>>sec;
        cout<<"l'heure est effectuer"<<endl;
        return true;
    }
};
