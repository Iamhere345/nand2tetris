#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

void set_file(FILE* file) {
    current_file = file;
}

char* trim(char* str, size_t len) {

    int offset = 0;
    char* end;

    /*
    since these files were written with *windows*, they terminate with \r\n,
    meaning i have to handle the carriage return \r as well as the normal whitespace.
    \r resets the cursor back to the start of the line...
    */
    while (isspace((unsigned char) *str) || *str == '\r') {
        str++;
        offset++;
    }
    
    if (offset == len)
        return NULL;

    end = str + ((len) - offset);

    if (end != str) {
        while (end >= str && (isspace((unsigned char) *end) || *end == '\r')) {
            printf("removing whitespace char 0x%X\n", *end);
            end--;
        }
    }
    
    printf("malloc(%ld)\n", (end - str) + 1);

    char* new_str = malloc((end - str) + 1);
    memcpy(new_str, str, end - str);

    // either replaces the trailing \n with a \0 or adds a \0
    if (new_str[(end - str) - 1] == '\n') {
        new_str[(end - str) - 1] = '\0';
    }

    if (new_str[(end - str) - 2] == '\r') {
        printf("AAAAAAAA\n");
        new_str[(end - str) - 2] = '\0';
    }
    
    // if theres a \n the end of the string will be \0\0


    new_str[end - str] = '\0';

    printf("returning trimmed string\n");

    return new_str;

}

bool advance() {
    char* line;
    size_t len = 0;
    int offset = 0;
    static int lineno = 0;

    while ((line = fgetln(current_file, &len)) != NULL)
    {
        lineno++;
        offset = 0;

        if (line[0] == '\n') {
            printf("!! skipping empty line\n");
        }

        // skip left whitespace

        char* trimmed_line = trim(line, len);

        if (trimmed_line == NULL) {
            printf("skipping blank line\n");
            continue;
        }

        /*
        for (int i = 0; i < len; i++) {
            if (line[i] == ' ' || line[i] == '\t') {
                printf("removing whitespace (len %zu)\n", len);
                len--;
                offset++;
            } else if (line[i] == '\n' || i == len-1) {
                printf("skipping empty line\n");
                continue;
            } else {
                printf("%d no more whitespace", lineno);
                break;
            }
        }

        line += offset;

        // skip comments
        if (line[0] == '/' && line[1] == '/') {
            printf("skipping comment\n");
            continue;
        }

        // trim right whitespace
        for (int i = len; i >= 0; i++) {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
                len--;
            } else {
                break;
            }
        }
        */

        printf("(%d) found instruction: (_%s_)\n", lineno, trimmed_line);

        return true;
    }

    return false;
    
}

