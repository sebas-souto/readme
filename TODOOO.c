//todo
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LONG_NOMBRE 50
#define MAX_LONG_AUTOR 50
#define MAX_LONG_TITULO 80
#define MAX_LONG_OPINION 80
#define MAXIMO 90
#define LONGITUD 50
int comprobacion();
int comprobar_lectores();
int comprobar_referencias();



void pantalla();
int confirmar();
void caratula(char,int,char *texto);
void lados(char,int,int);
void base(char,int);
int tituloo(char,int,char *texto);


int base_de_datos(int eleccion);
//BASICAS--------------------------------------------
int incorporar_lector(int *limite);
void agregar_referencia(int *id);
void obtener_informe(int *tamanio);
void expresar_opinion(int *tamanio,int *tam_lector);
void emitir_voto(int *tamanio);
void calcular_nota(int *tamanio);
//AVANZADAS------------------------------------------
//LECTOR---------------------------------------------
int comprobar_lector(char nombre[50], int *tamanio);
void asignar_id(char nombre[LONGITUD],int *limite);
//REFERENCIA-----------------------------------------
void confimar (int limite ,char *pantalla,char *cadena2);
void dame_autor(int *id);
void dame_titulo(int *id);
void dame_anio(int *id);
void dame_tipo(int *id);
//ACTUALIZAR TXTs------------------------------------
void actualizar_lector (int *limite);
void actualizar_refe (int *limite);
//LEER LECTOR-----------------------------------------
int leer_lector();
int*  obtener_puntos(char *cadena,int *pts);
void obtener_codigo(char *cadena, int *pts,int *id);
void obtener_nombre(char *cadena, int *pts,int *id);
//LEER REFERENCIA------------------------------------
int leer_referencia();
void datos(char *cadena, int *id);
void opinions(char *cadena, int *id2,int *id);
int* puntos(char *cadena,int *pts);
void signa(char *cadena, int *pts,int *id);
void tipo(char *cadena, int *pts, int *id);
void autor(char *cadena, int *pts, int *id);
void titulo(char *cadena, int *pts, int *id);
void anho(char *cadena, int *pts,int *id);
void votantes(char *cadena, int *pts,int *id);
void votos(char *cadena, int *pts,int *id);
void criticos(char *cadena, int *pts,int *id);
void lect(char *cadena, int *pts, int *id2, int *id);
void opinion(char *cadena, int *pts, int *id2, int *id);
//IMPRIMIR-------------------------------------------
void imprimir(int linea);


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
	else if (comprobar_lectores()==0){		//SI EXISTE Y NO TIENE EL FORMATO CORRECTO SE CIERRA
		printf("Linea mal formada en el fichero(lectores.txt)\n");
		return 0;}
		
	FILE *pf2;
	pf2 = fopen("referencias.txt","r");
	if (pf2==NULL){ 	//SI NO EXISTE EL TXT LO CREA
		printf("referencias.txt no existe y se ha creado\n");
		pf = fopen("referencias.txt","w");}
	else if(comprobar_referencias()==0){	//SI EXISTE Y NO TIENE EL FORMATO CORRECTO SE CIERRA
		printf("Linea mal formada en el fichero(referencias.txt)");
		return 0;}
	fclose(pf);
	fclose(pf2);
	return 1;
}

