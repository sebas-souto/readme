#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LONGITUD 50
int base_de_datos(int eleccion);
//BASICAS--------------------------------------------
int incorporar_lector(int *limite);
void agregar_referencia(int *id);
void obtener_informe(int *tamanio);
void expresar_opinion(int *tamanio,int *tam_lector);
void emitir_voto(int *tamanio);
void calcular_nota(int *tamanio);
//AVANZADAS------------------------------------------
//LECTOR---------------------------------------------
int comprobar_lector(char nombre[50], int *tamanio);
void asignar_id(char nombre[LONGITUD],int *limite);
//REFERENCIA-----------------------------------------
void confimar (int limite ,char *pantalla,char *cadena2);
void dame_autor(int *id);
void dame_titulo(int *id);
void dame_anio(int *id);
void dame_tipo(int *id);
//ACTUALIZAR TXTs------------------------------------
void actualizar_lector (int *limite);
void actualizar_refe (int *limite);
//LEER LECTOR-----------------------------------------
int leer_lector();
int*  obtener_puntos(char *cadena,int *pts);
void obtener_codigo(char *cadena, int *pts,int *id);
void obtener_nombre(char *cadena, int *pts,int *id);
//LEER REFERENCIA------------------------------------
int leer_referencia();
void datos(char *cadena, int *id);
void opinions(char *cadena, int *id2,int *id);
int* puntos(char *cadena,int *pts);
void signa(char *cadena, int *pts,int *id);
void tipo(char *cadena, int *pts, int *id);
void autor(char *cadena, int *pts, int *id);
void titulo(char *cadena, int *pts, int *id);
void anho(char *cadena, int *pts,int *id);
void votantes(char *cadena, int *pts,int *id);
void votos(char *cadena, int *pts,int *id);
void criticos(char *cadena, int *pts,int *id);
void lect(char *cadena, int *pts, int *id2, int *id);
void opinion(char *cadena, int *pts, int *id2, int *id);
//IMPRIMIR-------------------------------------------
void imprimir(int linea);

