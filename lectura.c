//LO HE PROBADO Y EN PRINCIPIO FUNCIONA 100%.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LONGITUD 50 //LONGITUD MAXIMA CADENA
struct lectores{
	int codigo;
	char nombre[256];
	
};
 
struct lectores lector[100];
int incorporar_lector(int *limite);

void obtener_codigo(char *cadena, int *pts,int *id);
int leer_lector();
void obtener_nombre(char *cadena, int *pts,int *id);
int obtener_puntos(char *cadena,int *pts);
int comprobar_lector(char nombre[50], int *tamanio);
void asignar_id(char nombre[LONGITUD],int *limite);



int main(){
	int limite,resultado;
	limite=leer_lector();
	/*int i;
	 * printf("---------Tabla------\n");
	for (i = 0; i < limite; i++) {
		printf("%s ---Codigo: %i\n", lector[i].nombre,lector[i].codigo);
	}*/

	resultado=incorporar_lector(&limite);//1 nuevo 0 repetido.
	/*if(resultado==1) {
		printf("---------Tabla actualizada----\n");
		for (i = 0; i < limite; i++) {
			printf("%s \n", lector[i].nombre);
		}
	}*/


 return 0;
}





//INCORPORAR LECTOR
int incorporar_lector (int *limite){
	int i,correcto,repetido,resul;
	char nombre[LONGITUD];
	int tamanio=*limite;
	do{
		printf("Escribe el nombre del lector: ");
		fgets(nombre,sizeof(nombre),stdin);
		correcto=1;
		i=0;
		
		if (nombre[0]=='\n'){    				          //CADENA VACIA
			correcto=0;
			printf("Cadena vacia\n");
		}
		else if (nombre[strlen(nombre)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			printf("Longitud excesiva\n");
			while (fgetc(stdin) != '\n');
		}
		else {                                            //CARACTER INVALIDO 
			while (i<strlen(nombre)){                 
				if (nombre[i]==':'){
					correcto=0;
					printf("Caracter invalido\n");
			    }
					i++;
			}
			
			    //LECTOR REPETIDO
				int a;
				for(a=0;a<strlen(nombre);a++) {
					if(nombre[a]== '\n'){
						nombre[a] = '\0';
						break;
					}
				}
				//printf("---%s-----8888\n",nombre);
			    repetido=comprobar_lector(nombre,&tamanio);
			    if(repetido==0) {printf("Lector repetido.\n"); resul=0; correcto==1;  }
			    else {
					asignar_id(nombre,&tamanio);
			   		*limite=tamanio;
			   		printf("Lector %s: asignado %i\n",lector[tamanio-1].nombre,lector[tamanio].codigo);
					resul=1;
				}
			    //ASIGNAMOS CODIGO REGISTRAMOS LECTOR IMPRIMIMOS LECTOR Y CODIGO	
		}	
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
	//printf("\nLector %s: asignado %i \n",lector[tamanio].nombre,lector[tamanio].codigo);

	return resul;
}


int leer_lector(){

	char cadena[256];
	int pts[256];
	int id=0;
	FILE *archivo;
	archivo = fopen("lectores.txt", "r");

	while(fgets(cadena,sizeof(cadena),archivo)!=NULL){

		// fgets(cadena,sizeof(cadena),archivo);

		//   while (fgetc(archivo) != '\n');
		// printf("%s",cadena);
		if(cadena[0]==':'){
			// printf("%i :\n",id);
			obtener_puntos(cadena,pts);
			obtener_codigo(cadena,pts,&id);
			obtener_nombre(cadena,pts,&id);
			id++;
		}

		else{
			printf("Formato del fichero incorrecto\n");
		}
	}


	fclose(archivo);
	return id;

}

void obtener_codigo(char *cadena, int *pts,int *id){
	int num,x,p=0;
	int y=*id;
	char variable[10],cadena2[256];
	strcpy(cadena2,cadena);
	cadena2[pts[2]]='\0';
	//   printf("lector: %s-%i \n",cadena2,pts[2]);


	for(x=pts[1];x<pts[2];x++){
		if(cadena2[x]!=':') {
			variable[p] = cadena2[x];
			//   printf("lector: %s\n",variable);
			p++;
		}
	}
	//printf("lector: %s-",variable);
	num=atoi(variable);
	lector[y].codigo=num;
}

void obtener_nombre(char *cadena, int *pts,int *id){
	int num = 0, x=0;
	int y = *id;
	char cadena2[81];
	strcpy(cadena2, cadena);
	cadena2[pts[3]] = '\0';

	//printf("%s\n",cadena2);

	for (x = pts[2]; x < pts[3]; x++) {
		if (cadena2[x] != ':') {
			cadena2[num] = cadena2[x];
			num++;
			// printf("%c",cadena2[x]);
		}
	}
	cadena2[pts[3]-3] = '\0';
	 //printf("%s \n",cadena2);
	strcpy(lector[y].nombre, cadena2);
}

int obtener_puntos(char *cadena,int *pts){
	int i=0, j=0;
	//int pts[10];
	for(i=0;i<strlen(cadena);i++){
		if(cadena[i]==':'){
			j++;
			pts[j]=i;
			   //  printf("%i",i);
		}
	}
	// printf("\n");
	return pts;
}

int comprobar_lector(char nombre[50], int *tamanio){
	int limite=*tamanio;
	int resultado,i;
	//printf("limite comprobar lector: %i\n",limite);
	for(i=0;i<limite;i++){//RECORREMOS LA STRUCT
		resultado= strcmp(nombre,lector[i].nombre);
		//printf("%i\n",resultado);
		if (resultado==0) break;

	}
	return resultado;
}


void asignar_id(char nombre[LONGITUD],int *limite){
	int i=*limite;
	i++;
	strcpy(lector[i-1].nombre,nombre);
	lector[i].codigo=i;
	*limite=i;
	//printf("id:%i",i);
}
