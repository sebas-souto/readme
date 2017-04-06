//INCORPORAR LECTOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LONGITUD 50 //LONGITUD MAXIMA CADENA

int main (){
	int i,correcto;
	char nombre[LONGITUD];
	do{
		printf("Escribe el nombre del lector: ");
		fgets(nombre,sizeof(nombre),stdin);
		correcto=1;
		i=0;
		
		if (nombre[0]=='\n'){    				          //CADENA VACIA
			correcto=0;
			printf("Cadena vacia\n");}
		else if (nombre[strlen(nombre)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			printf("Longitud excesiva\n");
			while (fgetc(stdin) != '\n');}
		else {                                            //CARACTER INVALIDO 
			while (i<strlen(nombre)){                 
				if (nombre[i]==':'){
					correcto=0;
					printf("Caracter invalido\n");}
					i++;}
			
			    //LECTOR REPETIDO
			    
			    
			    //ASIGNAMOS CODIGO REGISTRAMOS LECTOR IMPRIMIMOS LECTOR Y CODIGO	
		}	
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
	printf("Lector %s: asignado CODIGO",&nombre);
}
