echo -ne 'uint8_t arr[] = { ' > .tmp.c ; cat s.asm | sed  -e 's/^#.*//g' \
	-e 's/MOV/99/g' \
	-e 's/SET/3/g' \
	-e 's/EXIT/0/g' \
	-e 's/PRINT/45/g' \
	-e 's/JMP/80/g' \
	-e 's/XCMP/9/g' \
	-e 's/\s/,/g' \
	-e '/^$/d' \
	-e 's/$/,/'  >> .tmp.c
echo -ne '0 } ;'  >> .tmp.c

gcc -o _b writer.c 
./_b asm.o

rm _b .tmp.c
