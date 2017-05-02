#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LONGITUD 50

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
//BASICAS--------------------------------------------
int incorporar_lector(int *limite);
//LECTOR---------------------------------------------
int comprobar_lector(char nombre[50], int *tamanio);
void asignar_id(char nombre[LONGITUD],int *limite);
//REFERENCIA-----------------------------------------
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

//programa
int main(){
    int longi=0,nombre=0;
	//longi=leer_referencia();
    nombre=leer_lector();
    int k;
    for (k=0;k<30;k++){
    	printf("%s",refe[k].criticos);}
	//incorporar_lector(&nombre);
    actualizar_lector(&nombre);
    actualizar_refe(&longi);

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
    archivo = fopen("referencia.txt", "r");

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
    int pts[10], r=*id;
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

