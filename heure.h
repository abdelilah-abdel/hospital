#include <iostream>
#include <string>
#include <ctime>
using  namespace std;



class  heure {
private:
    int h;
    int m;
    int s;
public:

    heure(){
        h=0; m=00; s=0;
    };

    void  show_heure() const{
        cout<<h<<"h:"<<m<<"m:"<<s<<"s";
    }

    static bool  verifier_heure(heure &test){
        if (test.h >59 || test.h<0 || test.m<=59 || test.m <0 || test.s > 59 ||test.s <0 )
            return false;
        return true;
    }

    void entrer_heure(heure &test){
        if (verifier_heure(test))
        {
            h= test.h ;
            m= test.m ;
            s= test.s;
        } else
            std::cout<<"l'heur entre est invalid"<<std::endl ;

    }

    ~heure(){
        cout<<"heure destructed";
    };
  friend  heure::reset_heure();
};



void heure::reset_heure(){
    h=0; m=00; s=0;
}