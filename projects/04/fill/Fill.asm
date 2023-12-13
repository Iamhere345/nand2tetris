// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(LOOP)
@i
M=0

(CHECK_KEYBOARD)
@KBD
D=M

@FILL_WHITE
D;JEQ
@FILL_BLACK
D;JMP

(FILL_WHITE)

// check if loop is finished
@i
D=M
@8192       // length of screen map
D=D-A

@END
D;JEQ

// fill row segment
@SCREEN
D=A
@i
A=D+M
M=0

// increment i
@i
M=M+1

@FILL_WHITE
0;JMP

(FILL_BLACK)
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

@FILL_BLACK
A;JMP

//24755
(END)
@i
M=0
@LOOP
0;JMP