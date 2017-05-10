//BASE DE DATOS
#include "base_de_datos.h"
#include "pantalla.h"
void programa(int eleccion){
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
			expresar_opinion(tam_ref,tam_lec);
			break;
		case 4:
			obtener_informe(tam_ref);
			break;
		case 5:
			emitir_voto(tam_ref);
			break;
		case 6:
			calcular_nota(tam_ref);
			break;
		case 7:
			listar_referencia(tam_ref);
			break;
		case 8:
			buscar_referencia(tam_ref);
			break;
		case 9:
			cambiar_lector(tam_lec);
			break;}
// 	int k,z;
//	for(k=0;k<tam_ref;k++)printf("%i:%c:%s:%s:%i:%i:%i:%i\n",refe[k].signatura,refe[k].tipo,refe[k].autor,refe[k].titulo,refe[k].anio,refe[k].votantes,refe[k].votos,refe[k].criticos);
/*	for(k=0;k<tam_ref;k++){
		if(refe[k].criticos!=0){
			for(z=1;z<=refe[k].criticos;z++)printf("%i:%s\n",refe[k].info[k].lector,refe[k].info[k].opinion);}
			}*/
//	for(k=0;k<tam_lec;k++)printf("%i:%s\n",lector[k].codigo,lector[k].nombre);
    actualizar_lector(tam_lec);
	actualizar_refe(tam_ref);
    return;}

/*****************************************************************************************************************************************************************************
******************************************************************************BASICAS*****************************************************************************************
*****************************************************************************************************************************************************************************/
void incorporar_lector (int *ult_lect){//LISTA
    char nombre[256];
    int i;
    dame_cadena(MAX_LONG_NOMBRE,"\nEscribe el nombre del lector: ",nombre);		//PEDIMOS UN NOMBRE VALIDO
    
    for(i=0;i<*ult_lect;i++){		//RECORREMOS TODOS LOS NOMBRES PARA VER SI YA EXISTE
        if ((strcmp(nombre,lector[i].nombre))==0){
		imprimir(4);
		return;}		//SI YA EXISTE SALIMOS
	}		//SI NO EXISTE:
    *ult_lect+=1;		//INCREMENTAMOS EL NUMERO DE LECTORES EN 1
    strcpy(lector[*ult_lect-1].nombre,nombre);		//AÑADIMOS EL NUEVO LECTOR
    lector[*ult_lect-1].codigo=*ult_lect;		//LE ASIGNAMOS EL ULTIMO CODIGO
    printf("\nLector %s: asignado %i\n\n",lector[*ult_lect-1].nombre,lector[*ult_lect-1].codigo);
	return;}

void agregar_referencia(int *ult_sign){
	char texto[256];    
    refe[*ult_sign].signatura=*ult_sign+1;
    dame_cadena(MAX_LONG_AUTOR,"\nEscribe el autor de la referencia: ",texto);
	strcpy(refe[*ult_sign].autor,texto);
	dame_cadena(MAX_LONG_TITULO,"\nEscribe el titulo: ",texto);
    strcpy(refe[*ult_sign].titulo,texto);
    refe[*ult_sign].anio=dame_numero(1451,2016,"\nEscribe el anho: ");
    refe[*ult_sign].tipo=dame_tipo();
    refe[*ult_sign].criticos=0;
    refe[*ult_sign].votantes=0;
    refe[*ult_sign].votos=0;
    printf("\nReferencia %c:%s:%s:%i: asignada %i\n",refe[*ult_sign].tipo,refe[*ult_sign].autor,refe[*ult_sign].titulo,refe[*ult_sign].anio,refe[*ult_sign].signatura);
    *ult_sign+=1;
    return;}

