# virtual processor

* the processor supports harvard architecture
* 10 regsiters 
* 255 bytes instruction buffer
* 255 bytes data buffer
* 6 instructions 


## instruction set 

```
-----------------------------------------
| SET   |                               |
|       | opcode  0                     |
|       | format  " SET index value "   |
|       | size    3 bytes               |
-----------------------------------------
| MOV   |                               |
|       | opcode  5                     |
|       | format  " MOV index value "   |
|       | size    3 bytes               |
-----------------------------------------
| XCMP  |                               |
|       | opcode  3                     |
|       | format  "XCMP"                |
|       | size    1 bytes               |
-----------------------------------------
| JMP   |                               |
|       | opcode  4                     |
|       | format  "JMP value"           |
|       | size    2 bytes               |
-----------------------------------------
| PRINT |                               |
|       | opcode  2                     |
|       | format  "PRINT"               |
|       | size    1 bytes               |
-----------------------------------------
| EXIT  |                               |
|       | opcode  1                     |
|       | format  "EXIT"                |
|       | size    1 byte                |
-----------------------------------------

```


# gui 
contains the sample code from the source file 
![gui](https://raw.githubusercontent.com/roz3x/vp/master/frontend/gui_sample.jpg)


# usage 

currently only   assembly input . the values can be fed via format shown in ```source.asm``` file. 
to run the pre-writen test 
```
source ./run.sh source.asm
```
for gui 
```
cd frontent && electron ./ele.js
```
and the result SHOULD look like ```LOG.md```


or just see the github build [pickle rick](https://github.com/roz3x/vp/runs/885633417?check_suite_focus=true)

# deps 
sed and gcc (and  electorn )
