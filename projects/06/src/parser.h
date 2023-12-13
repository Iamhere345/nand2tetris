#include <stdio.h>
#include <stdbool.h>

static FILE* current_file;
static char* current_instruction;
static size_t instruction_len;


typedef enum {
    A_INSTRUCTION,
    C_INSTRUCTION,
    L_INSTRUCTION
} InstructionType;

// sets the input file to operate on
void set_file(FILE* file);

// Are there more lines in the input?
bool has_more_lines();

/*
skips over white space and comments, if necessary.

Reads the next instruction from the input, and makes it the current instruction.
The function should only be called if has_more_lines is true.
*/
bool advance();

/*
Returns the type of the current instruction

A_INSTRUCTION for @xxx, where xxx is either a decimal number or a symbol
C_INSTRUCTION for dest=comp;jump
L_INSTRUCTION for (xxx) where xxx is a symbol
*/
InstructionType get_instruction_type();

/*
If the current instruction is (xxx), returns the symbol xxx.
If the current instruction is @xxx, returns the symbol or decimal xxx (as a string).

Should be called only if get_instruction_type() is A_INSTRUCTION or L_INSTRUCTION.
*/
char* parser_symbol();

/*
Returns the symbolic dest part of the current C-instruction (8 possibilities).

Should be called only if the InstructionType is a C_INSTRUCTION.
*/
char* parser_dest();

/*
Returns the symbolic comp part of the current C-instruction (8 possibilities).

Should be called only if the InstructionType is a C_INSTRUCTION
*/
char* parser_comp();

/*
Returns the symbolic jump part of the current C-instruction (8 possibilities)

Should be called only if the InstructionType is a C_INSTRUCTION
*/
char* jump();

/*
utility function to trim leading and trailing whitespace from strings.
returns NULL if the string is only whitespace
*/
char* trim(char* str, size_t len);