```
	[LOG] set command DATA[0]:1
	[LOG] set command DATA[1]:20
	[LOG] set command DATA[2]:38
	[LOG] set command DATA[3]:39
	[LOG] set command DATA[4]:55
	[LOG] set command DATA[5]:100
	[LOG] set command DATA[6]:101
	[LOG] set command DATA[7]:111
	[LOG] mov command REGS[1]:8
	[LOG] mov command REGS[7]:8
	[LOG] mov command REGS[2]:0
	[LOG] mov command REGS[3]:100
	[LOG] print command first 8
	[LOG] xcmp command regs[1]:8 regs[2]:0
	[LOG] xcmp command regs[1]:8 regs[2]:5
	[LOG] jmp back 3
	[LOG] xcmp command regs[1]:5 regs[2]:5
	[LOG] found @5
	[LOG] exit command
	storage[0]:1 regs[0]:0
	storage[1]:20 regs[1]:8
	storage[2]:38 regs[2]:0
	storage[3]:39 regs[3]:100
	storage[4]:55 regs[4]:0
	storage[5]:100 regs[5]:0
	storage[6]:101 regs[6]:0
	storage[7]:111 regs[7]:8
	storage[8]:0 regs[8]:0

```
