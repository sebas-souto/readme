//Calcular nota
#include <stdio.h>
void calcular_nota(int);

int main(){
	calcular_nota(15);
	return 0;
}

void calcular_nota(int tamanio){
	int id,votantes,ULT_ID=tamanio;	//ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
	float votos;
	char cadena[100];
	
	do{
		printf("\nEscribe la signatura: ");
		fgets(cadena,sizeof(cadena),stdin);
		id=atoi(cadena);
		if (id<1 || id>ULT_ID)
			printf("\nValor seleccionado incorrecto\n");
	} while (id<1 || id>ULT_ID);
	
	//DECIDE DE QUE ID SE CALCULA LA NOTA  		SIGNATURA=ID	

	votos=refe[id-1].votos;
	votantes=refe[id-1].votantes;
		
	printf("\nNumero de votos:%i\n",votantes);	
	printf("Nota media:%.2f",votos/votantes);
	return;
}
