//Agregar referencia
#include<stdio.h>
#include<string.h>
#define LONGITUD 50
void agregar_referencia();
void autor();
void titulo();
void anio();
void tipo();
void imprimir();
int cadena_vacia(char cadena[LONGITUD]);
void confimar (int limite ,char *pantalla);
int main(){
	agregar_referencia();
	return 0;
}

void agregar_referencia(){
	
	autor();	
	titulo();
	anio();
	tipo();

}



void autor(){

	char pantalla[]="Escribe el autor de la referencia: ";
	confimar(LONGITUD,&pantalla);
}
void titulo(){

	char pantalla[]="Escribe el titulo: ";
	confimar(80,&pantalla);
}

void anio(){
	int cadena[5];
	int year,correcto=0;
	do{
	
	printf("Escribe el anho: ");
	fgets(cadena,sizeof(cadena),stdin);
	year=atoi(cadena);
	if((1450<year)&&(year<2017)){
		correcto=1;
	}
	else{
		imprimir(5);
		correcto=0;
	}
	}while(correcto==0);
	
}


void tipo(){
	int i,correcto=0,repetido;
	char tipo[5];
	do{
		printf("Escribe el tipo: ");
		fgets(tipo,sizeof(tipo),stdin);
		correcto=1;
		i=0;
		
		if (tipo[0]=='\n' ||tipo[0]=='\0'){    		          //CADENA VACIA
			correcto=0;
			imprimir(2);
			}
		else if (1<strlen(tipo)-1){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			imprimir(3);
			}                                           //CARACTER INVALIDO 
		else if (tipo[0]=='A'||tipo[0]=='a'||tipo[0]=='L'||tipo[0]=='l'){                 
			
					correcto=1;
					
		
			}
		else{
			correcto=0;
			imprimir(1);
		}
			
			
				
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
	
}



void confimar (int limite,char *pantalla){
	int i,correcto,resultado;
	char cadena[limite];
	do{
		printf("%s",pantalla);
		fgets(cadena,sizeof(cadena),stdin);
		correcto=1;
		
		if (cadena[0]=='\n'){    				          //CADENA VACIA
			correcto=0;
			imprimir(2);
			}
		else if (cadena[strlen(cadena)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			imprimir(3);
			while (fgetc(stdin) != '\n');
			}
		else {                                            //CARACTER INVALIDO 
			for (i=0;i<strlen(cadena);i++){                 
				if (cadena[i]==':'){
					correcto=0;
					imprimir(1);
			    }
				
			}
		}
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
	

}


void imprimir(int linea){
	char *errores[]={
	/*0*/   "\nError de formato en un fichero: “Linea mal formada en el fichero (NOMBRE_FICHERO)\n\n",
	/*1*/   "\nCaracter invalido\n\n",
	/*2*/   "\nCadena vacia\n\n",
	/*3*/   "\nLongitud de cadena excesivan\n\n",
	/*4*/   "\nLector repetido\n\n",
	/*5*/ "\nValor seleccionado incorrecto\n\n",
	/*6*/ "\nOperacion imposible en este momento\n\n",
	};
	
	printf("%s",errores[linea]);
}



