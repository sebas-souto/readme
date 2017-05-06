//BASE DE DATOS
#include "base_de_datos.h"
void programa(int eleccion){		//100%LISTO
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
			break;
	}
  int k;
//	for(k=0;k<tam_ref;k++)printf("%i:%c:%s:%s:%i:%i:%.2f:%i\n",refe[k].signatura,refe[k].tipo,refe[k].autor,refe[k].titulo,refe[k].anio,refe[k].votantes,refe[k].votos,refe[k].criticos);
 // for(k=0;k<tam_lec;k++)printf("%i:%s\n",lector[k].codigo,lector[k].nombre);
    actualizar_lector(tam_lec);
	actualizar_refe(tam_ref);
    return;}

//BASICAS--------------------------------------------
void incorporar_lector (int *ult_lect){		//100%LISTA
    char nombre[MAX_LONG_NOMBRE];
    dame_cadena(MAX_LONG_NOMBRE,"\nEscribe el nombre del lector: ",nombre);
    if(comprobar_lector(nombre,ult_lect)==0) imprimir(4);
    else {
        asignar_id(nombre,ult_lect);
        printf("\nLector %s: asignado %i\n\n",lector[*ult_lect-1].nombre,lector[*ult_lect-1].codigo);}
	return;}

void agregar_referencia(int *ult_sign){		//100%LISTA
    int a=*ult_sign;
    *ult_sign+=1;
    refe[*ult_sign-1].signatura=*ult_sign;
    dame_autor(a);
    dame_titulo(a);
    dame_anio(a);
    dame_tipo(a);
    refe[a].criticos=0;
    refe[a].votantes=0;
    refe[a].votos=0;
    printf("\nReferencia %c:%s:%s:%i: asignada %i\n",refe[a].tipo,refe[a].autor,refe[a].titulo,refe[a].anio,refe[a].signatura);
    return;}

void expresar_opinion(int ult_sign,int ult_lect){		//70%LISTA
    int codigo, correcto=0, id=dame_signatura(ult_sign);
    char cadena[256], opinion[MAX_LONG_OPINION];    
    
    do{
    	dame_cadena(256,"\nEscribe el codigo: ",cadena);
    	codigo=atoi(cadena);
    	if((codigo>0)&&(codigo<=ult_lect)) correcto=1;
    	else imprimir(5);
	}while(correcto==0);
    dame_cadena(MAX_LONG_OPINION,"\nEscribe el comentario: ",opinion);
    
    refe[id-1].criticos++;
    refe[id-1].info[refe[id-1].criticos].lector=codigo;
    strcpy(refe[id-1].info[refe[id-1].criticos].opinion,opinion);
    
    printf("\nOpinion registrada\n");
    return;}

void obtener_informe(int ult_sign){		//100%LISTA
    int x, p=0, id=dame_signatura(ult_sign);
    
    printf("\nNumero de comentarios:%i",refe[id-1].criticos); 
    for (x = refe[id-1].criticos; x > 0; x--) p++;
    if(refe[id-1].criticos!=0) {
        for (x = refe[x].criticos; x > 0; x--) {
            printf("\n%s:%s", lector[refe[id - 1].info[x].lector - 1].nombre, refe[id - 1].info[x].opinion);}
    }    
	printf("\n");
    return;}

void emitir_voto(int ult_sign){			//90%LISTA
    int k, correcto, id=dame_signatura(ult_sign);
    float voto;
    char cadena[256];
	do{
    	correcto=1;
        printf("\nEscribe el voto: ");
        fgets(cadena,sizeof(cadena),stdin);
/*        for(k=0;k<strlen(cadena)-1;k++){
        	if(isdigit(cadena[k])==0) correcto=0;}*/
        voto=atof(cadena);
        if(voto<0 || voto>10) correcto=0;
        if (correcto==0) imprimir(5);
    } while (correcto==0);
    refe[id-1].votos+=voto; 	//SUMAMOS EL VALOR DE VOTO AL VALOR DE VOTOS DE ESA ID
    refe[id-1].votantes++;		//E INCREMENTAMOS VOTANTES EN 1
    printf("\nVoto registrado\n");
    return;}

