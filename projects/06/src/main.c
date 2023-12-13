#include <stdio.h>
#include "parser.h"

int main(int argc, char** argv) {

    // no args supplied
    if (argc < 2) {
        printf("input file expected (usage ./hasm <prog.asm>)\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("unable to open input file '%s'. exiting", argv[2]);
        fclose(file);
        return 1;
    }

    set_file(file);

    while(advance() != false) {

        /*
        InstructionType type = get_instruction_type();

        if (type == A_INSTRUCTION || type == L_INSTRUCTION) {
            char* symbol = parser_symbol();

            // do codegen stuff
        } else if (type == C_INSTRUCTION) {
            char* dest = parser_dest();
            char* comp = parser_comp();
            char* jump = parser_jump();

            // do codegen stuff
        }
        */
    }

    fclose(file);

    return 0;
}