int comprobar_lectores(){
	char cadena[256], numeroC[10];
	char nombre[MAX_LONG_NOMBRE];
	int numero;
	int k, correcto=1, puntos=0, posicion=0;
	FILE *lectores;
	lectores = fopen("lectores.txt","r");
	while(fgets(cadena,sizeof(cadena),lectores)!=NULL){
		if (cadena[0]!=':') correcto=0;
		if (cadena[strlen(cadena)-2]!=':') correcto=0;
		for(k=0;k<strlen(cadena);k++){
			if(cadena[k]==':')puntos++;}
		if (puntos!=3) correcto=0;
		puntos=0;
		//NUMERO
		for(k=1;(isdigit(cadena[k]))&&cadena[k]!=':';k++)
			numeroC[k-1]=cadena[k];
		if(k==1) correcto=0;
		numeroC[k-1]='\n';
		numero=atoi(numeroC);
		if (numero<1) correcto=0;
		//NOMBRE
		for(k=0;k<strlen(cadena)-3;k++){
			if(cadena[k]==':') posicion=k+1;}
		for(k=0;k<strlen(cadena)-3;k++){
			nombre[k]=cadena[k+posicion];}
		nombre[strlen(nombre)-2]='\0';
		if(strlen(nombre)>MAX_LONG_NOMBRE) correcto=0;
//		printf("numero: %i nombre: %s\n",numero,nombre);
		posicion=0;
		for(k=0;k<MAX_LONG_NOMBRE;k++){
			nombre[k]='\0';
		}
	}
	fclose(lectores);
	if (correcto==1) return 1;
	return 0;
}

