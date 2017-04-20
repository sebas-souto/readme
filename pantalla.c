//TITULO MENU & CONFIRMACION SALIDA
#include <stdio.h>
#include <ctype.h>

void pantalla();
int confirmar();
void titulo();
void lados (int);
void base ();

int main(){
	pantalla();	
	return 0;
}

void pantalla (){
	char selec, cadena[256];
	
	titulo(); //IMPRIMIMOS LA CARTULA
	
	do{		
		printf("\n1) Incorporar lector\n2) Agregar referencia\n3) Expresar opinion\n4) Obtener informe\n5) Emitir voto\n6) Calcular nota\n7) Listar referencias\n8) Buscar referencias\n9) Cambiar lector\n0) Salir\n\nSiguiente comando? ");
		fgets(cadena,sizeof(cadena),stdin);		
		if (cadena[1]!='\n')
		cadena[0]='a';
	//	selec=atoi(cadena);	

		switch (cadena[0]){
			case '1':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
			//	incorporar_lector();
				break;
			case '2':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
			//	agregar_referencia();
				break;
			case '3':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
			//	expresar_opinion();
				break;
			case '4':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
			//	obtener_informe();
				break;
			case '5':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
			//	emitir_voto();
				break;
			case '6':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
				break;
			//	calcular_nota();
				break;
			case '7':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
				break;
			// listar_referencias()
			case '8':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
				break;
			// buscar_referencia()
			case '9':
				while (fgetc(stdin) != '\n'); //LIMPIAMOS EL BUFFER
				break;
			// cambiar_lector()
			case '0':
				selec=confirmar();
					if (selec==0){
						return;}
				break;
			default:
				printf("\nHas realizado una seleccion no valida\n");
				break;
		}//switch
	}while (selec!='0');
}

int confirmar(){
	char selec, cadena[256];
	do{
		printf("\nSeguro que deseas salir del programa? (s/n): ");
		fgets(cadena,sizeof(cadena),stdin);
		selec=cadena[0];
		if (cadena[1]!='\n')
		selec='a';
		selec=toupper(selec);
		if (selec=='S'){
			return 0;}
		else if (selec=='N'){
			return 1;}
	} while (selec !='N');
}

void titulo(){
	int k;
	base();
	lados(2);
	printf("#");
	for(k=0;k<34;k++){printf(" ");}
	printf("BIBLIOTECA");
	for(k=0;k<34;k++){printf(" ");}
	printf("#\n");
	lados(2);
	base();}
	
void base (){
	int k;
	for(k=0;k<80;k++){printf("#");}
	printf("\n");}
	
void lados (int num){
	int i,k;
	for(i=0;i<num;i++){
		printf("#");
		for(k=0;k<78;k++){printf(" ");}
		printf("#\n");}}
