

#include <stdio.h>
#include <stdint.h>

#include "._a.c"


int main ( int argc , char *argv[] , char** env ) {
	FILE *f = fopen(argv[1],"wb");
	int i = 0; 
	for (i=0;i<sizeof(arr)/sizeof(arr[1]);i++){
		arr[i] = arr[i]&0x0f;
		switch (arr[i]){
			case 0:
				break;
			case 1:
				i+=2;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				i+=1;
				break;
			case 5:
				i+=2;
				break;
			case 6:
				break;
		}
	}
	fwrite(arr,sizeof(arr),1,f);
	fclose(f);
	return 0;
}