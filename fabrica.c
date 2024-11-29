#include "fabrica.h"

FILE *logDeHoy;

int solicitarIdentificador(){
    int  identificador;
    printf("\nPor favor introduzca su identificador: ");
    scanf("%d",&identificador);
    if(identificador < 1 || identificador > 9999){
        printf("\nPor favor introduzca su identificador entre 1 y 9999\n");  
        solicitarIdentificador();
    }
    return identificador;
}

int eligeOpcionMenu(){

    int eleccionUsuario;
    printf("\nElige la opcion deseada:\n");
    printf("1) Introducir error\n");
    printf("2) Visualizar los errores de hoy\n");
    printf("3) Vaciar errores hoy\n");
    printf("4) Terminar jornada\n\n");
    
    printf("Accion: ");
    scanf("%d",&eleccionUsuario);

    if(eleccionUsuario < 1 || eleccionUsuario > 4)puts ("\nError. Introduce un valor correcto.");

    return eleccionUsuario;
}

int generarLogDeHoy(){
    
    int archivoGeneradoCorrectamente = 0;
    time_t tiempoActual = time(NULL);  //tiempo actual en segundos, el argumento NULL indica que no se quiere guardar en ningun puntero
    struct tm tiempoActualFraccionado = *localtime(&tiempoActual); //convierte un puntero al tiempo time:t a una estructura tm con valores feraccionados
   
    if(strftime(fechaActual,sizeof(fechaActual),"%Y-%m-%d",&tiempoActualFraccionado)!=0){ // con esta funcion formateamos 
        logDeHoy = fopen(fechaActual,"a");
    
    if(logDeHoy != NULL){
        fclose(logDeHoy);
        archivoGeneradoCorrectamente = 1;
    }
    else puts("Error al abrir el archivo");
    } 
    return archivoGeneradoCorrectamente;
}

void introducirError(int idOperario){
    
    char error[150];
    
    puts("Introduce el mensaje de error: ");
    getchar();
    gets(error);

    logDeHoy = fopen(fechaActual,"a");

    if(logDeHoy !=NULL){
        fprintf(logDeHoy,"\n%d - %s\n",idOperario, error);
        fclose(logDeHoy);
    }else puts("Error al abrir el archivo.");
}

void visualizarLog(){

    if(logDeHoy != NULL){
        fopen(fechaActual,"r");
        puts("\nEl historial de errores de hoy es: \n");
        char caracter;
        while((caracter = fgetc(logDeHoy))!=EOF)printf("%c", caracter);
        printf("\n");
        fclose(logDeHoy);
    } else puts("Error al abrir el archivo");
}

void eliminarLogDeHoy(){
    char confirmacion = 'n';
    puts("¿Estas seguro de vaciar el historial de hoy? (s/n)");
    getchar();

    scanf("%c",&confirmacion);
    if(confirmacion == 's'){

        char copiaDeSeguridad[150];
        strcpy(copiaDeSeguridad,"Copia de seguridad del día ");
        strcat(copiaDeSeguridad, fechaActual);
        rename(fechaActual, copiaDeSeguridad);
        remove(fechaActual);

    } 
}