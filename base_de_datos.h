#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void programa(int eleccion);
//BASICAS--------------------------------------------
void incorporar_lector(int *ult_lect);
void agregar_referencia(int *id);
void obtener_informe(int ult_sign);
void expresar_opinion(int ult_sign,int ult_lect);
void emitir_voto(int ult_sign);
void calcular_nota(int ult_sign);
//AVANZADAS------------------------------------------
void listar_referencia(int ult_sign);
	void  dame_referencias(char refe,int ult_sign);
void buscar_referencia(int ult_sign);
	int busca(char *cadena, int tamanio);
	int compara_nombre(char *cadena,int tamanio);
	int compara_titulo(char *cadena,int tamanio);
	int compara(char *cadena1,char *cadena2);
	void imprime_bus(int x);
void cambiar_lector(int tam_lec);
	int encontrar(char *buscar, int tamanio,int inicio);
	void cambiar(int x,char *nuevo,char *buscar,int tam_lec);
//LECTOR---------------------------------------------
int comprobar_lector(char nombre[MAX_LONG_NOMBRE], int *ultimo);
void asignar_id(char nombre[MAX_LONG_NOMBRE],int *ultimo);
//REFERENCIA-----------------------------------------
void dame_cadena(int limite ,char *pantalla,char *cadena2);
void dame_autor(int sign);
void dame_titulo(int sign);
void dame_anio(int sign);
void dame_tipo(int sign);
int dame_signatura(int ult_sing);
//ACTUALIZAR TXTs------------------------------------
void actualizar_lector (int ult_lect);
void actualizar_refe (int ult_sing);
//LEER LECTOR-----------------------------------------
int leer_lector();
void  obtener_puntos(char *cadena,int *pts);
void obtener_codigo(char *cadena, int *pts,int id);
void obtener_nombre(char *cadena, int *pts,int id);
//LEER REFERENCIA------------------------------------
int leer_referencia();
void datos(char *cadena, int *id);
void opinions(char *cadena, int *id2,int *id);
void puntos(char *cadena,int *pts);
void signa(char *cadena, int *pts,int *sign);
void tipo(char *cadena, int *pts, int *sign);
void autor(char *cadena, int *pts, int *sign);
void titulo(char *cadena, int *pts, int *sign);
void anho(char *cadena, int *pts,int *sign);
void votantes(char *cadena, int *pts,int *sign);
void votos(char *cadena, int *pts,int *sign);
void criticos(char *cadena, int *pts,int *sign);
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
    float votos;
    int criticos;
	struct informacion info[100];
};
struct lectores lector[100];
struct referencia refe[100];
