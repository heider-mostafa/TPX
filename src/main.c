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

int main (void) {
  fprintf(stdout, "Bonjour!");
}

// REMEMBER: THIS IS NOT A REAL HOMEWORK!!! THIS IS JUST AN EXAMPLE. THE REAL HOMEWORK IS TP0!!!
