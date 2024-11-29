#include "fabrica.h"

int main(){

    int salida = 0,idOperario = solicitarIdentificador(),logGenerado = generarLogDeHoy();

    if(generarLogDeHoy() == 1){
        do {
            switch(eligeOpcionMenu()){
            case 1:introducirError(idOperario);break;
            case 2:visualizarLog();break;
            case 3:eliminarLogDeHoy();break;
            case 4:salida = 1;break;
            default:break;
        }
        }while(salida != 1);
    }
    return 0;
}

