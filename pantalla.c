//TITULO MENU & CONFIRMACION SALIDA
#include "pantalla.h"
void pantalla (char simbolo, int ancho, char *texto){
	caratula(simbolo, ancho, texto); //IMPRIMIMOS LA CARTULA
	char cadena[256];	
	do{		
		printf("\n1) Incorporar lector\n2) Agregar referencia\n3) Expresar opinion\n4) Obtener informe\n5) Emitir voto\n6) Calcular nota\n7) Listar referencias\n8) Buscar referencias\n9) Cambiar lector\n0) Salir\n\nSiguiente comando? ");
		fgets(cadena,sizeof(cadena),stdin);
		if (cadena[1]!='\n') cadena[0]='X';	//SI NO SE INTRODUCE UN SOLO CARACTER INVALIDA EL 1º
		switch (cadena[0]){
			case '1':
				programa(1);
				break;
			case '2':
				programa(2);
				break;
			case '3':
				programa(3);
				break;
			case '4':
				programa(4);
				break;
			case '5':
				programa(5);
				break;
			case '6':
				programa(6);
				break;
			case '7':
				programa(7);
				break;
			case '8':
				programa(8);
				break;
			case '9':
				programa(9);
				break;
			case '0':
				cadena[0]=confirmar();
					if (cadena[0]==0) return;
				break;
			default:
				printf("\nHas realizado una seleccion no valida\n");
				break;
		}//switch
	}while (cadena[0]!='0');
}

void caratula(char simbolo, int ancho, char *texto){
	if (ANCHO_MAXIMO<ancho) ancho=ANCHO_MAXIMO;
	base(simbolo,ancho);
	lados(simbolo,ancho,2);
	Titulo(simbolo,ancho,texto);
	lados(simbolo,ancho,2);
	base(simbolo,ancho);}
	
void lados(char simbolo, int ancho, int lineas){
	int k,i;
	for (i=0;i<lineas;i++){
			printf("%c",simbolo);
		for(k=0;k<ancho-2;k++){
			printf(" ");}
		printf("%c\n",simbolo);	}
	return;}

void base(char simbolo, int ancho){
	int k;
	for(k=0;k<ancho;k++){
		printf("%c",simbolo);}
	printf("\n");		
	return;}
	
int Titulo(char simbolo, int ancho, char *texto){
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
	
int confirmar(){
	char cadena[256];
	do{
		printf("\nSeguro que deseas salir del programa? (s/n): ");
		fgets(cadena,sizeof(cadena),stdin);
		if (cadena[1]!='\n') cadena[0]='X'; 
		cadena[0]=toupper(cadena[0]);
		if (cadena[0]=='S'){
			return 0;}
		else if (cadena[0]=='N'){
			return 1;}
	} while (cadena[0]!='N');
}
