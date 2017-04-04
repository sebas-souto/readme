#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo;
	int caracter;
	char array[256];
	int num=0;
	
	archivo = fopen("lectores.txt","r");
	
	if (archivo == NULL) {
            printf("\nError de apertura del archivo. \n\n");
        }
        else {
            printf("\nEl contenido del archivo de prueba es \n\n");
            
             while((caracter = fgetc(archivo)) != EOF)  {
            
           /* while((caracter = fgetc(archivo)) != EOF)  {
		printf("%c",caracter);
	    }*/
	    fscanf('archivo',":%i:%s:",&num,&array);
	    printf("%i %s\n",num,array);
			}
	
        }
        fclose(archivo);
	return 0;
}
