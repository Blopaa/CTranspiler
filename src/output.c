#include <stdio.h>
#include <stdlib.h>

int main(void){
	char *variableA = "hola mundo";
	double entero = 1.34;
	int decimal = 143;
	int size0 = snprintf(NULL, 0, "%f%s", entero, variableA) + 1;
	char *suma = malloc(size0);
	sprintf(suma,"%f%s", entero, variableA);
	double resta = entero - decimal;
	double multiplicacion = entero * decimal;
	double division = entero / decimal;
	int size1 = snprintf(NULL, 0, "%f%s", division, variableA) + 1;
	char *algo = malloc(size1);
	sprintf(algo,"%f%s", division, variableA);
	printf("%s", suma);
	printf("%s", algo);

	return 0;
}
