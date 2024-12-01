#include "libs/miishell.h"
#include "src/machine.c"

void miishell(void)
{
    char* line;
    char** args;

    /**
      * this will helps us keep track of wether
      * we should stop the program or not.
      */
    int status = 1;
        
    struct Machine machine = get_machine_data();
    char* user = machine.user;

    do
    {
        printf("%s >> ", user);
    } while(status);
}