void calcular_nota(int ult_sign){		//100%LISTA
    int id=dame_signatura(ult_sign);

    printf("\nNumero de votos:%i",refe[id-1].votantes);
    if (refe[id-1].votos==0) printf("\nNota media:0.00\n");
    else printf("\nNota media:%.2f\n",refe[id-1].votos/refe[id-1].votantes);
    return;}
//AVANZADAS------------------------------------------
void listar_referencia(int ult_sign){		//100%LISTA
    char cadena[256];
    int correcto;

    do {
        printf("\nL)Libros\nA)Articulos\n\nElige el tipo de referencia que quieres listar: ");
        fgets(cadena, sizeof(cadena), stdin);
        correcto=1;

        if (toupper(cadena[1]) != '\n'){
			printf("\nTipo seleccionado no valido\n");
			correcto=0;}
			
        else if (toupper(cadena[0]) != 'L' && toupper(cadena[0]) != 'A'){
        	printf("\nTipo seleccionado no valido.\n");
        	correcto=0;}
    }while(correcto==0);
    
    dame_referencias(toupper(cadena[0]), ult_sign);
	return;}

void dame_referencias(char letra,int ult_sign){		//100%LISTA
    int x;
    for(x=0;x<ult_sign;x++){
        if(refe[x].tipo==letra){
            printf("\n%i) %s. \"%s\" (%i)",refe[x].signatura,refe[x].autor,refe[x].titulo,refe[x].anio);}
	}
	printf("\n");
	return;}

void buscar_referencia(int ult_sign){
    char cadena[256];
	int correcto=0, lon=0;
    do{
    	printf("\nDame la cadena de busqueda: ");
		fgets(cadena,sizeof(cadena),stdin);
		lon=strlen(cadena);
		
		if (cadena[0] == '\n') printf("\nCadena de busqueda vacia\n");
		else correcto= busca(cadena, ult_sign);
    }while(correcto==0);
    
    return;}

int busca(char *cadena,int tamanio){
    int resultado=0;int correcto=1;//vemos si la comparacion tuvo exito o no->1 exito ->0 no exito
    resultado=compara_nombre(cadena,tamanio);
    if(resultado==0){
        return correcto;
    }
    resultado=compara_titulo(cadena,tamanio);
    if(resultado==0){
        return correcto;
    }
    else{
        printf("\nNinguna referencia contiene la cadena buscada\n");
        correcto=0;
        return correcto;
    }
}

int compara_nombre(char *cadena,int tamanio){
    int correcto,x,y,inicio=0,fin=strlen(cadena);
    for(x=0;x<tamanio;x++){//Referemos el struct
       // for(y=0;y<strlen(refe[x].autor);y++){
            correcto=compara(cadena,refe[x].autor);
            if(correcto==0) {
               /* printf("%i) [%c] %s. \" %s\" (%i)\n",refe[x].signatura,refe[x].tipo,refe[x].autor,refe[x].titulo,refe[x].anio);
                if(refe[x].criticos!=0){

                }*/
                imprime_bus(x);
                return correcto;
            }
       // }
    }
    return correcto;
}

int compara_titulo(char *cadena,int tamanio){
    int correcto;
    int x,y,inicio=0,fin=strlen(cadena);
    for(x=0;x<tamanio;x++){//Referemos el struct
       // for(y=0;y<strlen(refe[x].titulo);y++){
            correcto=compara(cadena,refe[x].titulo);
            if(correcto==0) {
               // printf("%i) [%c] %s .\" %s\" (%i)\n",refe[x].signatura,refe[x].tipo,refe[x].autor,refe[x].titulo,refe[x].anio);
                imprime_bus(x);
                return correcto;
            }

      //  }

    }

    return correcto;
}

