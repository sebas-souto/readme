//Emitir voto
/*VALE ESTO SERIA UNA POSIBLE SOLUCION, FUNCIONA PERFECTAMENTE SIN EMBARGO A LA HORA DE IMPLEMERTARLO CUANDO LO EJECUTAS
LA PRIMERA VEZ PERFECTO SIN EMBARGO LA SEGUNDA NO ACTUALIZA EL TXT BIEN.*/

/*NOTA: APESAR DE QUE SEA UN SOLUCION NO NOS VALE USAR EL FSCANF NI SCANF HAY QUE CAMBIARLO. TIENES QUE PENSAR EN QUE PASA 
SI METE MUCHOS CARACTERES O COSAS RAR, QUE ES LO QUE HARAN CON LA BATERIA DE PRUEBAS.*/
#include <stdio.h>
void emitir_voto();

int main(){
	emitir_voto();
	return 0;
}

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
