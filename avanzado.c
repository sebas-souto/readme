//
// Created by soutov on 21/04/17.
//
#include <stdio.h>
#include <string.h>
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

/**********************************************************************************************************************/
struct lectores{
    int codigo;
    char nombre[256];

};

struct lectores lector[100];

void obtener_codigo(char *cadena, int *pts,int *id);
int leer_lector();
void obtener_nombre(char *cadena, int *pts,int *id);
int obtener_puntos(char *cadena,int *pts);
int comprobar_lector(char nombre[50], int *tamanio);
void asignar_id(char nombre[LONGITUD],int *limite);
void actualizar_txt (int *limite);


/**********************************************************************************************************************/
void listar_referencia(int longi);
void  dame_referencias(char refe,int tamanio);
void buscar_referencia(int tamanio);
void busca(char *cadena, int tamanio);
int compara_nombre(char *cadena,int tamanio);
int compara_titulo(char *cadena,int tamanio);
int compara(char *cadena1,char *cadena2);
void imprime_bus(int x);

/**********************************************************************************************************************/

void cambiar_lector(int tamanio_lector);
int encontrar(char *buscar, int tamanio);
void cambiar(int x,char *nuevo);



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

int main(){
    int longi=0,nombre,x;
    longi=leer_referencia();
    nombre=leer_lector();
    //listar_referencia(longi);

        //buscar_referencia(longi);
        cambiar_lector(nombre);

    return 0;
}

int leer_referencia(){

    char cadena[256];
    int id=0,id2=0;
    FILE *archivo;
    archivo = fopen("referencia.txt", "r");


    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){

        if(cadena[0]==':'){
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

/***********************************listar referencia******************************************************************/



void listar_referencia(int longi){
    char cadena[256];
    int tamanio=0;
    printf("L)Libros\nA)Articulos\n\nElige el tipo de referencia que quieres listar: ");
    fgets(cadena,sizeof(cadena),stdin);
    tamanio=strlen(cadena);
    printf("\n");

    if(tamanio>2) printf("\nTipo seleccionado no valido\n");

    else if(cadena[0]!='L'&& cadena[0]!='A'){
        printf("\nTipo seleccionado no valido.\n\n");
    }
    else {
        dame_referencias(cadena[0],longi);
    }


}
/*Buscamos en el struct las referencia que sean del tipo que buscamos y las imprimimos segun el formato especificado*/

void  dame_referencias(char letra,int tamanio){
    int x;
    for(x=0;x<tamanio;x++){


        if(refe[x].tipo==letra){

            printf("%i) %s. \"%s\" (%i)\n",refe[x].signatura,refe[x].autor,refe[x].titulo,refe[x].anio);
        }

    }
}

/****************************************buscar referencia*************************************************************/
void buscar_referencia(int tamanio){
    char cadena[256];
    int lon=0;
    printf("Dame la cadena de busqueda: ");
    fgets(cadena,sizeof(cadena),stdin);
    lon=strlen(cadena);


    if(cadena[0]=='\n') printf("\nCadena de busqueda vacia\n\n");

    else {
        printf("\n");
       busca(cadena,tamanio);

    }


}

void busca(char *cadena,int tamanio){
    int resultado=0;//vemos si la comparacion tuvo exito o no->1 exito ->0 no exito
    resultado=compara_nombre(cadena,tamanio);
    if(resultado==0){
        return;
    }
    resultado=compara_titulo(cadena,tamanio);
    if(resultado==0){
        return;
    }
    else{
        printf("\nNinguna referencia contiene la cadena buscada\n");
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
       // printf("%s---%s---%i\n",cad,p1,correcto);
        if (correcto==0) break;
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

/*******************************Cambiar lector*************************************************************************/
void cambiar_lector(int tamanio_lector){
    char buscar[256];
    char nuevo[256];
    int lon=0,x;
    int sigue=1;
    while(sigue==1) {
        printf("Dame el texto de busqueda: ");
        fgets(buscar, sizeof(buscar), stdin);

        if (buscar[0] == '\n') printf("\nCadena de busqueda vacia\n\n");
        else sigue=0;
    }
    sigue=1;
    while(sigue==1) {
        //   printf("\n");
        printf("\nDame el nuevo texto: ");
        fgets(nuevo, sizeof(nuevo), stdin);
        if (nuevo[0] == '\n') printf("\nCadena de busqueda vacia\n\n");

        else {
            buscar[strlen(buscar) - 1] = '\0';
            nuevo[strlen(nuevo) - 1] = '\0';
            for (x = 0; x < strlen(nuevo); x++) {
                if (nuevo[x] == ':') {
                    printf("Caracter invalido\n");
                  //  return;
                }

            }
            //  printf("%s --> %s\n", buscar, nuevo);
            lon = encontrar(buscar, tamanio_lector);
            if (lon != -1) {
                cambiar(lon, nuevo);
                sigue=0;
            }

        }

    }
}

int encontrar(char *buscar, int tamanio){
    int correcto,x=0,y,inicio=0,fin=strlen(buscar);

    for(x=0;x<tamanio;x++){//Referemos el struct
        correcto=compara(buscar,lector[x].nombre);

        if(correcto==0) {

             printf("Encontrado: %i) %s\n",lector[x].codigo,lector[x].nombre);
            correcto=x;
            return correcto;
        }
        else{
            correcto=-1;
           // return correcto;
        }

    }

    return correcto;
}

void cambiar(int x,char *nuevo){
    char confirmar[256]; int p=0, sigue=0;
    while(sigue==0) {
        printf("Quieres cambiar a este lector? (s/n):");
        fgets(confirmar, sizeof(confirmar), stdin);
        if (confirmar[0] == '\n'|| confirmar[0]=='\0') {
            sigue=0;
        }
        if (strlen(confirmar) < 2) sigue=0;

        if (confirmar[0] == 'N' || confirmar[0] == 'n') sigue=0;
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
/**********************************************************************************************************************/

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

int leer_lector(){

    char cadena[256];
    int pts[256];
    int id=0;
    FILE *archivo;
    archivo = fopen("lectores.txt", "r");

    while(fgets(cadena,sizeof(cadena),archivo)!=NULL){

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