//Emitir voto
#include <stdio.h>
void emitir_voto();

int main(){
	emitir_voto();
	return 0;
}

void emitir_voto(){
	int id,voto,ULT_ID=15;

	//ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
	//SE USA 15 COMO EJEMPLO
	
	do{
		printf("\nEscribe la signatura: ");
		scanf(" %i",&id);
		if (id<1 || id>ULT_ID)
			printf("\nValor seleccionado incorrecto\n");
	} while (id<1 || id>ULT_ID);
	
	//DECIDE A QUE ID SE LE VA A ASIGNAR EL VOTO	SIGNATURA=ID

	do{
		printf("\nEscribe el voto: ");
		scanf(" %i",&voto);
		if (voto<0 || voto>10)
			printf("\nValor seleccionado incorrecto\n");
	} while (voto<0 || voto>10);
	
//	printf("id: %i voto: %i",id,voto);
	
	//AQUI SUMAMOS EL VALOR DE VOTO AL VALOR DE VOTOS DE ESA ID
	//E INCREMENTAMOS VOTANTES EN 1
	
	printf("\nVoto registrado");
	return;
}
