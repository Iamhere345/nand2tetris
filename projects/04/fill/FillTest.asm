@i

(LOOP)

// check if loop is finished
@i
D=M
@8192       // length of screen map
D=D-A

@DONE
D;JEQ

// fill row segment
@SCREEN
D=A
@i
A=D+M
M=-1

// increment i
@i
M=M+1

@LOOP
0;JMP

(DONE)
@DONE
0;JMP