void expresar_opinion(int ult_sign,int ult_lect){//LISTA
    int codigo, id;
	char opinion[MAX_LONG_OPINION];
    if(ult_sign==0||ult_lect==0) printf("\nOperacion imposible en este momento\n");	//SI NO HAY REFERENCIAS NI LECTORES SE ACABA LA FUNCION
    else {
        id = dame_numero(1,ult_sign,"\nEscribe la signatura: ");
        codigo = dame_numero(1,ult_lect,"\nEscribe el codigo: ");
        dame_cadena(MAX_LONG_OPINION, "\nEscribe el comentario: ", opinion);

        refe[id - 1].criticos++;
        refe[id - 1].info[refe[id - 1].criticos].lector = codigo;
        strcpy(refe[id - 1].info[refe[id - 1].criticos].opinion, opinion);

        printf("\nOpinion registrada\n");}
    return;}

void obtener_informe(int ult_sign){//LISTA
    int x, p=0, id;
    if(ult_sign==0) printf("\nOperacion imposible en este momento\n");
    else {
        id = dame_numero(1,ult_sign,"\nEscribe la signatura: ");
        printf("\nNumero de comentarios:%i", refe[id - 1].criticos);
        for (x = refe[id - 1].criticos; x > 0; x--) p++;
        if (refe[id - 1].criticos != 0) {
            for (x = 1; x <= refe[id-1].criticos; x++) {
                printf("\n%s:%s", lector[refe[id - 1].info[x].lector - 1].nombre, refe[id - 1].info[x].opinion);}
        }
        printf("\n");}
    return;}

void emitir_voto(int ult_sign){//LISTA
    int id, voto;
    if (ult_sign == 0) printf("\nOperacion imposible en este momento\n");
    else {
        id = dame_numero(1,ult_sign,"\nEscribe la signatura: ");
        voto = dame_numero(0,10,"\nEscribe el voto: ");
        refe[id - 1].votos += voto;    //SUMAMOS EL VALOR DE VOTO AL VALOR DE VOTOS DE ESA ID
        refe[id - 1].votantes++;        //E INCREMENTAMOS VOTANTES EN 1
        printf("\nVoto registrado\n");}
    return;}

void calcular_nota(int ult_sign){//LISTA
    if (ult_sign == 0) printf("\nOperacion imposible en este momento\n");	//SI NO HAY REFERENCIAS ACABA LA FUNCION
    else {
        int id = dame_numero(1,ult_sign,"\nEscribe la signatura: ");
        printf("\nNumero de votos:%i", refe[id - 1].votantes);
        if (refe[id - 1].votos == 0) printf("\nNota media:0.00\n");
        else printf("\nNota media:%.2f\n",(float) refe[id - 1].votos / refe[id - 1].votantes);}
    return;}
/*****************************************************************************************************************************************************************************
******************************************************************************AVANZADAS***************************************************************************************
*****************************************************************************************************************************************************************************/
void listar_referencia(int ult_sign){
	char tipo[256];
    int x;
	do{
    	dame_cadena(1,"\nL)Libros\nA)Articulos\n\nElige el tipo de referencias que quieres listar: ",tipo);
    	tipo[0]=toupper(tipo[0]);
		if(tipo[0]=='L'||tipo[0]=='A') x=1;
        else printf("\nTipo seleccionado no valido");		
	}while(x==0);
	
    for(x=0;x<ult_sign;x++){
        if(refe[x].tipo==tipo[0]){
            printf("\n%i) %s. \"%s\" (%i)",refe[x].signatura,refe[x].autor,refe[x].titulo,refe[x].anio);}
	}
	printf("\n");
	return;}

void buscar_referencia(int ult_sign){
    char cadena[256];
	int x, correcto=0;
	
    do {
    	printf("\nDame la cadena de busqueda: ");
    	fgets(cadena,sizeof(cadena),stdin);
    	for(x=0;x<strlen(cadena)-1;x++)
        	if(cadena[x]!=' '&&cadena[x]!='	') correcto=1;

        if (cadena[0] == '\n') correcto=0;
        	
        if (correcto==0) printf("\nCadena de busqueda vacia\n");
    }while(correcto==0);
    
    for(x=0;x<ult_sign;x++){
    	if(compara(cadena,refe[x].autor)==0) imprime_bus(x,&correcto);
    	if(compara(cadena,refe[x].titulo)==0) imprime_bus(x,&correcto);}
    if(correcto==1) printf("\nNinguna referencia contiene la cadena de busqueda\n");
    return;}

