

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


#include "schema.c"
#include "functions.c"

int main( int argc , char** argv , char** env ) {
	functions[FUNC_EXIT](NULL );
	return EXIT_SUCCESS;
}
