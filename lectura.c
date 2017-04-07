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
	int limite,error;
	error=existencia_fichero("lectores.txt");
	if(error==0) {
	printf("No existe el fichero\n");
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




