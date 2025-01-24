#include <stdio.h>
#include <stdlib.h>

char*  miFuncion(a,b){
	int c = 135;
	double d = 1.4;
	double e = c + d;
	char *f = "prueba";
	int size0 = snprintf(NULL, 0, "%s%f", f, e) + 1;
	char *g = malloc(size0);
	sprintf(g,"%s%f", f, e);
	return g;
}

int main(void){
	char *A = "esto esta funcionando muy bien";

	return 0;
}
