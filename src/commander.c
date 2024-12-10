#include "../libs/miishell.h"
#include "functions/clear.c"

/**
* This function takes care of analysing our list of commands,
* loop through it and execute the respective function.
*
* After executing, the function returns 0 in case of failure,
* and 1 in case of success.
*
* @params: char* function, char** args
* @return int
*/ 
int execute(char* function, char** args)
{
    pid_t pid;
    int status;

    pid = fork();

    /**
    * The fork was not done correctly :(
    */  
    if(pid < 0)
    {
        perror("Could not create fork on execute() !");
    }

    if(pid == 0)
    {
        ((int (*) (void)) &clear)();
    } else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}