int compara(char *cadena1,char *cadena2){
    char p1[256],cad[256],cad1[256];
    int p,y,inicio=0,fin=strlen(cadena1);
    strcpy(cad,cadena1);
    strcpy(cad1,cadena2);
    cad[strlen(cad)-1]='\0';
    cad1[strlen(cad1)]='\0';
	
   // printf("Cadenas a comparar: %s---%s\n",cad,cad1);
    while(fin<strlen(cad1)+2) {
        y=0;
        for (p =inicio; p < fin-1; p++) {
            p1[y] = cad1[p];
            y++;}
    	p1[fin-1]='\0';
        if (strcmp(cad, p1)==0) return 0;
        inicio++;
        fin++;}
    return 1;}

void imprime_bus(int x, int *correcto){
    int y;
    *correcto=0;
    printf("\n%i) [%c] %s. \" %s\" (%i)\n",refe[x].signatura,refe[x].tipo,refe[x].autor,refe[x].titulo,refe[x].anio);
    if(refe[x].criticos!=0){
        for(y=1;y<=refe[x].criticos;y++)
            printf("%s -> %s\n",lector[refe[x].info[y].lector-1].nombre,refe[x].info[y].opinion);}
    return;}

void cambiar_lector(int ult_lect){
    char buscar[256], nuevo[256]="", sigo;
    int x, correcto=0,cambio=0;
    dame_cadenas(buscar,nuevo);
	  printf("\n");
    x=0;
    do{
    	while(x<=ult_lect||correcto==0){//Referemos el struct
			x++;
			//printf("*Nombres: %s--\n",lector[x-1].nombre);
			correcto=compara(buscar,lector[x-1].nombre);
			//printf("*Correcto ->%i--\n",correcto);			
		if(correcto==0){
			sigo=dame_confirmacion(x-1);
    			if(sigo=='S') {cambiar(x-1,nuevo,buscar);correcto=1;cambio++;return;}
			if(sigo=='N'){correcto=0;}
			
		} //CAMBIAMOS EL LECTOR
	
	}
    	if(correcto!=1 ||cambio==0) {
		printf("\nNingun lector cambiado\n");//SI NO ENCUENTRA EL LECTOR ACABA AQUI
		return;	
	}
    }while(x<=ult_lect||sigo=='S');   
    return;}
    
void dame_cadenas(char *buscar, char *nuevo){
	int x, correcto=0;
	printf("\n");
	do{
	
    		printf("\nDame el texto de busqueda: ");
    		fgets(buscar,256,stdin);
	 	/*if (buscar[0]=='\n') {
			printf("\nTexto vacio\n");
			}
		else correcto=1;*/
		for(x=0;x<strlen(buscar)-1;x++){
        		if((buscar[x]!='\t'||buscar[x]!=' ')&& buscar[0]!='\n'){
			  correcto=1;
			  break;
			} 
			else 	{
			   printf("\nTexto vacio\n");
		           correcto=0;			
			}					
		
		}
    	//	printf("Buscar: %s\n",buscar);
	}while(correcto==0);
	correcto=0;
	

	buscar[strlen(buscar)-1]='\0';
	int salta=1;
    do{
	salta=1;
    	//correcto=1;
    	printf("\nDame el nuevo texto: ");
    	fgets(nuevo,256,stdin);
    //    nuevo[strlen(nuevo)-1]='\0';
	
       for(x=0;x<strlen(nuevo);x++){
        	if (nuevo[x]==':'){
			salta=3; 
			//printf("%c %i",nuevo[x],salta);
			correcto=0;
			printf("\nCaracter invalido\n");
		//	imprimir(1);
			break;
		}//if
		//x++;
		//printf("Sustituir: %s\n",nuevo);
		
           }	
	if(salta==1) {correcto=1;break;}
    }while(correcto==0);
    nuevo[strlen(nuevo)-1]='\0';	
	return;}
	
