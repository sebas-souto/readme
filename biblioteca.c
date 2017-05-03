//PROGRAMA BIBLIOTECA
#include "biblioteca.h"
#include "pantalla.h"
#include "base_de_datos.h"
#include "pantalla.c"
#include "base_de_datos.c"

int main(){
	if (comprobacion()==0) return 1;
	pantalla('#',80,"BIBLIOTECA");
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
	int numero=0;
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
		if(k==1) correcto=0;						//COMPRUEBA SI ES UN NUMERO
		numeroC[k-1]='\0';
		if(atoi(numeroC)<=numero) correcto=0;		//COMPRUEBA QUE LOS NUMEROS VAN EN ORDEN ASCENDENTE
		numero=atoi(numeroC);
		if (numero<1||numero>50) correcto=0;		//COMPRUEBA QUE EL NUMERO ESTA ENTRE 0 Y 16 BYTES
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
	int signatura=0, anho, votantes, votos, criticos, lector;	
	int k, correcto=1, puntos=0, posicion=0;
	FILE *referencias;
	referencias = fopen("referencias.txt","r");
	while(fgets(cadena,sizeof(cadena),referencias)!=NULL){
		//printf("%c",cadena[0]);
		if(cadena[0]==':'){
			if (cadena[strlen(cadena)-2]!=':') correcto=0;
			for(k=0;k<strlen(cadena);k++){
				if(cadena[k]==':')puntos++;}
			if (puntos!=9) correcto=0;					//COMPRUEBA QUE EXISTAN SOLO DOS PUNTOS
	//		printf("%i",puntos);
			puntos=0; posicion=0;
			//SIGNATURA
			for(k=1;(isdigit(cadena[k]))&&cadena[k]!=':';k++)
				numeroC[k-1]=cadena[k];
			if(k==1) correcto=0;						//COMPRUEBA SI ES UN NUMERO
			numeroC[k-1]='\0';
			if(atoi(numeroC)<=signatura) correcto=0;		//COMPRUEBA QUE LOS NUMEROS VAN EN ORDEN ASCENDENTE
			signatura=atoi(numeroC);
			if (signatura<1||signatura>50) correcto=0;		//COMPRUEBA QUE EL NUMERO ESTA ENTRE 0 Y 16 BYTES
			
			//TIPO
			for(k=0;puntos<3;k++){
				if(cadena[k]==':') posicion=k+1;puntos++;}
			tipo=cadena[posicion];
			if(tipo!='L'&&tipo!='A'&&tipo!='a')correcto=0; //COMPRUEBA QUE TIPO ESA A L a

			puntos=0;posicion=0;
			//AUTOR
			
		}
		else if(cadena[0]=='#'){
			if (cadena[strlen(cadena)-2]!=':') correcto=0;
				for(k=0;k<strlen(cadena);k++){
					if(cadena[k]==':')puntos++;}
			if (puntos!=2) correcto=0;					//COMPRUEBA QUE EXISTAN SOLO DOS PUNTOS
			//COMPROBAR NUMERO LECTOR
			for(k=1;(isdigit(cadena[k]))&&cadena[k]!=':';k++)
				numeroC[k-1]=cadena[k];
			if(k==1) correcto=0;						//COMPRUEBA SI ES UN NUMERO
			numeroC[k-1]='\0';
			lector=atoi(numeroC);
			if (lector<1||lector>50) correcto=0;		//COMPRUEBA QUE EL NUMERO ESTA ENTRE 0 Y 16 BYTES
			//COMPROBAR OPINION
			for(k=0;k<strlen(cadena)-3;k++){
				if(cadena[k]==':') posicion=k+1;}
			for(k=0;k<strlen(cadena)-3;k++){
				opinion[k]=cadena[k+posicion];}
			opinion[strlen(opinion)-2]='\0';
			if(strlen(opinion)>MAX_LONG_OPINION) correcto=0; //COMPRUEBA LA LONGITUD MAX DE OPINION
//			printf("numero: %i nombre: %s\n",lector,opinion);
			posicion=0; puntos=0;
			for(k=0;k<MAX_LONG_NOMBRE;k++){
				opinion[k]='\0';}
			
		}
		else correcto=0;
	//	printf("%s\n",cadena);
	
	}
	fclose(referencias);
	if (correcto==1) return 1;
	return 0;
}

