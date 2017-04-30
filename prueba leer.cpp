#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comprobar_lectores();

int main(){
	int comprobar_lectores();
}
int comprobar_lectores(){
	char cadena[256];
	int k;
	FILE *pf;
	pf = fopen("lectores.txt","r");
	fgets(cadena,strlen(cadena),pf);
	printf("%i",strlen(cadena));
	for (k=0;k<strlen(cadena);k++){
			printf("%c",cadena[k]);
		}
	while(fgets(cadena,strlen(cadena),pf)!=NULL){
		for (k=0;k<strlen(cadena);k++){
			printf("%c",cadena[k]);
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	printf("%s",cadena);
	
	
	
	
	return 1;
}