char dame_confirmacion(int x){
	char sigo[256];
	int correcto;
	do{
        printf("\nEncontrado: %i) %s\n\nQuieres cambiar a este lector? (s/n): ",lector[x].codigo,lector[x].nombre);
       	fgets(sigo, sizeof(sigo), stdin);
       	sigo[0]=toupper(sigo[0]);
       	if (sigo[0] == 'N' || sigo[0] == 'S') correcto=1; 
      	if (sigo[1] != '\n') correcto=0;   
    } while(correcto==0);
	return sigo[0];}
	
void cambiar(int x, char *nuevo,char *buscar){
    char cambio[256];char cambio2[256];int pos_bus=0,y=0,p=0,tam=0,i=0;	
	char cambio3[256];
    pos_bus=strlen(buscar);
	for(i=0;i<strlen(lector[x].nombre);i++){
	//	printf("--%c----%c\n",buscar[0],lector[x].nombre[i]);
		if(lector[x].nombre[i]==buscar[0])break;
		else {
		cambio[i]=lector[x].nombre[i];
		
		}
	}
	cambio[i]='\0';
	//printf("0--%s\n",cambio);
	//if (i==strlen(lector[x].nombre)) i=0;
	for(y=0;y<strlen(nuevo);y++){//copio lo nuevo
		cambio2[y]=nuevo[tam];
		tam++;
		}
	cambio2[tam]='\0';
	strcat(cambio,cambio2);
	//printf("1--%s\n",cambio);
	for(y=i+pos_bus;y<strlen(lector[x].nombre);y++){//copio lo ultimo
		cambio3[p]=lector[x].nombre[y];
	//	printf("--%c",cambio3[y]);
		p++;
	}
	strcat(cambio,cambio3);
	cambio[i+tam+p]='\0';
	//printf("--%s\n",cambio);
    strcpy(lector[x].nombre,cambio);
    printf("\nLector cambiado a: %i) %s\n",lector[x].codigo,lector[x].nombre);
    return;}
/*****************************************************************************************************************************************************************************
******************************************************************************DAME DATOS**************************************************************************************
*****************************************************************************************************************************************************************************/
void dame_cadena (int limite,char *pantalla, char *cadena2){	//PENDIENTE REVISAR
    int i, correcto;
    char cadena[256];
    do{
        printf("%s",pantalla);
        fgets(cadena,sizeof(cadena),stdin);
        correcto=1; i=0;
        if (cadena[0]=='\n'){    				          //CADENA VACIA
            correcto=0;
            imprimir(2);}
        else if (limite+1<strlen (cadena)){       //LONGITUD CADENA EXCESIVA
            correcto=0;
            imprimir(3);}
        else {                                            //CARACTER INVALIDO
            while (i<strlen(cadena)){
                if (cadena[i]==':'){ correcto=0; imprimir(1);}
                i++;}
		}
    }while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA
    cadena[strlen(cadena)-1]='\0';
    strcpy(cadena2,cadena);}

int dame_numero(int limite1, int limite2, char *pantalla){			//100%LISTA
	int k, numero, correcto;
	char cadena[256];
	do{
    	correcto=1;
        printf("%s",pantalla);
        fgets(cadena,sizeof(cadena),stdin);
        for(k=0;k<strlen(cadena)-1;k++){
        	if(isdigit(cadena[k])==0) correcto=0;}
        numero=atoi(cadena);
        if (numero<limite1 || numero>limite2) correcto=0;
        if (correcto==0) imprimir(5);
    } while (correcto==0);

	return numero;}

char dame_tipo(){		//100%LISTA
    int correcto=0;
    char tipo[256];
	do{
		dame_cadena(1,"\nEscribe el tipo: ",tipo);
		tipo[0]=toupper(tipo[0]);
		if(tipo[0]=='L'||tipo[0]=='A') correcto=1;
        else imprimir(1);		
	}while(correcto==0);
	
    return tipo[0];}
/*****************************************************************************************************************************************************************************
******************************************************************************ACTUALIZAR TXTS*********************************************************************************
*****************************************************************************************************************************************************************************/
void actualizar_lector (int ult_lect){//LISTA
    int i;
    FILE *archivo;
    archivo = fopen("lectores.txt", "w");
    for (i=0; i<ult_lect; i++) {
        fprintf(archivo,":%i:%s:\n", lector[i].codigo,lector[i].nombre);}
    fclose(archivo);
    return;}

