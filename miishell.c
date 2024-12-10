#include "libs/miishell.h"
#include "src/machine.c"
#include "src/tokenizer.c"
#include "src/reader.c"
#include "src/commander.c"

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

        line = get_line();
        args = parse_line(line);
        
        execute("clear", args);

        free(line);
        free(args);
    } while(status);
}