int comprobar_referencias(){
	char cadena[256], numeroC[10];
	char tipo, autor[MAX_LONG_AUTOR], titulo[MAX_LONG_TITULO], opinion[MAX_LONG_OPINION];
	int signatura, anho, votantes, votos, criticos, lector;	
	int k, correcto=1, puntos=0, posicion=0;
	FILE *referencias;
	referencias = fopen("referencias.txt","r");
	while(fgets(cadena,sizeof(cadena),referencias)!=NULL){
	//	printf("%s\n",cadena);
	}
	fclose(referencias);
	if (correcto==1) return 1;
	return 0;
}
//TITULO MENU & CONFIRMACION SALIDA
void pantalla (){
	caratula('#',80,"BIBLIOTECA"); //IMPRIMIMOS LA CARTULA
	char selec, cadena[256];	
	do{		
		printf("\n1) Incorporar lector\n2) Agregar referencia\n3) Expresar opinion\n4) Obtener informe\n5) Emitir voto\n6) Calcular nota\n7) Listar referencias\n8) Buscar referencias\n9) Cambiar lector\n0) Salir\n\nSiguiente comando? ");
		fgets(cadena,sizeof(cadena),stdin);		
		selec=cadena[0];
		if (cadena[1]!='\n') selec='X';	//SI NO SE INTRODUCE UN SOLO CARACTER INVALIDA EL 1º

		switch (selec){
			case '1':
				base_de_datos(1);
				break;
			case '2':
				base_de_datos(2);
				break;
			case '3':
				base_de_datos(3);
				break;
			case '4':
				base_de_datos(4);
				break;
			case '5':
				base_de_datos(5);
				break;
			case '6':
				base_de_datos(6);
				break;
			case '7':
				base_de_datos(7);
				break;
			case '8':
				base_de_datos(8);
				break;
			case '9':
				base_de_datos(9);
				break;
			case '0':
				selec=confirmar();
					if (selec==0) return;
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
		if (cadena[1]!='\n') selec='X'; 
		selec=toupper(selec);
		if (selec=='S'){
			return 0;}
		else if (selec=='N'){
			return 1;}
	} while (selec !='N');
}

void caratula(char simbolo, int ancho, char *texto){
	if (MAXIMO<ancho) ancho=MAXIMO;
	base(simbolo,ancho);
	lados(simbolo,ancho,2);
	tituloo(simbolo,ancho,texto);
	lados(simbolo,ancho,2);
	base(simbolo,ancho);}
	
int tituloo(char simbolo, int ancho, char *texto){
	if (ancho<strlen(texto)+2) return 1;   //SI EL ANCHO ES INSUFICIENTE RETORNA 1
	int k, lado, resto;
	lado=ancho-2-strlen(texto);
	resto=strlen(texto)%2;
	
	printf("%c",simbolo);
	for(k=0;k<resto+lado/2;k++){
		printf(" ");}
 	printf("%s",texto);
	for(k=0;k<lado/2;k++){
		printf(" ");}
	printf("%c\n",simbolo);
	return 0;}
	
void base(char simbolo, int ancho){
	int k;
	for(k=0;k<ancho;k++){
		printf("%c",simbolo);}
	printf("\n");		
	return;}
	
void lados(char simbolo, int ancho, int lineas){
	int k,i;
	for (i=0;i<lineas;i++){
			printf("%c",simbolo);
		for(k=0;k<ancho-2;k++){
			printf(" ");}
		printf("%c\n",simbolo);	}
	return;}
	

//STRUCTS-------------------------------------------
struct lectores{
    int codigo;
    char nombre[256];
};
struct informacion{
    int lector;
    char opinion[80];
};
struct referencia{
    int signatura;
    char tipo;
    char autor[51];
    char titulo[81];
    int anio;
    int votantes;
    int votos;
    int criticos;
	struct informacion info[100];
};
struct lectores lector[100];
struct referencia refe[100];

//programa
int base_de_datos(int eleccion){
    int tam_lec, tam_ref;
    tam_lec=leer_lector();
	tam_ref=leer_referencia();
	switch(eleccion){
		case 1:
			incorporar_lector(&tam_lec);
			break;
		case 2:
			agregar_referencia(&tam_ref);
			break;
		case 3:
			expresar_opinion(&tam_ref,&tam_lec);
			break;
		case 4:
			obtener_informe(&tam_ref);
			break;
		case 5:
			emitir_voto(&tam_ref);
			break;
		case 6:
			calcular_nota(&tam_ref);
			break;
		case 7:
			//listar_referencia();
			break;
		case 8:
			//buscar_referencia();
			break;
		case 9:
			//cambiar_lector();
			break;
	}
   /* int k;

    for(k=0;k<tam_ref;k++){
        printf("%i:%s:%i:%i:%c:%s:%i:%i\n",refe[k].anio,refe[k].autor,refe[k].criticos,refe[k].signatura,refe[k].tipo,refe[k].titulo,refe[k].votantes,refe[k].votos);}
    for(k=0;k<tam_lec;k++){
    	printf("%s\n",lector[k].nombre);}*/
        
    actualizar_lector(&tam_lec);
  //  actualizar_refe(&tam_ref);

    return 0;
}

//BASICAS--------------------------------------------
int incorporar_lector (int *limite){
    int i,a,correcto=0,repetido,tamanio=*limite;
    char nombre[LONGITUD];
    while (correcto==0){
        printf("Escribe el nombre del lector: ");
        fgets(nombre,sizeof(nombre),stdin);
        correcto=1;
        i=0;

        if (nombre[0]=='\n'){    				          //CADENA VACIA
            correcto=0;
            printf("Cadena vacia\n");}
        else if (nombre[strlen(nombre)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
            correcto=0;
            printf("Longitud excesiva\n");
            while (fgetc(stdin) != '\n');}
        else {                                            //CARACTER INVALIDO
            while (i<strlen(nombre)){
                if (nombre[i]==':'){
                    correcto=0;
                    printf("Caracter invalido\n");}
                i++;}
		}
	}
        //printf("\nLector %s: asignado %i \n",lector[tamanio].nombre,lector[tamanio].codigo);
    for(a=0;a<strlen(nombre);a++) {
        if(nombre[a]== '\n'){
            nombre[a] = '\0';
            break;}
			}
    //printf("---%s-----8888\n",nombre);
    repetido=comprobar_lector(nombre,&tamanio);
    if(repetido==0) {
		printf("Lector repetido.\n");
		return 0;}
    else {
        asignar_id(nombre,&tamanio);
        *limite=tamanio;
        printf("Lector %s: asignado %i\n",lector[tamanio-1].nombre,lector[tamanio-1].codigo);
		return 1;}
}

void agregar_referencia(int *id){
    int tam=*id, a=tam;
    tam++;
    refe[tam-1].signatura=tam;
  //  printf("Tamanio en agregar referencia: %i\n",tam);
    dame_autor(&a);
    dame_titulo(&a);
    dame_anio(&a);
    dame_tipo(&a);
    refe[a].criticos=0;
    refe[a].votantes=0;
    refe[a].votos=0;
    printf("Referencia %c:%s:%s:%i: asignada %i\n",refe[a].tipo,refe[a].autor,refe[a].titulo,refe[a].anio,refe[a].signatura);
    //printf("%s %s %i %c\n",refe[tam].autor,refe[tam].titulo,refe[tam].anio,refe[tam].tipo);
    *id=tam;
}

void expresar_opinion(int *tamanio,int *tam_lector){
    int id,x,z,ULT_ID=*tamanio,codigo;
    int ULT_COD=*tam_lector;				//ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
    char cadena[256], comentario[256];    

    do{
        printf("\nEscribe la signatura: ");
        fgets(cadena,sizeof(cadena),stdin);
        id=atoi(cadena);
        if (id<1 || id>ULT_ID)
            printf("\nValor seleccionado incorrecto\n");
    } while (id<1 || id>ULT_ID);

    do{
        printf("\nEscribe el codigo: ");
        fgets(cadena,sizeof(cadena),stdin);
        codigo=atoi(cadena);
        if (codigo<0 || codigo>ULT_COD)
            printf("\nValor seleccionado incorrecto\n");
    } while (codigo<0 || codigo>ULT_COD);

   // printf("Escribe el comentario:");
   // fgets(comentario,sizeof(comentario),stdin);
    confimar (80,"Escribe el comentario:",comentario);
    comentario[strlen(comentario)-1]='\0';
    refe[id-1].criticos=refe[id-1].criticos+1;
    x=refe[id-1].criticos;
    refe[id-1].info[x].lector=codigo;
    strcpy(refe[id-1].info[x].opinion,comentario);

    return;
}

void obtener_informe(int *tamanio){
    int id,x,z,ULT_ID=*tamanio;				//ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
    char cadena[256];

    do{
        printf("\nEscribe la signatura: ");
        fgets(cadena,sizeof(cadena),stdin);
        id=atoi(cadena);
        if (id<1 || id>ULT_ID)
            printf("\nValor seleccionado incorrecto\n");
    } while (id<1 || id>ULT_ID);

    printf("Numero de comentarios:%i\n",refe[id-1].criticos);
    int p=0;
    for (x = refe[id-1].criticos; x > 0; x--){
        z=refe[id-1].info[x].lector;
        printf("z=%i");
        //printf("%s:%s \n", lector[x].nombre,refe[id-1].info[x].opinion);
        p++;
    }
    if(refe[x].criticos!=0) {
        for (x = refe[x].criticos; x > 0; x--) {
            // printf("z:%i--x=%i--\n",z,x);
            printf("%s:%s \n", lector[refe[id - 1].info[x].lector - 1].nombre, refe[id - 1].info[x].opinion);
            //printf("z:%i\n",refe[id-1].info[x].lector);
        }
    }

    return;
}

void emitir_voto(int *tamanio){
    int id,voto,ULT_ID=*tamanio; //ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
    char cadena[100];			//TAMAÑO MAXIMO DE LA CADENA

    do{
        printf("\nEscribe la signatura: ");
        fgets(cadena,sizeof(cadena),stdin);
        id=atoi(cadena);
        if (id<1 || id>ULT_ID)
            printf("\nValor seleccionado incorrecto\n");
    } while (id<1 || id>ULT_ID);

    do{
        printf("\nEscribe el voto: ");
        fgets(cadena,sizeof(cadena),stdin);
        voto=atoi(cadena);
        if (voto<0 || voto>10)
            printf("\nValor seleccionado incorrecto\n");
    } while (voto<0 || voto>10);

    printf("id: %i voto: %i",id,voto);

    refe[id-1].votos+=voto; 	//SUMAMOS EL VALOR DE VOTO AL VALOR DE VOTOS DE ESA ID
    refe[id-1].votantes++;		//E INCREMENTAMOS VOTANTES EN 1

    printf("id: %i voto: %i votantes: %i",id,refe[id-1].votos,refe[id-1].votantes);
    printf("\nVoto registrado");
    return;
}

void calcular_nota(int *tamanio){
    int id,votantes,ULT_ID=*tamanio;	//ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
    float votos;
    char cadena[100];

    do{
        printf("\nEscribe la signatura: ");
        fgets(cadena,sizeof(cadena),stdin);
        id=atoi(cadena);
        if (id<1 || id>ULT_ID)
            printf("\nValor seleccionado incorrecto\n");
    } while (id<1 || id>ULT_ID);

    votos=refe[id-1].votos;
    votantes=refe[id-1].votantes;

    printf("\nNumero de votos:%i\n",votantes);
    printf("Nota media:%.2f",votos/votantes);
    return;
}
//AVANZADAS------------------------------------------

//LECTOR---------------------------------------------
int comprobar_lector(char nombre[50], int *tamanio){
    int limite=*tamanio;
    int resultado,i;
    //printf("limite comprobar lector: %i\n",limite);
    for(i=0;i<limite;i++){//RECORREMOS LA STRUCT
        resultado= strcmp(nombre,lector[i].nombre);
        //printf("%i\n",resultado);
        if (resultado==0) break;
    }
    return resultado;
}

void asignar_id(char nombre[LONGITUD],int *limite){
    int i=*limite;
    i++;
    strcpy(lector[i-1].nombre,nombre);
    lector[i-1].codigo=i;
    *limite=i;
    //printf("id:%i",i);
    //lector[i-1].nombre[strlen(lector[i-1].nombre)-3]='\0';
}
//REFERENCIA-----------------------------------------
void confimar (int limite,char *pantalla, char *cadena2){
    int i=0,correcto,resultado;
    char cadena[limite];
    do{
        printf("%s",pantalla);
        fgets(cadena,sizeof(cadena),stdin);
        correcto=1;

        if (cadena[0]=='\n'){    				          //CADENA VACIA
            correcto=0;
            imprimir(2);
        }
        else if (cadena[strlen(cadena)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
            correcto=0;
            imprimir(3);
            while (fgetc(stdin) != '\n');
        }
        else {                                            //CARACTER INVALIDO
            while (i<strlen(cadena)){
                if (cadena[i]==':'){
                    correcto=0;
                    imprimir(1);
                }
                i++;
            }
        }
    }while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA
    strcpy(cadena2,cadena);
}

void dame_autor(int *id){
    int id2=*id;
    char autor[50];
    char pantalla[]="Escribe el autor de la referencia: ";
    confimar(50,pantalla,autor);
    autor[strlen(autor)-1]='\0';
    strcpy(refe[id2].autor,autor);
    //printf("%s-----%i",refe[id2].autor,id2);
}

void dame_titulo(int *id){
    int id2=*id;
    char titulo[80];
    char pantalla[]="Escribe el titulo: ";
    confimar(80,pantalla,titulo);
    titulo[strlen(titulo)-1]='\0';
    strcpy(refe[id2].titulo,titulo);
}

void dame_anio(int *id){
    int id2=*id;
    char cadena[5];
    int year,correcto=0;
    do{
        printf("Escribe el anho: ");
        fgets(cadena,sizeof(cadena),stdin);
        year=atoi(cadena);
        if((1450<year)&&(year<2017)){
            correcto=1;
        }
        else{
            imprimir(5);
            correcto=0;
        }
    }while(correcto==0);
    refe[id2].anio=year;
   // printf("anio: %i\n",refe[id2].anio);

}

void dame_tipo(int *id){
    int id2=*id;
    int i=0,correcto,resultado;
    char cadena[20];
    char letra;
    do{
        printf("Escribe el tipo: ");
        fgets(cadena,100,stdin);

        //	printf("cadena:-%s-longuitud:%i",cadena,strlen(cadena));

        if (cadena[0]=='\n'){    				          //CADENA VACIA
            correcto=0;
            imprimir(2);
        }

        else if (strlen(cadena)>2){       //LONGITUD CADENA EXCESIVA
            correcto=0;
            imprimir(3);

        }
        else if(cadena[0]=='L'||cadena[0]=='l'||cadena[0]=='a'||cadena[0]=='A'){
            correcto=1;
            //imprimir(1);
        }
        else {
            correcto=0;
            imprimir(1);
        }
    }while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA

    refe[id2].tipo=cadena[0];
}
//ACTUALIZAR TXTs------------------------------------
void actualizar_lector (int *limite){
    int i;
    int tamanio=*limite;
    FILE *archivo;
    //printf("LLega aqui!!!!\n");
    archivo = fopen("lectores.txt", "w");
    for (i = 0; i < tamanio; i++) {
        fprintf(archivo,":%i:%s:\n", lector[i].codigo,lector[i].nombre);
        //printf(":%i:%s:\n", lector[i].codigo,lector[i].nombre);
    }
    fclose(archivo);
}

void actualizar_refe (int *limite) {
    int x, z;
    int tamanio = *limite;
    FILE *archivo;
    //printf("LLega aqui!!!!\n");
    archivo = fopen("referencias.txt", "w");
    for (x = 0; x < tamanio; x++) {
        fprintf(archivo,":%i:%c:%s:%s:%i:%i:%i:%i:\n", refe[x].signatura, refe[x].tipo, refe[x].autor, refe[x].titulo,
               refe[x].anio, refe[x].votantes, refe[x].votos, refe[x].criticos);
        //printf("criticos:%i\n",refe[x].criticos);
         for (z = refe[x].criticos; z > 0; z--) {
            // printf("z:%i--x=%i--\n",z,x);
            fprintf(archivo,"#%i:%s:\n", refe[x].info[z].lector, refe[x].info[z].opinion);
        }
    }
    fclose(archivo);
}

//LEER LECTOR-----------------------------------------
int leer_lector(){
    char cadena[256];
    int pts[256];
    int id=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){
    	// printf("%i :\n",id);
        obtener_puntos(cadena,pts);
        obtener_codigo(cadena,pts,&id);
        obtener_nombre(cadena,pts,&id);
        id++;}
    fclose(archivo);
    return id;
}

int* obtener_puntos(char *cadena,int *pts){
    int i=0, j=0;
    //int pts[10];
    for(i=0;i<strlen(cadena);i++){
        if(cadena[i]==':'){
            j++;
            pts[j]=i;
            //  printf("%i",i);
        }
    }
    // printf("\n");
    return pts;
}

void obtener_codigo(char *cadena, int *pts,int *id){
    int num, x, p=0, y=*id;
    char variable[10],cadena2[256];
    strcpy(cadena2,cadena);
    cadena2[pts[2]]='\0';
    //   printf("lector: %s-%i \n",cadena2,pts[2]);
    for(x=pts[1];x<pts[2];x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            //   printf("lector: %s\n",variable);
            p++;}
    }
    //printf("lector: %s-",variable);
    num=atoi(variable);
    lector[y].codigo=num;
}

void obtener_nombre(char *cadena, int *pts,int *id){
    int num=0, x=0, y=*id;
    char cadena2[81];
    strcpy(cadena2, cadena);
    cadena2[pts[3]] = '\0';
//	printf("%s\n",cadena2);
    for (x = pts[2]; x < strlen(cadena2); x++) {
        if (cadena2[x] != ':') {
            cadena2[num] = cadena2[x];
            //	printf("%c",cadena2[x]);
            num++;}
    }
    //printf("\n");
    cadena2[num] = '\0';
    // printf("----%s \n",cadena2);
    strcpy(lector[y].nombre, cadena2);
}

//LEER REFERENCIA------------------------------------
int leer_referencia(){
    char cadena[256];
    int id=0,id2=0;
    FILE *archivo;
    archivo = fopen("referencias.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){
        if(cadena[0]==':'){
            datos(cadena, &id);
            id++;
            id2=refe[id-1].criticos;}

        else if(cadena[0]=='#'){
            //printf("id2: %i \n",id2);
            opinions(cadena,&id2,&id);
            id2--;}
        else{
            printf("Formato del fichero incorrecto\n");}
    }
    fclose(archivo);
    return id;}

void datos(char *cadena, int *id){
    int pts[256], r=*id;
    puntos(cadena,pts);
    signa(cadena,pts,&r);
    tipo(cadena,pts,&r);
    autor(cadena,pts,&r);
    titulo(cadena,pts,&r);
    anho(cadena,pts,&r);
    votantes(cadena,pts,&r);
    votos(cadena,pts,&r);
    criticos(cadena,pts,&r);
}

void opinions(char *cadena, int *id2, int *id){
    int pts[10], r=*id, m=*id2;
    puntos(cadena,pts);
    lect(cadena,pts,&m,&r);
    opinion(cadena,pts,&m,&r);
}

int* puntos(char *cadena,int *pts){
    int i=0, j=0;
    for(i=0;i<strlen(cadena);i++){
        if(cadena[i]==':'){
            j++;
            pts[j]=i;}
    }
    return pts;
}

void signa(char *cadena, int *pts, int *id){
    int num,x;
    int y=*id;
    char variable[10],cadena2[80];
    strcpy(cadena2,cadena);
    cadena2[pts[2]]='\0';

    for(x=0;x<strlen(cadena2);x++){
        cadena2[x]=cadena2[x+1];
    }
    num=atoi(cadena2);
    refe[y].signatura=num;
}

void tipo(char *cadena, int *pts, int *id){
    int num=0,x;
    int y=*id;
    char variable[10],cadena2[80];
    strcpy(cadena2,cadena);
    cadena2[pts[3]]='\0';
    // printf("%s--%i--%i\n",cadena2,pts[2],pts[3]);

    for(x=pts[2];x<pts[3];x++){
        if(cadena[x]!=':') {
            variable[num] = cadena2[x];
            num++;
        }
    }
    refe[y].tipo=variable[0];

}

void autor(char *cadena, int *pts, int *id){
    int num=0,x;
    int y=*id;
    char cadena2[80];
    strcpy(cadena2,cadena);
    cadena2[pts[4]]='\0';

    for(x=pts[3];x<strlen(cadena2);x++){
        if(cadena[x]!=':') {
            cadena2[num] = cadena2[x];

            num++;
        }
    }
    cadena2[num]='\0';
    //printf("%s\n",cadena2);
    strcpy(refe[y].autor,cadena2);
}

void titulo(char *cadena, int *pts, int *id) {
    int num = 0, x;
    int y = *id;
    char cadena2[80];
    strcpy(cadena2, cadena);
    cadena2[pts[5]] = '\0';

    for (x = pts[4]; x < strlen(cadena2); x++) {
        if (cadena2[x] != ':') {
            cadena2[num] = cadena2[x];

            num++;
        }
    }
    cadena2[num]='\0';
    // printf("%s\n",cadena2);
    strcpy(refe[y].titulo, cadena2);
    // printf("%s\n",refe[y].titulo);
}

void anho(char *cadena, int *pts, int *id){
    int num,x,p=0;
    int y=*id;
    char variable[10],cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[6]]='\0';
    for(x=pts[5];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            p++;
        }
    }
    num=atoi(variable);
    // printf("%s\n",variable);
    refe[y].anio=num;
}

