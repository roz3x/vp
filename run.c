

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


#include "schema.c"
#include "functions.c"

RAM r;

int main( int argc , char** argv , char** env ) {
	f[FUNC_EXIT](&r);
	return EXIT_SUCCESS;
}
