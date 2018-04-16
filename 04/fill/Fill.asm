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

//@SCREEN
//D = A
//@PIXEL
//M = D - 1

(LOOP)
@SCREEN
D = A
@PIXEL
M = D-1
@KBD
D = M;
@BLACK
D;JNE

@WHITE
D;JEQ


(BLACK)
@PIXEL
A = M
M = -1
@PIXEL
M = M + 1
@24576
D = A
@PIXEL
D = D - M
@BLACK
D;JNE
@LOOP
0;JMP




(WHITE)

@PIXEL
A = M
M = 0
@PIXEL
M = M+1
@24576
D = A
@PIXEL
D = D - M
@WHITE
D;JNE

@LOOP
0;JMP
