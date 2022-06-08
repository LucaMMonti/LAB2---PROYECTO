#include <iomanip>
#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "fecha.h"
#include "clases.h"
#include "Empleado.h"
#include "Presentismo.h"

using namespace std;
///Prototipos
void CargaDatos();
    int BuscarLegajo(int leg);

void ListadoEmpleado(int);
void MostrarSector (int sector);
int CantRegistrosEmpleado();

void AsistenciaDelMes();
void AsistenciaPersonal();
void ListadoAsistencia();
///funciones
void CargaDatos(){
    Empleado obj;
    int leg, encontro;
    cout<<"INGRESAR LEGAJO "<<endl;
    cin>>leg;
    encontro=BuscarLegajo(leg);
    if(encontro==-2){
        obj.Cargar(leg);
        if(obj.GrabarEnDisco()==true){
          cout<<"SE GRABO CORRECTAMENTE"<<endl;
        }
    }
    else{
        cout<<"EMPLEADO YA SE ENCUENTRA DADO DE ALTA "<<endl;
    }
}

int BuscarLegajo(int leg){
    Empleado obj;
    int pos=0;
    while(obj.leerDisco(pos)==1){
        if(obj.getLegajo()==leg){
            return pos;
        }
        pos++;
    }
    return -2;
}
void BajaEmpleado();

void BajaEmpleado(){
    Empleado obj;
    int leg, encontro=0;
    cout<<"INGRESAR LEGAJO "<<endl;
    cin>>leg;
    encontro=BuscarLegajo(leg);
    if(obj.leerDisco(encontro)==1){
        obj.setEstado(false);
        cout<<"SE GENERO LA BAJA DEL EMPLEADO "<<endl;
    }
}

void ListadoEmpleado(int sector){
    Empleado obj;
    int pos=0, contador=0;
    cout<<"========== SECTOR ";
    MostrarSector(sector);
    cout<<" =========="<<endl;
    cout <<"LEGAJO";
    cout << "\tAPELLIDOS";
    cout << "\tNOMBRES";
    cout << "\tDNI";
    cout << "\tALTA" << endl;
    while(obj.leerDisco(pos++)==1){
        if(obj.getSector()==sector){
                cout << obj.getLegajo();///lEGAJO
                cout << "\t" << obj.getApellido();
                cout << "\t" << "\t"<< obj.getNombre();
                cout << "\t" << obj.getDni();
                cout << "\t" << obj.getFechaAlta().getDia()<< "/"; cout << obj.getFechaAlta().getMes() << "/";
                cout << obj.getFechaAlta().getAnio();
                cout << endl;
                contador++;
        }
    }
    cout<<" =============================="<<endl;
    cout<<"HAY "<<contador<<" EMPLEADOS EN LA CATEGORIA."<<endl;
    return;
}

void MostrarSector (int sector){
    if(sector==1){
        cout<<"ADMINISTRACION";
        return;
    }
    else{
        if(sector==2){
        cout<<"PRODUCCION";
        return;
        }
        else{
            if(sector==3){
                cout<<"RRHH";
                return;
            }
        }
    }
}

int CantRegistrosEmpleado(){
    int cant, bytes;
    FILE *Po=fopen("Empleados.dat","rb");
    if(Po==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            fclose(Po);
            return false;
        }
        fseek(Po,0,2);
        bytes=ftell(Po);
        cant=bytes/(sizeof(Empleado));
        fclose(Po);
        return cant;
}

void AsistenciaPersonal(){
    Empleado obj;
    Presentismo aux;
    int leg,pos, opc=1;
    bool grabo;
    while(opc!=0){
    cout<<"INGRESAR LEGAJO A CARGAR "<<endl;
    cin>>leg;
        pos=BuscarLegajo(leg);
        if(pos>=0){
            aux.Cargar(leg);
            grabo=aux.grabarDisco();
            if(grabo==true){
                cout<<"ASISTENCIA CARGADA CORRECTAMENTE "<<endl;
            }
        }
        else{
            cout<<"NO FIGURA EL EMPLEADO EN LA BASE"<<endl;
        }
        cout<<"¿DESEA CARGAR OTRA ASISTENCIA? "<<endl;
        cout<<"1 -  SI"<<endl;
        cout<<"0 -  NO"<<endl;
        cin>>opc;
    }
}

void ListadoAsistencia(){
    Presentismo obj;
    Empleado aux;
    int leg, pos;
        cout<<"INGRESAR LEGAJO A BUSCAR "<<endl;
        cin>>leg;
        pos=BuscarLegajo(leg);
        if(pos>=0){
            cout<<"============= ASISTENCIA  ";
            aux.leerDisco(pos);
            cout<<aux.getApellido();
            cout<<" ============="<<endl;
            pos=0;
            cout <<"LEGAJO";
            cout << "\tINGRESO";
            cout << "\t"<<"\tEGRESO" << endl;
            while(obj.leerDisco(pos)==1){
                if(obj.getLegajo()==leg){
                    cout << obj.getLegajo();///lEGAJO
                    cout << "\t" << obj.getFechaEntrada().getDia()<< "/"; cout << obj.getFechaEntrada().getMes() << "/";
                    cout << obj.getFechaEntrada().getAnio();
                    cout << "\t" << obj.getFechaSalida().getDia()<< "/"; cout << obj.getFechaSalida().getMes() << "/";
                    cout << obj.getFechaSalida().getAnio();
                    cout << endl;
                }
                pos++;
            }
        }
}

#endif // CLASES_H_INCLUDED