void votantes(char *cadena, int *pts, int *id){
    int num,x,p=0;
    int y=*id;
    char variable[10],cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[7]]='\0';
    //printf("%s--\n",cadena2);
    for(x=pts[6];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            cadena2[p] = cadena2[x];
            // printf("%c\n",cadena2[x]);
            p++;
        }
    }
    cadena2[p]='\0';
    //  printf("%i\n",p);
    num=atoi(cadena2);
    //printf("%s--\n",variable);
    refe[y].votantes=num;
    //  printf("%i\n",refe[y].votantes);
}

void votos(char *cadena, int *pts, int *id){
    int num=0,x,p=0;
    int y=*id;
    char variable[10],cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[8]]='\0';
    for(x=pts[7];x<pts[8];x++){
        if(cadena2[x]!=':') {
            cadena2[p] = cadena2[x];
            //  num=num+atoi(cadena2[x]);
            // printf("%c",cadena2[x]);
            p++;
        }
    }

    cadena2[p]='\0';
    //printf("--%s--",cadena2);
    num=atoi(cadena2);
    //printf("#%i#\n",num);
    refe[y].votos=num;
}

void criticos(char *cadena, int *pts, int *id){
    int num,x,p=0;
    int y=*id;
    char variable[10],cadena2[120];

    strcpy(cadena2,cadena);
    cadena2[pts[9]]='\0';
    for(x=pts[8];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            cadena2[p] = cadena2[x];
            p++;
        }
    }
    cadena2[p]='\0';
    // printf("--%s--",cadena2);
    num=atoi(cadena2);
    // printf("#%i#\n",num);
    refe[y].criticos=num;
    //printf("criticos:--%i---y=%i\n",refe[y].criticos,y);
}

