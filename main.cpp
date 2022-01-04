#include "service.h"


int main() {
    std::cout << "BONJOUR, World!" << std::endl;

     service *Tabservices ;
     Tabservices= new service[20]; // not sure
     Tabservices->ajouter_inf();

    return 0;
}
