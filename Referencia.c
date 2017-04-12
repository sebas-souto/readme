//Prototipo de array de struct para referencia.
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

int main(){
    //struct refencia refe[5];
    int x,z, tamanio=0;
    tamanio=leer_referencia();
    agregar_referencia(&tamanio);
    actualizar_refe (&tamanio);
  //  printf("tamanio: %i\n",tamanio);
   /* for(x=0;x<tamanio;x++){
      printf("%i %c %s %s %i %i %i %i\n",refe[x].signatura,refe[x].tipo,refe[x].autor,refe[x].titulo,refe[x].anio,refe[x].votantes,refe[x].votos ,refe[x].criticos);
        //printf("criticos:%i\n",refe[x].criticos);
        for(z=refe[x].criticos;z>0;z--) {
           // printf("z:%i--x=%i--\n",z,x);
            printf("%i %s\n", refe[x].info[z].lector,refe[x].info[z].opinion);
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
    cadena2[strlen(cadena2)-5]='\0';
  //  printf("%s\n",variable);
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
  //printf("criticos:%i---y=%i\n",refe[y].criticos,y);
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
        fprintf(archivo,":%i:%c:%s:%s:%i:%i:%i:%i\n", refe[x].signatura, refe[x].tipo, refe[x].autor, refe[x].titulo,
               refe[x].anio, refe[x].votantes, refe[x].votos, refe[x].criticos);
        //printf("criticos:%i\n",refe[x].criticos);
         for (z = refe[x].criticos; z > 0; z--) {
            // printf("z:%i--x=%i--\n",z,x);
            fprintf(archivo,"#%i:%s:\n", refe[x].info[z].lector, refe[x].info[z].opinion);
        }


    }
    fclose(archivo);
}