void lect(char *cadena, int *pts,int *id2,int *id){
    int num,x,p=0,m=0;
    int y=*id;
    int r=*id2;
    char variable[10],cadena2[256];
    strcpy(cadena2,cadena);
    cadena2[pts[1]]='\0';
    //  printf("lector1: %s %i %i\n",cadena2,pts[1],strlen(cadena2));

    for(x=0;x<strlen(cadena2);x++){
        if(cadena2[x]=='#') {
            p=x;

        }
    }

    for(x=p;x<strlen(cadena2);x++){
        if(cadena2[x]!='#') {
            variable[p] = cadena2[x];
            // printf("lector: %s\n",variable);
            p++;
        }
    }
    //printf("lector: %s\n",variable);
    num=atoi(variable);
    refe[y-1].info[r].lector=num;
    //printf("lector: %i -%i---%i\n",refe[y-1].info[r].lector,y,r);
}

void opinion(char *cadena, int *pts,int *id2,int *id){
    int num = 0, x,m=0;
    int y = *id;
    int r=*id2;
    char variable[80],cadena2[81];
    strcpy(cadena2, cadena);
    cadena2[pts[2]] = '\0';



    for (x = pts[1]; x < strlen(cadena2); x++) {
        if (cadena[x] != ':') {
            variable[num] = cadena2[x];

            num++;
        }
    }
    variable[num]='\0';
    // printf("%s\n",variable);
    strcpy(refe[y-1].info[r].opinion, variable);
    // printf("%s --Usuario:%i ---nº: %i\n",refe[y-1].info[r].opinion,y-1,r);
    //  m++;
}

//IMPRIMIR--------------------------------------------
void imprimir(int linea){
    char *errores[]={
            /*0*/   "\nError de formato en un fichero: ?Linea mal formada en el fichero (NOMBRE_FICHERO)\n\n",
            /*1*/   "\nCaracter invalido\n\n",
            /*2*/   "\nCadena vacia\n\n",
            /*3*/   "\nLongitud de cadena excesivan\n\n",
            /*4*/   "\nLector repetido\n\n",
            /*5*/ "\nValor seleccionado incorrecto\n\n",
            /*6*/ "\nOperacion imposible en este momento\n\n",
    };

    printf("%s",errores[linea]);
}

