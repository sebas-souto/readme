//Agregar referencia
#include<stdio.h>
#include<string.h>
#define LONGITUD 50
void agregar_referencia();
void autor();
void titulo();
void year();
void tipo();
void imprimir();
int cadena_vacia(char cadena[LONGITUD]);
int main(){
	agregar_referencia();
	return 0;
}

void agregar_referencia(){
	
	autor();	
	titulo();
	year();
	tipo();

}



void autor(){
	int i,correcto,repetido;
	char refencia[LONGITUD];
	do{
		printf("Escribe el autor de la referencia: ");
		fgets(refencia,sizeof(refencia),stdin);
		correcto=1;
		i=0;
		
		if (cadena_vacia(refencia)){    				          //CADENA VACIA
			correcto=0;
			}
		else if (refencia[strlen(refencia)-1] != '\n'){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			imprimir(3);
			}
		else {                                            //CARACTER INVALIDO 
			while (i<strlen(refencia)){                 
				if (refencia[i]==':'){
					correcto=0;
					imprimir(1);
			    }
					i++;
			}
			
			    
		}	
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
	
}


void titulo(){
	int i,correcto,repetido;
	char title[LONGITUD];
	do{
		printf("Escribe el titulo: ");
		fgets(title,sizeof(title),stdin);
		correcto=1;
		i=0;
		
		if (cadena_vacia(title)){    				          //CADENA VACIA
			correcto=0;
			}
		else if (80<strlen(title)-1){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			imprimir(3);
			}
		else {                                            //CARACTER INVALIDO 
			while (i<strlen(title)){                 
				if (title[i]==':'){
					correcto=0;
					imprimir(1);
			    }
					i++;
			}
			
			    
		}	
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
}




void year(){
	int cadena [5],correcto=0,anio;
	do{
		printf("Escribe el anho: ");
		fgets(cadena,sizeof(cadena),stdin);
                anio=atoi(cadena);
		if((1470<anio)&&(anio<2017)){
			correcto=1;
		}
		
		else{
			imprimir(5);
			correcto=0;
		}
			
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
}
int cadena_vacia(char cadena[LONGITUD]){
	int resultado=0;
		if (cadena[0]=='\n'){    				          //CADENA VACIA
			imprimir(2);
			resultado=1;
		}
		else{
			resultado=0;
		}
		return resultado;
	
}
void tipo(){
	int i,correcto,repetido;
	char tipo[5];
	do{
		printf("Escribe el tipo: ");
		fgets(tipo,sizeof(tipo),stdin);
		correcto=1;
		i=0;
		
		if (cadena_vacia(tipo)){    		          //CADENA VACIA
			correcto=0;
			}
		else if (1<strlen(tipo)-1){       //LONGITUD CADENA EXCESIVA
			correcto=0;
			imprimir(3);
			}                                           //CARACTER INVALIDO 
		else if (tipo[0]=='A'||tipo[0]=='a'||tipo[0]=='L'||tipo[0]=='l'){                 
			
					correcto=0;
					imprimir(1);
		
			}
		else{
			correcto=1;
		}
			
			
				
	}while (correcto==0); //PIDE EL NOMBRE HASTA UNA INTRODUCCION CORRECTA	
	
}
void imprimir(int linea){
	char *errores[]={
	/*0*/   "\nError de formato en un fichero: “Linea mal formada en el fichero (NOMBRE_FICHERO)\n\n",
	/*1*/   "\nCaracter invalido\n\n",
	/*2*/   "\nCadena vacia\n\n",
	/*3*/   "\nLongitud de cadena excesivan\n\n",
	/*4*/   "\nLector repetido\n\n",
	/*5*/ "\nValor seleccionado incorrecto\n\n",
	/*6*/ "\nOperacion imposible en este momento\n\n",
	};
	
	printf("%s",errores[linea]);
}
