//Prototipo de array de struct para referencia.

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
}refe[5000];



int main(){
	//struct refencia refe[5];
	refe[0].signatura=12;
	refe[0].tipo='A';
	printf("%i %c",refe[0].signatura, refe[0].tipo='A');
	return 0;
}