int compara(char *cadena1,char *cadena2){
    char p1[256],cad[256],cad1[256];
    int correcto,x,p,y=0,inicio=0,fin=strlen(cadena1);
    strcpy(cad,cadena1);
    strcpy(cad1,cadena2);
    cad[strlen(cad)-1]='\0';
    cad1[strlen(cad1)]='\0';
    while(fin<strlen(cad1)+2) {
        y=0;
        for (p =inicio; p < fin-1; p++) {
            p1[y] = cad1[p];
            y++;
        }
         p1[fin-1]='\0';
        //x=0;
        correcto = strcmp(cad, p1);
    //    printf("%s---%s---%i\n",cad,p1,correcto);
        if (correcto==0) return 0;
        inicio++;
        fin++;
    }
    return correcto;
}

void imprime_bus(int x){
    int y;
    printf("%i) [%c] %s. \" %s\" (%i)\n",refe[x].signatura,refe[x].tipo,refe[x].autor,refe[x].titulo,refe[x].anio);
    if(refe[x].criticos!=0){
        for(y=1;y<refe[x].criticos+1;y++){
            printf("%s -> %s\n",lector[refe[x].criticos].nombre,refe[x].info[y].opinion);
        }

    }

}

void cambiar_lector(int tam_lec){
    char buscar[256], nuevo[256];
    int lon=0,x,sigue=1,correcto=0;
    do{
        sigue=1;
        while(sigue==1) {
            printf("Dame el texto de busqueda: ");
            fgets(buscar, sizeof(buscar), stdin);

            if (buscar[0] == '\n') printf("\nCadena de busqueda vacia\n\n");
            else sigue=0;
         }
         sigue=1;
            do{
            //   printf("\n");
            printf("\nDame el nuevo texto: ");
            fgets(nuevo, sizeof(nuevo), stdin);
            if (nuevo[0] == '\n') printf("\nCadena de busqueda vacia\n\n");
                buscar[strlen(buscar) - 1] = '\0';
                nuevo[strlen(nuevo) - 1] = '\0';
                for (x = 0; x < strlen(nuevo); x++) {
                    if (nuevo[x] == ':') {
                        printf("Caracter invalido\n");
                      //  return;
                    }
                }
              //  printf("%s --> %s\n", buscar, nuevo);
                lon = encontrar(buscar, tam_lec,0);
              //  printf("--> %i\n",lon);
                if (lon != -1) {
                    cambiar(lon, nuevo,buscar,tam_lec);
                    sigue=0;
                    correcto=1;
                   // break;
                }
                else {
                    sigue = 0;
                  //  break;
                }
         } while(sigue==1);
    }while(correcto==0);

}

int encontrar(char *buscar, int ult_lect,int inicio){//->ok 0, fallo->-1
    int correcto,x=0,y,fin=strlen(buscar);

    for(x=inicio;x<ult_lect;x++){//Referemos el struct
        correcto=compara(buscar,lector[x].nombre);

        if(correcto==0) {
        	printf("Encontrado: %i) %s\n",lector[x].codigo,lector[x].nombre);
            correcto=x;
            return correcto;}
            correcto=-1;
          //  return correcto;
    }
    return correcto;
}

void cambiar(int x,char *nuevo,char *buscar,int tam_lec){
    char confirmar[256]; int p=0, sigue=0;
    while(sigue==0) {
        printf("Quieres cambiar a este lector? (s/n):");
        fgets(confirmar, sizeof(confirmar), stdin);
        if (confirmar[0] == '\n'|| confirmar[0]=='\0') {
           // sigue=0;
        }
        if (strlen(confirmar) < 2) sigue=0;
        if (confirmar[0] == 'N' || confirmar[0] == 'n') {
            encontrar(buscar, tam_lec,x);}
        else sigue=1;
    }
    if(confirmar[0]=='S'||confirmar[0]=='s'){
        nuevo[strlen(nuevo)]='\0';
     //   printf("***1-->%i---%s----%s\n",x+1,lector[x].nombre,nuevo);
        strcpy(lector[x].nombre,nuevo);
        printf("Lector cambiado a: %i) %s\n",lector[x].codigo,lector[x].nombre);
        return;
    }
    else{
        return;
    }
}

