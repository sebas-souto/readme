//Prototipo de array de struct para referencia.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct referencia{
    int signatura;
    char tipo;
    char autor[51];
    char titulo[81];
    int anio;
    int votantes;
    int votos;
    int criticos;
    int lector;
    char opinion[81];
};

struct referencia refe[100];
void leer_referencia();
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
void opinions(char *cadena, int *id);
void lect(char *cadena, int *pts, int *id);
void opinion(char *cadena, int *pts, int *id);
int main(){
    //struct refencia refe[5];
    int x;
    leer_referencia();

    for(x=0;x<6;x++){
       // printf("%i %c %s %s %i %i %i %i\n",refe[x].signatura,refe[x].tipo,refe[x].autor,refe[x].titulo,refe[x].anio,refe[x].votantes,refe[x].votos,refe[x].criticos);
        printf("%i %s\n",refe[x].lector,refe[x].opinion);
    }
    return 0;
}


void leer_referencia(){

    char cadena[256];
    int id=0,id2=0;
    FILE *archivo;
    archivo = fopen("referencia.txt", "r");


    while(feof(archivo) == 0){

        fgets(cadena,sizeof(cadena),archivo);
        //id++;
       // printf("%s\n",cadena);

        if(cadena[0]==':'){
           // printf("%i :\n",id);
            datos(cadena, &id);
            id++;
        }

        else if(cadena[0]=='#'){
          //  printf("%i #\n",id);
           opinions(cadena,&id2);
            id2++;
        }
        else{
            printf("Formato del fichero incorrecto\n");
        }
    }


    fclose(archivo);

}
void opinions(char *cadena, int *id){
    int pts[10];//Array que indica en que posicion de la cadena esta los :
    int r=*id;
    puntos(cadena,pts);
    lect(cadena,pts,&r);
     opinion(cadena,pts,&r);

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
        if (cadena[x] != ':') {
            cadena2[num] = cadena2[x];

            num++;
        }
    }
    //  printf("%s\n",variable);
    strcpy(refe[y].titulo, cadena2);
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
    refe[y].anio=num;
}

void votantes(char *cadena, int *pts, int *id){
    int num,x,p=0;
    int y=*id;
    char variable[10],cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[7]]='\0';

    for(x=pts[6];x<strlen(cadena2);x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            p++;
        }
    }
    num=atoi(variable);
    refe[y].votantes=num;
}

void votos(char *cadena, int *pts, int *id){
    int num,x,p=0;
    int y=*id;
    char variable[10],cadena2[120];
    strcpy(cadena2,cadena);
    cadena2[pts[8]]='\0';
    for(x=pts[7];x<pts[8];x++){
        if(cadena2[x]!=':') {
            variable[p] = cadena2[x];
            p++;
        }
    }
    num=atoi(variable);
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
            variable[p] = cadena2[x];
            p++;
        }
    }
    num=atoi(variable);
    refe[y].criticos=num;
}

void lect(char *cadena, int *pts,int *id){
    int num,x,p=0;
    int y=*id;
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
    refe[y].lector=num;
}

void opinion(char *cadena, int *pts,int *id){
    int num = 0, x;
    int y = *id;
    char variable[80],cadena2[81];
    strcpy(cadena2, cadena);
    cadena2[pts[2]] = '\0';



    for (x = pts[1]; x < strlen(cadena2); x++) {
        if (cadena[x] != ':') {
            variable[num] = cadena2[x];

            num++;
        }
    }
     //printf("%s\n",cadena2);
    strcpy(refe[y].opinion, variable);
}