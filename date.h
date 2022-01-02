#include <iostream>
#include "heure.h"

using namespace std;
class date {
private:
     int jr ;
     int m ;
     int an ;
     int hr ;
public:
    date(){
        jr = 01;
        m =01 ;
        an = 1900;
        hr = 00 ;
    }

    void get_date(){
       cout<<"date [jj/mm/aaaa/h] :"<< jour<<"/"<<mois<<"/"<<annee<<"/"<<;
    }
};