//LECTOR---------------------------------------------
int comprobar_lector(char nombre[MAX_LONG_NOMBRE], int *ultimo){		//100%LISTA
    int i;
    for(i=0;i<*ultimo;i++){
        if ((strcmp(nombre,lector[i].nombre))==0) return 0;}
    return 1;}

void asignar_id(char nombre[MAX_LONG_NOMBRE],int *ultimo){		//100%LISTA
	*ultimo+=1;
    strcpy(lector[*ultimo-1].nombre,nombre);
    lector[*ultimo-1].codigo=*ultimo;}
//REFERENCIA-----------------------------------------
void dame_cadena (int limite,char *pantalla, char *cadena2){	//100%LISTA
    int i=0, correcto;
    char cadena[limite+2];
    do{
        printf("%s",pantalla);
        fgets(cadena,sizeof(cadena),stdin);
        correcto=1;

        if (cadena[0]=='\n'){    				          //CADENA VACIA
            correcto=0;
            imprimir(2);}
        else if (cadena[strlen(cadena)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
            correcto=0;
            imprimir(3);
            while (fgetc(stdin) != '\n');}
        else {                                            //CARACTER INVALIDO
            while (i<strlen(cadena)){
                if (cadena[i]==':'){ correcto=0; imprimir(1);}
                i++;}
		}
    }while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA
    cadena[strlen(cadena)-1]='\0';
    strcpy(cadena2,cadena);}

void dame_autor(int sign){		//100%LISTA
    char autor[MAX_LONG_AUTOR];
    dame_cadena(MAX_LONG_AUTOR,"\nEscribe el autor de la referencia: ",autor);
    strcpy(refe[sign].autor,autor);
	return;}

void dame_titulo(int sign){		//100%LISTA
    char titulo[MAX_LONG_TITULO];
    dame_cadena(MAX_LONG_TITULO,"\nEscribe el titulo: ",titulo);
    strcpy(refe[sign].titulo,titulo);
	return;}

void dame_anio(int sign){		//90%LISTA
    int year,correcto=0;
    char cadena[256];
    do{
    	dame_cadena(256,"\nEscribe el anho: ",cadena);
    	year=atoi(cadena);
    	if((1450<year)&&(year<2017)) correcto=1;
    	else imprimir(5);
	}while(correcto==0);
	
    refe[sign].anio=year;
    return;}

void dame_tipo(int sign){		//100%LISTA
    int correcto=0;
    char tipo[256];
	do{
		dame_cadena(1,"\nEscribe el tipo: ",tipo);
		tipo[0]=toupper(tipo[0]);
		if(tipo[0]=='L'||tipo[0]=='A') correcto=1;
        else imprimir(1);		
	}while(correcto==0);
	
    refe[sign].tipo=tipo[0];
    return;}

int dame_signatura(int ult_sing){			//100%LISTA
	int k, signatura, correcto;
	char cadena[256];
	do{
    	correcto=1;
        printf("\nEscribe la signatura: ");
        fgets(cadena,sizeof(cadena),stdin);
        for(k=0;k<strlen(cadena)-1;k++){
        	if(isdigit(cadena[k])==0) correcto=0;}
        signatura=atoi(cadena);
        if (signatura<1 || signatura>ult_sing) correcto=0;
        if (correcto==0) imprimir(5);
    } while (correcto==0);
	
	return signatura;}
//ACTUALIZAR TXTs------------------------------------
void actualizar_lector (int ult_lect){		//100%LISTA
    int i;
    FILE *archivo;
    archivo = fopen("lectores.txt", "w");
    for (i=0; i<ult_lect; i++) {
        fprintf(archivo,":%i:%s:\n", lector[i].codigo,lector[i].nombre);}
    fclose(archivo);}

void actualizar_refe (int ult_sing) {		//100%LISTA
    int x, z;
    FILE *archivo;
    archivo = fopen("referencias.txt", "w");
    for (x=0; x<ult_sing; x++) {
        fprintf(archivo,":%i:%c:%s:%s:%i:%i:%f:%i:\n", refe[x].signatura, refe[x].tipo, refe[x].autor, refe[x].titulo, refe[x].anio, refe[x].votantes, refe[x].votos, refe[x].criticos);
        for (z = refe[x].criticos; z > 0; z--) {
            fprintf(archivo,"#%i:%s:\n", refe[x].info[z].lector, refe[x].info[z].opinion);}
    }
    fclose(archivo);}

//LEER LECTOR-----------------------------------------
int leer_lector(){				//100%LISTA
    char cadena[256];
    int pts[256], lect=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){
        obtener_puntos(cadena,pts);
        obtener_codigo(cadena,pts,lect);
        obtener_nombre(cadena,pts,lect);
        lect++;}
    fclose(archivo);
    return lect;}

