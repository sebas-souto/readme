//CONFIRMAR
#include <stdio.h>
#include "pantalla.c"
//#include "base_de_datos.c"

int comprobacion();

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
	else if (1==0){		//SI EXISTE Y NO TIENE EL FORMATO CORRECTO SE CIERRA
		printf("Linea mal formada en el fichero(lectores.txt)");
		return 0;}
		
	FILE *pf2;
	pf2 = fopen("referencias.txt","r");
	if (pf2==NULL){ 	//SI NO EXISTE EL TXT LO CREA
		printf("referencias.txt no existe y se ha creado\n");
		pf = fopen("referencias.txt","w");}
	else if(1==0){		//SI EXISTE Y NO TIENE EL FORMATO CORRECTO SE CIERRA
		printf("Linea mal formada en el fichero(referencias.txt)");
		return 0;}
	return 1;
}
