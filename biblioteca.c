//PROGRAMA BIBLIOTECA
#include "biblioteca.h"
#include "base_de_datos.c"
#include "pantalla.c"

int main(){				//100%LISTA
	if (comprobacion()==0) return 1;	//SI LOS TXT ESTAN MAL FORMADOS CIERRA EL PROGRAMA
	pantalla('#',80,"BIBLIOTECA");
	return 0;
}

int comprobacion(){		//100%LISTA
	FILE *pf;
	pf = fopen("lectores.txt","r");
	if (pf==NULL) pf=fopen("lectores.txt","w");
	else if (comprobar_lectores()==0){
		printf("Linea mal formada en el fichero (lectores.txt)\n");
		return 0;}
		
	FILE *pf2;
	pf2 = fopen("referencias.txt","r");
	if (pf2==NULL) pf2=fopen("referencias.txt","w");
	else if(comprobar_referencias()==0){
		printf("Linea mal formada en el fichero (referencias.txt)\n");
		return 0;}
	fclose(pf);
	fclose(pf2);
	return 1;}

int comprobar_lectores(){
	char cadena[256];
	int codigo=0, correcto=1;
	FILE *lectores;
	lectores = fopen("lectores.txt","r");
	while(fgets(cadena,sizeof(cadena),lectores)!=NULL){
		if (cadena[0]==':'){
			if(comprobar_puntos(cadena,3)==0) correcto=0;
			if(comprobar_num(cadena,MAX_LONG_CODIGO,&codigo,'S')==0) correcto=0;
			if(comprobar_cadena(cadena,MAX_LONG_NOMBRE,2)==0) correcto=0;}
		else correcto=0;}
	fclose(lectores);
	return correcto;}

int comprobar_referencias(){
	char cadena[256];
	int signatura=0, lector=0, correcto=1;
	FILE *referencias;
	referencias = fopen("referencias.txt","r");
	while(fgets(cadena,sizeof(cadena),referencias)!=NULL){
		if(cadena[0]==':'){
			if(comprobar_num(cadena,MAX_LONG_SINGNATURA,&signatura,'S')==0) correcto=0;
			if(comprobar_tipo(cadena,1)==0) correcto=0;
			if(comprobar_cadena(cadena,MAX_LONG_AUTOR,3)==0) correcto=0;
			if(comprobar_cadena(cadena,MAX_LONG_TITULO,4)==0) correcto=0;
			if(comprobar_numero(cadena,MAX_LONG_ANHO,5)==0) correcto=0;
			if(comprobar_numero(cadena,MAX_LONG_VOTANTES,6)==0) correcto=0;
		//	if(comprobar_numero(cadena,MAX_LONG_VOTOS,7)==0) correcto=0;
			if(comprobar_numero(cadena,MAX_LONG_CRITICOS,8)==0) correcto=0;}			
		else if(cadena[0]=='#'){
			if(comprobar_puntos(cadena,2)==0) correcto=0;
			if(comprobar_num(cadena,MAX_LONG_LECTOR,&lector,'N')==0) correcto=0;
			if(comprobar_cadena(cadena,MAX_LONG_OPINION,1)==0) correcto=0;}
		else correcto=0;}
	fclose(referencias);
	return correcto;}

int comprobar_puntos(char *cadena,int n_pts){
	int k, correcto=1, puntos=0;
	if (cadena[strlen(cadena)-2]!=':'&&cadena[strlen(cadena)-1]!=':') correcto=0;
	for(k=0;k<strlen(cadena);k++){
		if(cadena[k]==':')puntos++;}
	if (puntos!=n_pts) correcto=0;
	return correcto;}

int comprobar_num(char *cadena,int tam, int *numero, char ORDEN){
	int k, correcto=1;
	char numeroC[256];
	for(k=1;cadena[k]!=':';k++){
			numeroC[k-1]=cadena[k];
			if(isdigit(cadena[k])==0) correcto=0;}	//COMPRUEBA SI ES UN NUMERO
	numeroC[k-1]='\0';
	if (ORDEN=='S')
		if(atoi(numeroC)<=*numero) correcto=0;		//COMPRUEBA QUE LOS NUMEROS VAN EN ORDEN ASCENDENTE
	*numero=atoi(numeroC);
	if (*numero<1||*numero>tam) correcto=0;		//COMPRUEBA QUE EL NUMERO ESTA ENTRE 0 Y 16 BYTES
//	printf("correcto:%i numero: %i\n",correcto,*numero);
	return correcto;}

int comprobar_tipo(char *cadena,int tam){
	int k, posicion=0, correcto=1, puntos=0;
	char nombre [MAX_LONG_NOMBRE];
	for(k=0;k<MAX_LONG_NOMBRE;k++){
			nombre[k]='\0';}
	for(k=0;puntos<2;k++){
			if(cadena[k]==':') {
				posicion=k+1;
				puntos++;}
	}
	nombre[0]=cadena[posicion];
	nombre[1]='\0';
	
	if (nombre[0]!='A'&&nombre[0]!='L') correcto=0;
	return correcto;}

int comprobar_cadena(char *cadena,int tam,int sitio){
	int k, posicion=0, correcto=1, puntos=0;
	char nombre [256];
	for(k=0;k<256;k++){
			nombre[k]='\0';}
	for(k=0;puntos<sitio;k++){
			if(cadena[k]==':') {
				posicion=k+1;
				puntos++;}
	}
	for(k=posicion;cadena[k]!=':';k++){
		nombre[k-posicion]=cadena[k];}
	if(strlen(nombre)>tam) correcto=0;
//	printf("%s\n",nombre);
	
	return correcto;}

int comprobar_numero(char *cadena,int tam,int sitio){
	int k, numero, posicion=0, correcto=1, puntos=0;
	char nombre [256];
	for(k=0;k<256;k++){
			nombre[k]='\0';}
	for(k=0;puntos<sitio;k++){
			if(cadena[k]==':') {
				posicion=k+1;
				puntos++;}
	}
	for(k=posicion;cadena[k]!=':';k++){
		nombre[k-posicion]=cadena[k];
		if(isdigit(nombre[k-posicion])==0) correcto=0;}
	numero=atoi(nombre);
	if(numero>tam) correcto=0;
//	printf("%s %i correcto: %i\n",nombre,numero,correcto);
	
	return correcto;}

