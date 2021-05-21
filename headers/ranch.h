#ifndef RANCH_H
#define RANCH_H

#include "pigshall.h"

#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>

/************************* Ranch class *************************/
class Ranch
{
public:
    void addHall(PigsHall*);
    QVector<PigsHall*> pigsHalls();

    QJsonObject getJson();
    void loadRanchFromJson(QJsonDocument);

private:
    QVector<PigsHall*> halls;
};
/**************************************************************/

extern Ranch *ranch;

#endif // RANCH_H
