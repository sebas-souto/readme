//TITULO MENU & CONFIRMACION SALIDA
#include "pantalla.h"

void pantalla (){
	caratula('#',80,"BIBLIOTECA"); //IMPRIMIMOS LA CARTULA
	char selec, cadena[256];	
	do{		
		printf("\n1) Incorporar lector\n2) Agregar referencia\n3) Expresar opinion\n4) Obtener informe\n5) Emitir voto\n6) Calcular nota\n7) Listar referencias\n8) Buscar referencias\n9) Cambiar lector\n0) Salir\n\nSiguiente comando? ");
		fgets(cadena,sizeof(cadena),stdin);		
		selec=cadena[0];
		if (cadena[1]!='\n') selec='X';	//SI NO SE INTRODUCE UN SOLO CARACTER INVALIDA EL 1�

		switch (selec){
			case '1':
				base_de_datos(1);
				break;
			case '2':
				base_de_datos(2);
				break;
			case '3':
				base_de_datos(3);
				break;
			case '4':
				base_de_datos(4);
				break;
			case '5':
				base_de_datos(5);
				break;
			case '6':
				base_de_datos(6);
				break;
			case '7':
				base_de_datos(7);
				break;
			case '8':
				base_de_datos(8);
				break;
			case '9':
				base_de_datos(9);
				break;
			case '0':
				selec=confirmar();
					if (selec==0) return;
				break;
			default:
				printf("\nHas realizado una seleccion no valida\n");
				break;
		}//switch
	}while (selec!='0');
}

int confirmar(){
	char selec, cadena[256];
	do{
		printf("\nSeguro que deseas salir del programa? (s/n): ");
		fgets(cadena,sizeof(cadena),stdin);
		selec=cadena[0];
		if (cadena[1]!='\n') selec='X'; 
		selec=toupper(selec);
		if (selec=='S'){
			return 0;}
		else if (selec=='N'){
			return 1;}
	} while (selec !='N');
}

void caratula(char simbolo, int ancho, char *texto){
	if (MAXIMO<ancho) ancho=MAXIMO;
	base(simbolo,ancho);
	lados(simbolo,ancho,2);
	tituloo(simbolo,ancho,texto);
	lados(simbolo,ancho,2);
	base(simbolo,ancho);}
	
int tituloo(char simbolo, int ancho, char *texto){
	if (ancho<strlen(texto)+2) return 1;   //SI EL ANCHO ES INSUFICIENTE RETORNA 1
	int k, lado, resto;
	lado=ancho-2-strlen(texto);
	resto=strlen(texto)%2;
	
	printf("%c",simbolo);
	for(k=0;k<resto+lado/2;k++){
		printf(" ");}
 	printf("%s",texto);
	for(k=0;k<lado/2;k++){
		printf(" ");}
	printf("%c\n",simbolo);
	return 0;}
	
void base(char simbolo, int ancho){
	int k;
	for(k=0;k<ancho;k++){
		printf("%c",simbolo);}
	printf("\n");		
	return;}
	
void lados(char simbolo, int ancho, int lineas){
	int k,i;
	for (i=0;i<lineas;i++){
			printf("%c",simbolo);
		for(k=0;k<ancho-2;k++){
			printf(" ");}
		printf("%c\n",simbolo);	}
	return;}
