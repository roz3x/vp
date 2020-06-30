
#define FUNC_EXIT   0
#define FUNC_SET    3
#define FUNC_PRINT 45
#define FUNC_XCMP   9
#define FUNC_JMP   80
#define FUNC_MOV   99

void f_mov( RAM* r ) {
	LOG("mov command");
	u8 src,val;
	src = r->ins[r->ip++];
	val = r->ins[r->ip++];
	r->regs[src] = val;
	return;
}

void f_exit(RAM* r ) {
	LOG("exit command");
	exit(EXIT_SUCCESS);
}

void f_set(RAM* r ) {
	LOG("set command");
	u8 src,val;
	src = r->ins[r->ip++];
	val = r->ins[r->ip++];
	r->storage[src] = val;
	return;
}

void f_print(RAM* r) {
	LOG("print command");
	int i = r->regs[0];
	for (;i--;) 
		fprintf(stdout ,"storage[%d]:%d\n",i,r->storage[i]);
	r->ip++;
	return;
	
}

void f_xcmp(RAM* r){
	LOG("xcmp command");
	if (r->regs[1]<=r->regs[2])
		r->regs[4] = 3;
	else if (r->storage[(r->regs[1]+r->regs[2])/2] == r->regs[3]) 
		r->regs[4] = 1;
	else if (r->storage[(r->regs[1]+r->regs[2])/2]  > r->regs[3]) 
		r->regs[4] = 2;
	else 
		r->regs[4] = 0;
	r->ip++;
	return;

}

void f_jmp(RAM* r) {
	u8 res = r->regs[4];
	int j = (int)r->regs[5];
	switch (res) {
		case 1:
			LOG("found");
			return;
		case 2:
			r->regs[1] = (r->regs[1]+r->regs[2])/ 2 - 1;
			f_xcmp(r);
			break;
		case 0:
			r->regs[2] = (r->regs[1]+r->regs[2])/ 2 + 1;
			f_xcmp(r);
			break;
		case 3:
			LOG("not found");
			break;
	}
	return;
}

static void (*f[0xff])(RAM* r ) =  {
	[FUNC_SET] = f_set,
	[FUNC_EXIT]   = f_exit,
	[FUNC_PRINT]  = f_print,
	[FUNC_XCMP]   = f_xcmp,
	[FUNC_JMP]    = f_jmp,
};