void obtener_puntos(char *cadena,int *pts){					//100%LISTA
    int i, j=0;
    for(i=0;i<strlen(cadena);i++){
        if(cadena[i]==':'){
            j++;
            pts[j]=i;}
    }
    return;}

void obtener_codigo(char *cadena, int *pts,int lect){		//100%LISTA
    int x, p=0;
    char variable[10],cadena2[256];
    strcpy(cadena2,cadena);
    cadena2[pts[2]]='\0';
    for(x=pts[1];x<pts[2];x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            p++;}
    }
    lector[lect].codigo=atoi(variable);
	return;}

void obtener_nombre(char *cadena, int *pts,int lect){		//100%LISTA
    int x, p=0;
    char cadena2[256];
    strcpy(cadena2, cadena);
    cadena2[pts[3]] = '\0';
    for (x = pts[2]; x < strlen(cadena2); x++) {
        if (cadena2[x] != ':') {
            cadena2[p] = cadena2[x];
            p++;}
    }
    cadena2[p] = '\0';
    strcpy(lector[lect].nombre,cadena2);
    return;}

//LEER REFERENCIA------------------------------------
int leer_referencia(){
    char cadena[256];
    int sign=0,id2=0;
    FILE *archivo;
    archivo = fopen("referencias.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){
        if(cadena[0]==':'){
            datos(cadena, &sign);
            sign++;
            id2=refe[sign-1].criticos;}

        else if(cadena[0]=='#'){
			opinions(cadena,&id2,&sign);
            id2--;}
    }
    fclose(archivo);
    return sign;}

void datos(char *cadena, int *sign){
    int pts[256];
    puntos(cadena,pts);
    signa(cadena,pts,sign);
    tipo(cadena,pts,sign);
    autor(cadena,pts,sign);
    titulo(cadena,pts,sign);
    anho(cadena,pts,sign);
    votantes(cadena,pts,sign);
    votos(cadena,pts,sign);
    criticos(cadena,pts,sign);
}

void opinions(char *cadena, int *id2, int *id){
    int pts[10], r=*id, m=*id2;
    puntos(cadena,pts);
    lect(cadena,pts,&m,&r);
    opinion(cadena,pts,&m,&r);
}

void puntos(char *cadena,int *pts){
    int i=0, j=0;
    for(i=0;i<strlen(cadena);i++){
        if(cadena[i]==':'){
            j++;
            pts[j]=i;}
    }
    return;}

void signa(char *cadena, int *pts, int *sign){
    int x;
    char cadena2[80];
    strcpy(cadena2,cadena);
    cadena2[pts[2]]='\0';

    for(x=0;x<strlen(cadena2);x++) cadena2[x]=cadena2[x+1];
    refe[*sign].signatura=atoi(cadena2);
    return;}

