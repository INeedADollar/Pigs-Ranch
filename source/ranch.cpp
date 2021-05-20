#include "headers/ranch.h"

/************************* Ranch class *************************/
Ranch::Ranch()
{

}

void Ranch::addHall(PigsHall hall){
    halls.push_back(hall);
}

QVector<PigsHall> Ranch::pigsHalls() {
    return halls;
}
/**************************************************************/
