#ifndef FABRICA_H
#define FABRICA_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char fechaActual[15];

int eligeOpcionMenu();
int solicitarIdentificador();
int generarLogDeHoy();
void introducirError(int idOperario);
void visualizarLog();
void eliminarLogDeHoy();

#endif