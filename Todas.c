//SOLO FALTA CALCULAR 
/*HABRIA A MAYORES QUE COMPROBAR EL CORRECTO FUNCIONAMIENTO DE TODAS LAS FUNCIONES, ES DECIR PARA DIRENTES ENTRADAS SI 
DA LO QUE TIENE QUE DAR.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LONGITUD 50
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

struct referencia refe[100];
int leer_referencia();
void emitir_voto(int *tamanio);
/***************************LEER TXT REFERENCIA************************************************************************/
void datos(char *cadena, int *id);
int puntos(char *cadena,int *pts);
void signa(char *cadena, int *pts,int *id);
void tipo(char *cadena, int *pts, int *id);
void autor(char *cadena, int *pts, int *id);
void titulo(char *cadena, int *pts, int *id);
void anho(char *cadena, int *pts,int *id);
void votantes(char *cadena, int *pts,int *id);
void votos(char *cadena, int *pts,int *id);
void criticos(char *cadena, int *pts,int *id);
void opinions(char *cadena, int *id2,int *id);
void lect(char *cadena, int *pts, int *id2, int *id);
void opinion(char *cadena, int *pts, int *id2, int *id);

/**********************************************************************************************************************/


void actualizar_refe (int *limite);

/*******************FUNCIONES INTRODUCIR REFERENCIA********************************************************************/


void agregar_referencia(int *id);
void dame_autor(int *id);
void dame_titulo(int *id);
void dame_anio(int *id);
void dame_tipo(int *id);
void imprimir(int linea);
void confimar (int limite ,char *pantalla,char *cadena2);



/**********************************************************************************************************************/
struct lectores{
    int codigo;
    char nombre[256];

};

struct lectores lector[100];
int incorporar_lector(int *limite);

void obtener_codigo(char *cadena, int *pts,int *id);
int leer_lector();
void obtener_nombre(char *cadena, int *pts,int *id);
int obtener_puntos(char *cadena,int *pts);
int comprobar_lector(char nombre[50], int *tamanio);
void asignar_id(char nombre[LONGITUD],int *limite);
void actualizar_txt (int *limite);




/**********************************************************************************************************************/
void obtener_informe(int *tamanio);
void expresa_opinion(int *tamanio,int *tam_lector);


int main(){
    //struct refencia refe[5];
    int r,x,z, tamanio=0,tam_lector;
    //int limite,resultado;
    tam_lector=leer_lector();
    tamanio=leer_referencia();
   // agregar_referencia(&tamanio);
 //   emitir_voto(&tamanio);
    //actualizar_refe (&tamanio);
  //  obtener_informe(&tamanio);
    expresa_opinion(&tamanio,&tam_lector);
    actualizar_refe (&tamanio);

  //  printf("tamanio: %i\n",tamanio);
   /* for(r=0;r<5;r++) {
        printf("*******************************************************************************************\n");
        for (x = 0; x < tamanio; x++) {
            printf("%i %c %s %s %i %i %i %i\n", refe[x].signatura, refe[x].tipo, refe[x].autor, refe[x].titulo,
                   refe[x].anio, refe[x].votantes, refe[x].votos, refe[x].criticos);
            //printf("criticos:%i\n",refe[x].criticos);
            for (z = refe[x].criticos; z > 0; z--) {
                // printf("z:%i--x=%i--\n",z,x);
                printf("%i %s\n", refe[x].info[z].lector, refe[x].info[z].opinion);
            }
        }
    }*/
    return 0;
}



/****************************LEER REFERENCIA***************************************************************************/


int leer_referencia(){

    char cadena[256];
    int id=0,id2=0;
    FILE *archivo;
    archivo = fopen("referencia.txt", "r");


    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){

       // fgets(cadena,sizeof(cadena),archivo);
        //id++;
       // printf("%s\n",cadena);

        if(cadena[0]==':'){
           // printf("%i :\n",id);
            datos(cadena, &id);
            id++;
            id2=refe[id-1].criticos;
        }

        else if(cadena[0]=='#'){

            //printf("id2: %i \n",id2);
           opinions(cadena,&id2,&id);
            id2--;
        }
        else{
            printf("Formato del fichero incorrecto\n");
        }
    }


    fclose(archivo);
    return id;

}


void opinions(char *cadena, int *id2, int *id){
    int pts[10];//Array que indica en que posicion de la cadena esta los :
    int r=*id;
    int m=*id2;
    puntos(cadena,pts);
    lect(cadena,pts,&m,&r);
    opinion(cadena,pts,&m,&r);


}

