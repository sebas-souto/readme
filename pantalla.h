#define ANCHO_MAXIMO 90
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void pantalla(char simbolo, int ancho, char *texto);
void caratula(char simbolo, int ancho, char *texto);
void lados(char simbolo, int ancho, int lineas);
void base(char simbolo, int ancho);
int Titulo(char simbolo, int ancho, char *texto);
int confirmar();
