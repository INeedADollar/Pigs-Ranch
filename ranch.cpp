#include "ranch.h"

Ranch::Ranch()
{

}

void Ranch::addHall(PigsHall hall){
    halls.push_back(hall);
}

QVector<PigsHall> Ranch::pigsHalls() {
    return halls;
}
