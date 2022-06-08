#ifndef DIASTRABAJADOS_H_INCLUDED
#define DIASTRABAJADOS_H_INCLUDED

class DiasTrabajados{
    private:
    int Legajo, DiasLicencia, DiasSinActividad;
    public:
    //Gets
    int getDiaslicencia(){return diasLicencia;}
    int getSinActividad(){return diasSinActividad;}
    //Sets
    void setDiaslicencia (int licencia){diasLicencia=licencia;}
    void setSinActividad(int sinActividad){diasSinActividad=sinActividad;}
};

#endif // DIASTRABAJADOS_H_INCLUDED
