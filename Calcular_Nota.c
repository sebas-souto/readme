//Calcular nota
#include <stdio.h>
void calcular_nota();

int main(){
	calcular_nota();
	return 0;
}

void calcular_nota(){
	int id,votantes,ULT_ID=15;
	float votos;
	
	//ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
	//SE USA 15 COMO EJEMPLO
	
	do{
		printf("\nEscribe la signatura: ");
		scanf(" %i",&id);
		if (id<1 || id>ULT_ID)
			printf("\nValor seleccionado incorrecto\n");
	} while (id<1 || id>ULT_ID);
	
	//DECIDE DE QUE ID SE CALCULA LA NOTA  		SIGNATURA=ID	
//	votos=27;votantes=5;
	//VOTANTES DEBE SER = AL VOTANTES DE ESA ID
	//VOTOS DEBE SER = AL VOTOS DE ESA ID
		
	printf("\nNumero de votos:%i\n",votantes);	
	printf("Nota media:%.2f",votos/votantes);
	return;
}
