
#define LOG(a) fprintf(stderr,"[log] %s\n",a);

typedef unsigned char u8 ;

struct RAM  {
	u8 storage[0x100];
	u8 ins[0x200];
	int ip;
	u8 regs[10];
} r ;
typedef struct RAM RAM;




