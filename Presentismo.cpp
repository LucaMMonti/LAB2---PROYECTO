#include "Presentismo.h"
#include "fecha.h"
#include <iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

void Presentismo::Cargar(int leg){
    Legajo=leg;
    cout<<"INGRESAR FECHA ENTRADA"<<endl;
    FechaEntrada.Cargar();
    ///cout<<"INGRESAR HORA ENTRADA"<<endl;
    cout<<"INGRESAR FECHA SALIDA"<<endl;
    FechaSalida.Cargar();
    //cout<<"INGRESAR HORA SALIDA"<<endl;
}

void Presentismo::Mostrar(){}


bool Presentismo::grabarDisco(int pos){
    if(pos==0){
    FILE *p=fopen("Presentismo.dat","ab");
    if(p==NULL){
    cout<<"ERROR DE ARCHIVO "<<endl;
    fclose(p);
    return false;
    }
        if(fwrite(this,sizeof(Presentismo),1,p)==1){
            fclose(p);
            return true;
        }
    }
    else
    {
        FILE *p=fopen("Presentismo.dat","rb+");
        if(p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            fclose(p);
            return false;
        }
        fseek(p,pos*sizeof (Presentismo),0);
        if(fwrite(this,sizeof(Presentismo),1,p)==1) {
            fclose(p);
            return true;
        }
    }
}
bool Presentismo::leerDisco(int pos){
    FILE *pu=fopen("Presentismo.dat","rb");
    if(pu==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        fclose(pu);
        return false;
    }
    fseek(pu, pos*sizeof(Presentismo),0);
    if (fread(this,sizeof(Presentismo),1,pu)==1){
    fclose(pu);
    return true;
    }
}
