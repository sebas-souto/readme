/*SE HAN AÑADIDO DOS FUNCIONES:
1-EXISTENCIA DE FICHERO, COMPRUEBA SI UN TXT EXISTE O NO
2-COMPROBACION DE FORMA: SOLO MIRA SI TIENEN LOS DOS PUNTOS, EL PRIMERO Y ULTIMO.
OJO: NO MIRA LOS DOS PUNTOS DEL MEDIO!!!!*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lectores{
	int codigo;
	char nombre[256];
	
};

struct lectores lector[50000];

 int leer();
 int existencia_fichero(char txt [256]);

int main ( ){
	int limite,error,error2;
	error=existencia_fichero("lectores.txt");
	if(error==0) {
	printf("No existe el fichero\n");
	return 0;
	}
	error2=formator_correcto();
	if(error2==0) {
	printf("Formato incorrecto\n");
	return 0;
	}
	limite=leer();
	int i=0;

	for(i=0;i<limite-1;i++){
		printf("%i %s \n",lector[i].codigo,lector[i].nombre);
	}

 return 0;
}


int leer( ){

 	int num=0;
  	int leo,linea; 
    char nombre[256];
    
    
	int i=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");
    
    
    while(leo!=EOF){
	
		leo= fscanf(archivo,":%i:",&num);
		fgets(nombre,sizeof(nombre),archivo);
		linea=strlen(nombre);
		
		if (nombre[linea-1]=='\0'){
		
		nombre[linea-2]='\0';
		}
	
		else{
			nombre[linea-1]='\0';
		}
		/*
		AQUI LLAMAMOS LA FUNCION QUE CONFIRME QUE LA VARIABLE NOMBRE[] Y NUM CUMPLAN LOS REQUISITOS:
	
		*/
	    
	    
	    
		lector[i].codigo=num;
		strcpy(lector[i].nombre,nombre);
		i++;
}


    fclose(archivo);
	return i;
}

int	existencia_fichero(char txt [256]){
	/*DEVUELVE 1 SI EXISTE EL FICHERO 0 SI NO EXISTE.*/
	int existencia=1;
	FILE *archivo;
    archivo = fopen(txt, "r");
    if(archivo){
		return existencia;
	}
	else{
		existencia =0;
		return existencia;
	}
	
}



int	formator_correcto(){
	int formato=1;
	int existencia=1;
	FILE *archivo;
    archivo = fopen("lectores.txt", "r");
	int leo=0,num,linea;
	char nombre[256];
	
	
	  while(leo!=EOF){
	
		leo= fscanf(archivo,":%i:",&num);
		//printf("%i\n",leo);
		if(leo==-1) return formato;
		fgets(nombre,sizeof(nombre),archivo);
	//	printf("%s\n",nombre);
		linea=strlen(nombre);
		if(leo!=1 ||nombre[linea-2]!=':' ) {
		
		return 0;
		}
		
	}
	
	return formato;
}



