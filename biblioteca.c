//PROGRAMA BIBLIOTECA
#include "biblioteca.h"
#include "pantalla.c"
#include "base_de_datos.c"

int main(){
	if (comprobacion()==0) return 1;
	pantalla();
	return 0;
}

int comprobacion(){
	FILE *pf;
	pf = fopen("lectores.txt","r");
	if (pf==NULL){		//SI NO EXISTE EL TXT LO CREA
		printf("lectores.txt no existe y se ha creado\n");
		pf = fopen("lectores.txt","w");}
	else if (comprobar_lectores()==0){		//SI EXISTE Y NO TIENE EL FORMATO CORRECTO SE CIERRA
		printf("Linea mal formada en el fichero(lectores.txt)\n");
		return 0;}
		
	FILE *pf2;
	pf2 = fopen("referencias.txt","r");
	if (pf2==NULL){ 	//SI NO EXISTE EL TXT LO CREA
		printf("referencias.txt no existe y se ha creado\n");
		pf = fopen("referencias.txt","w");}
	else if(comprobar_referencias()==0){	//SI EXISTE Y NO TIENE EL FORMATO CORRECTO SE CIERRA
		printf("Linea mal formada en el fichero(referencias.txt)");
		return 0;}
	fclose(pf);
	fclose(pf2);
	return 1;
}

int comprobar_lectores(){
	char cadena[256], numeroC[10];
	char nombre[MAX_LONG_NOMBRE];
	int numero;
	int k, correcto=1, puntos=0, posicion=0;
	FILE *lectores;
	lectores = fopen("lectores.txt","r");
	while(fgets(cadena,sizeof(cadena),lectores)!=NULL){
		if (cadena[0]!=':') correcto=0;
		if (cadena[strlen(cadena)-2]!=':') correcto=0;
		for(k=0;k<strlen(cadena);k++){
			if(cadena[k]==':')puntos++;}
		if (puntos!=3) correcto=0;
		puntos=0;
		//NUMERO
		for(k=1;(isdigit(cadena[k]))&&cadena[k]!=':';k++)
			numeroC[k-1]=cadena[k];
		if(k==1) correcto=0;
		numeroC[k-1]='\n';
		numero=atoi(numeroC);
		if (numero<1) correcto=0;
		//NOMBRE
		for(k=0;k<strlen(cadena)-3;k++){
			if(cadena[k]==':') posicion=k+1;}
		for(k=0;k<strlen(cadena)-3;k++){
			nombre[k]=cadena[k+posicion];}
		nombre[strlen(nombre)-2]='\0';
		if(strlen(nombre)>MAX_LONG_NOMBRE) correcto=0;
//		printf("numero: %i nombre: %s\n",numero,nombre);
		posicion=0;
		for(k=0;k<MAX_LONG_NOMBRE;k++){
			nombre[k]='\0';
		}
	}
	fclose(lectores);
	if (correcto==1) return 1;
	return 0;
}

int comprobar_referencias(){
	char cadena[256], numeroC[10];
	char tipo, autor[MAX_LONG_AUTOR], titulo[MAX_LONG_TITULO], opinion[MAX_LONG_OPINION];
	int signatura, anho, votantes, votos, criticos, lector;	
	int k, correcto=1, puntos=0, posicion=0;
	FILE *referencias;
	referencias = fopen("referencias.txt","r");
	while(fgets(cadena,sizeof(cadena),referencias)!=NULL){
	//	printf("%s\n",cadena);
	}
	fclose(referencias);
	if (correcto==1) return 1;
	return 0;
}