void actualizar_refe (int ult_sing) {//LISTA
    int x, z;
    FILE *archivo;
    archivo = fopen("referencias.txt", "w");
    for (x=0; x<ult_sing; x++) {
    	
        fprintf(archivo,":%i:%c:%s:%s:%i:%i:%i:%i:\n", refe[x].signatura, refe[x].tipo, refe[x].autor, refe[x].titulo, refe[x].anio, refe[x].votantes, refe[x].votos, refe[x].criticos);
		if(refe[x].criticos!=0) {
           for (z = 1; z <= refe[x].criticos; z++)
               fprintf(archivo, "#%i:%s:\n", refe[x].info[z].lector, refe[x].info[z].opinion);}
    }
    fclose(archivo);
	return;}
/*****************************************************************************************************************************************************************************
*******************************************************************************LEER TXTS**************************************************************************************
*****************************************************************************************************************************************************************************/
int leer_lector(){
    char cadena[256];
    char informacion[256];
    int lect=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){
    	leer_info(cadena,informacion,1);
    	lector[lect].codigo=atoi(informacion);
    	leer_info(cadena,informacion,2);
		strcpy(lector[lect].nombre,informacion);
        lect++;}
    fclose(archivo);
    return lect;}

int leer_referencia(){
    char cadena[256];
    int sign=0,id2;
    FILE *archivo;
    archivo = fopen("referencias.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){
        if(cadena[0]==':'){
            datos(cadena, &sign);
            sign++;
			id2=1;}

        else if(cadena[0]=='#'){
			opinions(cadena,&id2,&sign);
            id2++;}
    }
    fclose(archivo);
    return sign;}

void datos(char *cadena, int *sign){
	char informacion[256];
    leer_info(cadena,informacion,1);
    refe[*sign].signatura=atoi(informacion);
    leer_info(cadena,informacion,2);
    refe[*sign].tipo=informacion[0];
    leer_info(cadena,informacion,3);
    strcpy(refe[*sign].autor,informacion);
    leer_info(cadena,informacion,4);
    strcpy(refe[*sign].titulo,informacion);
    leer_info(cadena,informacion,5);
    refe[*sign].anio=atoi(informacion);
    leer_info(cadena,informacion,6);
    refe[*sign].votantes=atoi(informacion);
    leer_info(cadena,informacion,7);
    refe[*sign].votos=atoi(informacion);
    leer_info(cadena,informacion,8);
    refe[*sign].criticos=atoi(informacion);}

void opinions(char *cadena, int *id2, int *id){
    char informacion[256];
	leer_info(cadena,informacion,1);
	refe[*id-1].info[*id2].lector=atoi(informacion);
    leer_info(cadena,informacion,2);
    strcpy(refe[*id-1].info[*id2].opinion, informacion);}

void leer_info(char *cadena, char *texto,int pos){
	int k, posicion, puntos=0;
	
	for(k=0;puntos<pos;k++){		//BUSCA EL INICIO DEL TEXTO EN LA CADENA
		if(cadena[k]==':'||cadena[k]=='#') {posicion=k+1; puntos++;}
	}
	for(k=posicion;cadena[k]!=':';k++){
		texto[k-posicion]=cadena[k];}	//PASA EL CONTENIDO DESEADO A TEXTO
	texto[k-posicion]='\0';	
	return;}
/*****************************************************************************************************************************************************************************
********************************************************************************IMPRIMIR**************************************************************************************
*****************************************************************************************************************************************************************************/
void imprimir(int linea){
    char *errores[]={
            /*0*/   "\nError de formato en un fichero: ?Linea mal formada en el fichero (NOMBRE_FICHERO)\n",
            /*1*/   "\nCaracter invalido\n",
            /*2*/   "\nCadena vacia\n",
            /*3*/   "\nLongitud de la cadena excesiva\n",
            /*4*/   "\nLector repetido\n",
            /*5*/ 	"\nValor seleccionado incorrecto\n",
            /*6*/ 	"\nOperacion imposible en este momento\n",
    };
    printf("%s",errores[linea]);
    return;}
