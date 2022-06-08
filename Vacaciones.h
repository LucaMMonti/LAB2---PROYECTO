#ifndef VACACIONES_H_INCLUDED
#define VACACIONES_H_INCLUDED

class Vacaciones{
    private:
    int Legajo, Sector;
    Fecha FechaINI_Vacaciones;
    Fecha FechaFIN_Vacaciones;
    public:
    ///Gets
    int getLegajo(){return Legajo;}
    int getSector(){return Sector;}

    ///Set
    void setSector (int s){Sector=s;}
    ///Funciones Globales
    void Cargar();
    void Mostrar();
    bool grabarDisco();
    bool leerDisco();
};

#endif // VACACIONES_H_INCLUDED
