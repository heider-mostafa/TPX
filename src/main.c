#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/wait.h>

#define true 1
#define false 0
#define bool int

typedef int error_code;

#define ERROR (-1)
#define HAS_ERROR(code) ((code) < 0)
#define NULL_TERMINATOR '\0'

enum op {   //todo these are your custom shell operators. You might want to use them to represent &&, ||, & and "no operator"
    BIDON, NONE, OR, AND, ALSO    //BIDON is just to make NONE=1, BIDON is unused
};

struct command {    //todo you might want to use this to represent the different commands you find on a line
    char **call;
    enum op operator;
    struct command *next;
    int count;
    bool also;
};
//hint hint: this looks suspiciously similar to a linked list we saw in the demo. I wonder if I could use the same ideas here??

void freeStringArray(char **arr) {  //todo probably add this to free the "call" parameter inside of command
}

error_code readline(char **out) {   //todo this is pretty barebones, you must complete it
}

int main (void) {
    //todo
    char *line;
    readline(&line);    //todo what about error_code?
    if(strcmp(line, "exit") == 0) {
        free(line);
        exit(0);
    }
    while (true);

    //todo probably add other functions for different parts of the homework...
}