//Emitir voto
#include <stdio.h>
void emitir_voto(int);

int main(){
	emitir_voto(15);
	return 0;
}

void emitir_voto(int tamanio){
	int id,voto,ULT_ID=tamanio; //ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
	char cadena[100];			//TAMAÑO MAXIMO DE LA CADENA
	
	
	do{
		printf("\nEscribe la signatura: ");
		fgets(cadena,sizeof(cadena),stdin);
		id=atoi(cadena);
		if (id<1 || id>ULT_ID)
			printf("\nValor seleccionado incorrecto\n");
	} while (id<1 || id>ULT_ID);
	
	//DECIDE A QUE ID SE LE VA A ASIGNAR EL VOTO	SIGNATURA=ID

	do{
		printf("\nEscribe el voto: ");
		fgets(cadena,sizeof(cadena),stdin);
		voto=atoi(cadena);
		if (voto<0 || voto>10)
			printf("\nValor seleccionado incorrecto\n");
	} while (voto<0 || voto>10);
	
	printf("id: %i voto: %i",id,voto);	
	
	refe[id-1].votos+=voto; //SUMAMOS EL VALOR DE VOTO AL VALOR DE VOTOS DE ESA ID
	refe[id-1].votantes++;//E INCREMENTAMOS VOTANTES EN 1
	
	printf("id: %i voto: %i votantes: %i",id,refe[id-1].votos,refe[id-1].votantes);
	
	printf("\nVoto registrado");
	return;
}
