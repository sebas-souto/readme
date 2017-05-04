#define MAX_LONG_CODIGO 32767
#define MAX_LONG_NOMBRE 50
#define MAX_LONG_SINGNATURA 2147483647
#define MAX_LONG_AUTOR 50
#define MAX_LONG_TITULO 80
#define MAX_LONG_ANHO 32767
#define MAX_LONG_VOTANTES 32767
#define MAX_LONG_VOTOS 2147483647
#define MAX_LONG_CRITICOS 32767
#define MAX_LONG_LECTOR 32767
#define MAX_LONG_OPINION 80
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int comprobacion();
int comprobar_lectores();
int comprobar_referencias();
int comprobar_puntos(char *cadena,int n_pts);
int comprobar_num(char *cadena,int tam, int *numero, char ORDEN);
int comprobar_cadena(char *cadena,int tam,int sitio);
int comprobar_tipo(char *cadena,int tam);
int comprobar_numero(char *cadena,int tam,int sitio);
