//TITULO MENU & CONFIRMACION SALIDA
#include <stdio.h>
#include <ctype.h>
#include "pantalla.h"

int main (){
	char selec='1';
	
	titulo(); //IMPRIMIMOS LA CARTULA
	
	while (selec!='0'){
		
		printf("\n1) Incorporar lector\n2) Agregar referencia\n3) Expresar opinion\n4) Obtener informe\n5) Emitir voto\n6) Calcular nota\n0) Salir\n\nSiguiente comando? ");
		fscanf(stdin," %c",&selec);	

		switch (selec){
			case '1':
				return 1;
				break;
			case '2':
				return 2;
				break;
			case '3':
				return 3;
				break;
			case '4':
				return 4;
				break;
			case '5':
				return 5;
				break;
			case '6':
				return 6;
				break;
			case '0':
				selec=confirmar();
					if (selec==0){
						return 0;}
				break;
			default:
				printf("\nHas realizado una seleccion no valida\n");
				break;
		}//switch
	}//while
}

int confirmar(){
	char selec;
	do{
		printf("\nSeguro que deseas salir del programa? (s/n): ");
		fscanf(stdin," %c",&selec);
		selec=toupper(selec);
		if (selec=='S'){
			return 0;}
		else if (selec=='N'){
			return 1;}
	} while (selec !='N');
}

void titulo(){
	int k;
	base();
	lados(2);
	printf("#");
	for(k=0;k<34;k++){printf(" ");}
	printf("BIBLIOTECA");
	for(k=0;k<34;k++){printf(" ");}
	printf("#\n");
	lados(2);
	base();}
	
void base (){
	int k;
	for(k=0;k<80;k++){printf("#");}
	printf("\n");}
	
void lados (int num){
	int i,k;
	for(i=0;i<num;i++){
		printf("#");
		for(k=0;k<78;k++){printf(" ");}
		printf("#\n");}}
