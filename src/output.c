#include <stdio.h>
#include <stdlib.h>

int main(void){
	int variableA = 1;
	double variableB = 2.5;
	char *variableC = " hola mundo";
	double suma = variableA + variableB;
	int size0 = snprintf(NULL, 0, "%f%s", suma, variableC) + 1;
	char *sumaTexto = malloc(size0);
	sprintf(sumaTexto,"%f%s", suma, variableC);
	printf("%s", sumaTexto);

	return 0;
}