void datos(char *cadena, int *id){
    int pts[10];//Array que indica en que posicion de la cadena esta los :
    int r=*id;
    puntos(cadena,pts);
    /*for(x=1;x<sizeof(pts) / sizeof(int);x++){
        printf("%i ",pts[x]);
    }
    printf("\n");*/
    signa(cadena,pts,&r);
    tipo(cadena,pts,&r);
    autor(cadena,pts,&r);
    titulo(cadena,pts,&r);
    anho(cadena,pts,&r);
    votantes(cadena,pts,&r);
    votos(cadena,pts,&r);
    criticos(cadena,pts,&r);

}


int puntos(char *cadena,int *pts){
    int i=0, j=0;
    //int pts[10];
    for(i=0;i<strlen(cadena);i++){
        if(cadena[i]==':'){
            j++;
            pts[j]=i;
        }
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

/**********************************************************************************************************************/




/**********************************INTRODUCIR REFERENCIA***************************************************************/


void agregar_referencia(int *id){
    int tam=*id;
    int a=tam;
    tam=tam+1;
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


void dame_autor(int *id){
    int id2=*id;
    char autor[50];
    char pantalla[]="Escribe el autor de la referencia: ";
    confimar(50,&pantalla,autor);
    autor[strlen(autor)-1]='\0';
    strcpy(refe[id2].autor,autor);
    //printf("%s-----%i",refe[id2].autor,id2);
}



void dame_titulo(int *id){
    int id2=*id;
    char titulo[80];
    char pantalla[]="Escribe el titulo: ";
    confimar(80,&pantalla,titulo);
    titulo[strlen(titulo)-1]='\0';
    strcpy(refe[id2].titulo,titulo);
}



void dame_anio(int *id){
    int id2=*id;
    int cadena[5];
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



void imprimir(int linea){
    char *errores[]={
            /*0*/   "\nError de formato en un fichero: �Linea mal formada en el fichero (NOMBRE_FICHERO)\n\n",
            /*1*/   "\nCaracter invalido\n\n",
            /*2*/   "\nCadena vacia\n\n",
            /*3*/   "\nLongitud de cadena excesivan\n\n",
            /*4*/   "\nLector repetido\n\n",
            /*5*/ "\nValor seleccionado incorrecto\n\n",
            /*6*/ "\nOperacion imposible en este momento\n\n",
    };

    printf("%s",errores[linea]);
}

/**********************************************************************************************************************/

void actualizar_refe (int *limite) {
    int x, z;
    int tamanio = *limite;
    FILE *archivo;
    //printf("LLega aqui!!!!\n");
    archivo = fopen("referencia.txt", "w");
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

/*****************************************EMITIR VOTO *****************************************************************/

void emitir_voto(int *tamanio){
    int id,voto,ULT_ID=*tamanio;

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
    refe[id-1].votos=refe[id-1].votos+voto;
    printf("id: %i voto: %i",id,refe[id-1].votos);
    refe[id-1].votantes=refe[id-1].votantes+1;
    //AQUI SUMAMOS EL VALOR DE VOTO AL VALOR DE VOTOS DE ESA ID
    //E INCREMENTAMOS VOTANTES EN 1

    printf("\nVoto registrado\n");
    return;
}


/********************************************OBTENER INFORME***********************************************************/
void obtener_informe(int *tamanio){
    int id,x,z,ULT_ID=*tamanio;
    char cadena[256];
    //ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
    //SE USA 15 COMO EJEMPLO

    do{
        printf("\nEscribe la signatura: ");
        fgets(cadena,sizeof(cadena),stdin);
        id=atoi(cadena);
        if (id<1 || id>ULT_ID)
            printf("\nValor seleccionado incorrecto\n");

    } while (id<1 || id>ULT_ID);

    //DECIDE A QUE ID SE LE VA A ASIGNAR EL VOTO	SIGNATURA=ID
    printf("Numero de comentarios:%i\n",refe[id-1].criticos);
    int p=0;
    /*for (x = refe[id-1].criticos; x > 0; x--){
        z=refe[id-1].info[x].lector;
        printf("z=%i");
        //printf("%s:%s \n", lector[x].nombre,refe[id-1].info[x].opinion);
        p++;
    }*/
    if(refe[x].criticos!=0) {
        for (x = refe[x].criticos; x > 0; x--) {
            // printf("z:%i--x=%i--\n",z,x);
            printf("%s:%s \n", lector[refe[id - 1].info[x].lector - 1].nombre, refe[id - 1].info[x].opinion);
            //printf("z:%i\n",refe[id-1].info[x].lector);
        }
    }

    return;
}




/***********************************EXPRESAR OPINION*******************************************************************/

void expresa_opinion(int *tamanio,int *tam_lector){
    int id,x,z,ULT_ID=*tamanio,codigo;
    int ULT_COD=*tam_lector;
    char cadena[256], comentario[256];
    //ULT_ID DEBE SER EL VALOR DE LA ULTIMA ID
    //SE USA 15 COMO EJEMPLO

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




/**************************INCORPORAR LECTOR***************************************************************************/

//INCORPORAR LECTOR
int incorporar_lector (int *limite){
    int i,correcto,repetido,resul;
    char nombre[LONGITUD];
    int tamanio=*limite;
    do{
        printf("Escribe el nombre del lector: ");
        fgets(nombre,sizeof(nombre),stdin);
        correcto=1;
        i=0;

        if (nombre[0]=='\n'){    				          //CADENA VACIA
            correcto=0;
            printf("Cadena vacia\n");
        }
        else if (nombre[strlen(nombre)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
            correcto=0;
            printf("Longitud excesiva\n");
            while (fgetc(stdin) != '\n');
        }
        else {                                            //CARACTER INVALIDO
            while (i<strlen(nombre)){
                if (nombre[i]==':'){
                    correcto=0;
                    printf("Caracter invalido\n");
                }
                i++;
            }


            //ASIGNAMOS CODIGO REGISTRAMOS LECTOR IMPRIMIMOS LECTOR Y CODIGO
        }

    }while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA
    //printf("\nLector %s: asignado %i \n",lector[tamanio].nombre,lector[tamanio].codigo);
    //LECTOR REPETIDO
    int a;
    for(a=0;a<strlen(nombre);a++) {
        if(nombre[a]== '\n'){
            nombre[a] = '\0';
            break;
        }
    }
    //printf("---%s-----8888\n",nombre);
    repetido=comprobar_lector(nombre,&tamanio);
    if(repetido==0) {printf("Lector repetido.\n"); resul=0; correcto==1;  }
    else {
        asignar_id(nombre,&tamanio);
        *limite=tamanio;
        printf("Lector %s: asignado %i\n",lector[tamanio-1].nombre,lector[tamanio-1].codigo);
        resul=1;
    }

    return resul;
}


int leer_lector(){

    char cadena[256];
    int pts[256];
    int id=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){

        // fgets(cadena,sizeof(cadena),archivo);

        //   while (fgetc(archivo) != '\n');
        //printf("--%s",cadena);
        if(cadena[0]==':'){
            // printf("%i :\n",id);
            obtener_puntos(cadena,pts);
            obtener_codigo(cadena,pts,&id);
            obtener_nombre(cadena,pts,&id);
            id++;
        }

        else{
            printf("Formato del fichero incorrecto\n");
        }
    }


    fclose(archivo);
    return id;

}

void obtener_codigo(char *cadena, int *pts,int *id){
    int num,x,p=0;
    int y=*id;
    char variable[10],cadena2[256];
    strcpy(cadena2,cadena);
    cadena2[pts[2]]='\0';
    //   printf("lector: %s-%i \n",cadena2,pts[2]);


    for(x=pts[1];x<pts[2];x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            //   printf("lector: %s\n",variable);
            p++;
        }
    }
    //printf("lector: %s-",variable);
    num=atoi(variable);
    lector[y].codigo=num;
}

void obtener_nombre(char *cadena, int *pts,int *id){
    int num = 0, x=0;
    int y = *id;
    char cadena2[81];
    strcpy(cadena2, cadena);
    cadena2[pts[3]] = '\0';

//	printf("%s\n",cadena2);

    for (x = pts[2]; x < strlen(cadena2); x++) {
        if (cadena2[x] != ':') {
            cadena2[num] = cadena2[x];
            num++;
            //	printf("%c",cadena2[x]);
        }
    }
    //printf("\n");
    cadena2[num] = '\0';
    // printf("----%s \n",cadena2);
    strcpy(lector[y].nombre, cadena2);
}

int obtener_puntos(char *cadena,int *pts){
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

void actualizar_txt (int *limite){
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
