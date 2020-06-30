

#include <stdio.h>
#include <stdint.h>

#include ".tmp.c"


int main ( int argc , char *argv[] , char** env ) {
	FILE *f = fopen(argv[1],"wb");
	fwrite(arr,sizeof(arr),1,f);
	fclose(f);
	return 0;
}

