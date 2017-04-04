#include <stdio.h>

 
int main ( int argc, char **argv ){
 	FILE *fp;
 	
 	char buffer[256];
 	int num=0;
 	fp = fopen ( "lectores.txt", "r" );
 	
 	fscanf(fp, ":%i:%s:" ,&num,buffer);
 	printf("%i %s",num,buffer);
 	
 	fclose ( fp );
 	
 	return 0;
}
