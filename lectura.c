#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
    int num=0;
    char nombre[256];
    char apellido[256];
	int i=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");
    while(i!=5){
	
	fscanf(archivo," :%i:%s %s:",&num,&nombre,&apellido);
	printf(" %i %s %s\n",num,nombre,apellido);
	i++;
}
    fclose(archivo);

    }

