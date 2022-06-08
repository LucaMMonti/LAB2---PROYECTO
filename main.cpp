#include <iostream>
#include "fecha.h"
#include "clases.h"
#include "Empleado.h"
#include "Menus.h"
#include "Presentismo.h"


using namespace std;
int main(){
    int opc, Eleccion, opcDatos, cat;
    Empleado obj;

     while(true){
        system("cls");
        cout<<"============== MENU =============="<<endl;
        cout<<"1. ALTAS/BAJAS DE PERSONAL   "<<endl;
        cout<<"2. CARGA DE ASISTENCIA       "<<endl;
        cout<<"3. CONSULTAS     "<<endl;
        cout<<"=================================="<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    Eleccion=MenuAltaBaja();
                    if(Eleccion==1){
                        CargaDatos();///CARGAR ALTA
                    }
                    else{
                        if(Eleccion==2){
                            BajaEmpleado();//GENERAR BAJA
                        }
                    }
                break;
            case 2:
                AsistenciaPersonal();
                break;
            case 3:
                if(MenuConsultas()==1){
                    cat=MenuDatosDelPersonal();
                    ListadoEmpleado(cat);
                }
                else{
                    if(MenuConsultas()==2){
                        ListadoAsistencia();
                    }
                    else{
                        if(MenuConsultas()==3){
                            ///vacaciones
                        }
                    }
                }
            break;
            case 4:
                break;
            case 5:
                cout<<CantRegistrosEmpleado();
                break;
            case 0:
                return 0;
        }
        system("pause>null");
    }
return 0;
}

