#define LONGITUD 50
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int base_de_datos(int eleccion);
//BASICAS--------------------------------------------
int incorporar_lector(int *limite);
void agregar_referencia(int *id);
void obtener_informe(int *tamanio);
void expresar_opinion(int *tamanio,int *tam_lector);
void emitir_voto(int *tamanio);
void calcular_nota(int *tamanio);
//AVANZADAS------------------------------------------
void listar_referencia(int longi);
	void  dame_referencias(char refe,int tamanio);
void buscar_referencia(int tamanio);
	int busca(char *cadena, int tamanio);
	int compara_nombre(char *cadena,int tamanio);
	int compara_titulo(char *cadena,int tamanio);
	int compara(char *cadena1,char *cadena2);
	void imprime_bus(int x);
void cambiar_lector(int tam_lec);
	int encontrar(char *buscar, int tamanio,int inicio);
	void cambiar(int x,char *nuevo,char *buscar,int tam_lec);
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
//STRUCTS-------------------------------------------
struct lectores{
    int codigo;
    char nombre[256];
};
struct informacion{
    int lector;
    char opinion[80];
};
struct referencia{
    int signatura;
    char tipo;
    char autor[51];
    char titulo[81];
    int anio;
    int votantes;
    int votos;
    int criticos;
	struct informacion info[100];
};
struct lectores lector[100];
struct referencia refe[100];