void tipo(char *cadena, int *pts, int *sign){
    int num=0,x;
    char variable[10], cadena2[80];
    strcpy(cadena2,cadena);
    cadena2[pts[3]]='\0';

    for(x=pts[2];x<pts[3];x++){
        if(cadena[x]!=':') {
            variable[num] = cadena2[x];
            num++;}
    }
    refe[*sign].tipo=variable[0];
    return;}

void autor(char *cadena, int *pts, int *sign){
    int num=0,x;
    char cadena2[80];
    strcpy(cadena2,cadena);
    cadena2[pts[4]]='\0';

    for(x=pts[3];x<strlen(cadena2);x++){
        if(cadena[x]!=':') {
            cadena2[num] = cadena2[x];
            num++;}
    }
    cadena2[num]='\0';
    strcpy(refe[*sign].autor,cadena2);
    return;}

void titulo(char *cadena, int *pts, int *sign) {
    int num = 0, x;
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
    strcpy(refe[*sign].titulo, cadena2);
    // printf("%s\n",refe[y].titulo);
}

void anho(char *cadena, int *pts, int *sign){
    int x,p=0;
    char variable[10],cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[6]]='\0';
    for(x=pts[5];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            p++;}
    }
    variable[p]='\0';
    refe[*sign].anio=atoi(variable);
    return;}

void votantes(char *cadena, int *pts, int *sign){
    int x,p=0;
    char cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[7]]='\0';
    for(x=pts[6];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            cadena2[p] = cadena2[x];
            p++;}
    }
    cadena2[p]='\0';
    refe[*sign].votantes=atoi(cadena2);
    return;}

void votos(char *cadena, int *pts, int *sign){
    int x,p=0;
    char cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[8]]='\0';
    for(x=pts[7];x<pts[8];x++){
        if(cadena2[x]!=':') {
            cadena2[p] = cadena2[x];
            p++;}
    }
    cadena2[p]='\0';
    refe[*sign].votos=atof(cadena2);
    return;}

void criticos(char *cadena, int *pts, int *sign){
    int x,p=0;
    char cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[9]]='\0';
    for(x=pts[8];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            cadena2[p] = cadena2[x];
            p++;}
    }
    cadena2[p]='\0';
    refe[*sign].criticos=atoi(cadena2);
    return;}

void lect(char *cadena, int *pts,int *id2,int *id){
    int num,x,p=0;
    int y=*id;
    int r=*id2;
    char variable[10],cadena2[256];
    strcpy(cadena2,cadena);
    cadena2[pts[1]]='\0';

    for(x=0;x<strlen(cadena2);x++){
        if(cadena2[x]=='#') {
            p=x;}
    }

    for(x=p;x<strlen(cadena2);x++){
        if(cadena2[x]!='#') {
            variable[p] = cadena2[x];
            p++;}
    }
    refe[y-1].info[r].lector=atoi(variable);
    return;}

void opinion(char *cadena, int *pts,int *id2,int *sign){
    int x, p=0;
    char variable[80],cadena2[81];
    strcpy(cadena2, cadena);
    cadena2[pts[2]] = '\0';
    for (x = pts[1]; x < strlen(cadena2); x++) {
        if (cadena[x] != ':') {
            variable[p] = cadena2[x];
            p++;}
    }
    variable[p]='\0';
    strcpy(refe[*sign-1].info[*id2].opinion, variable);
    return;}
//IMPRIMIR--------------------------------------------
void imprimir(int linea){
    char *errores[]={
            /*0*/   "\nError de formato en un fichero: ?Linea mal formada en el fichero (NOMBRE_FICHERO)\n",
            /*1*/   "\nCaracter invalido\n",
            /*2*/   "\nCadena vacia\n",
            /*3*/   "\nLongitud de cadena excesiva\n",
            /*4*/   "\nLector repetido\n",
            /*5*/ 	"\nValor seleccionado incorrecto\n",
            /*6*/ 	"\nOperacion imposible en este momento\n",
    };
    printf("%s",errores[linea]);
    return;}
