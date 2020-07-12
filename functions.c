
void f_mov( RAM* r ) {
	u8 src,val;
	src = r->ins[++r->ip];
	val = r->ins[++r->ip];
	L("mov command REGS[%d]:%d",src,val);
	r->regs[src] = val;
	return;
}

void f_exit(RAM* r ) {
	L("exit command");
	exit(EXIT_SUCCESS);
}

void f_set(RAM* r ) {
	u8 src,val;
	src = r->ins[++r->ip];
	val = r->ins[++r->ip];
	L("set command DATA[%d]:%d",src,val);
	r->storage[src] = val;
	return;
}

void f_print(RAM* r) {
	int i = 0;
	L("print command first %d",r->regs[7]);
	for (;i<=r->regs[7];i++) P("storage[%d]:%d regs[%d]:%d\n",i,r->storage[i],i,r->regs[i]);
	return;
	
}

void f_xcmp(RAM* r){
	L("xcmp command regs[1]:%d regs[2]:%d",r->regs[1],r->regs[2]);
	if (r->regs[1]<r->regs[2])
		r->regs[4] = 0;
	else if (r->storage[(r->regs[1]+r->regs[2])/2] == r->regs[3]) 
		r->regs[4] = 1;
	else if (r->storage[(r->regs[1]+r->regs[2])/2]  > r->regs[3]) 
		r->regs[4] = 2;
	else 
		r->regs[4] = 3;
	return;

}

void f_jmp(RAM* r) {
	u8 res  = r->regs[4];
	u8 des  = r->ins[++r->ip];
	switch (res) {
		case 1:
			L("found @%d",(r->regs[1]+r->regs[2])/2);
			return;
		case 2:
			r->regs[1] = (r->regs[1]+r->regs[2])/ 2 - 1;
			L("jmp back %d",des);
			r->ip-=des;
			break;
		case 3:
			r->regs[2] = (r->regs[1]+r->regs[2])/ 2 + 1;
			r->ip-=des;
			break;
		case 0:
			L("not found");
			break;
	}
	return;
}

static void (*F[0xff])(RAM* r ) =  {
	[FUNC_SET]    = f_set,
	[FUNC_EXIT]   = f_exit,
	[FUNC_PRINT]  = f_print,
	[FUNC_XCMP]   = f_xcmp,
	[FUNC_JMP]    = f_jmp,
	[FUNC_MOV]    = f_mov,
};
