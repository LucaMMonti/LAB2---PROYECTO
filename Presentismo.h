#ifndef PRESENTISMO_H_INCLUDED
#define PRESENTISMO_H_INCLUDED
#include "fecha.h"

class Presentismo{
private:
    Fecha FechaEntrada, FechaSalida;
    Fecha HoraEntrada, HoraSalida;
    int Legajo;
public:
    ///Gets
    Fecha getFechaEntrada(){return FechaEntrada;}
    Fecha getFechaSalida(){return FechaSalida;}
    Fecha getHoraSalida(){return HoraSalida;}
    Fecha getHoraEntrada(){return HoraEntrada;}
    int getLegajo(){return Legajo;}

    ///Sets
    void setFechaEntrada (Fecha f){FechaEntrada=f;}///ver dependiendo lo que se necesite
    void setFechaSalida (Fecha i){FechaEntrada=i;}///ver dependiendo lo que se necesite
    void setHoraSalida (Fecha s){HoraSalida=s;}
    void setHoraIngreso (Fecha i){HoraEntrada=i;}
    void setLegajo(int leg){Legajo=leg;}
    ///FUNCIONE LOCALES
    void Cargar(int leg);
    void Mostrar();
    bool grabarDisco(int pos=0);
    bool leerDisco(int);
};

#endif // PRESENTISMO_H_INCLUDED
