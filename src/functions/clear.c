#include "../../libs/miishell.h"
#include <stdio.h>

/**
* This function simply takes care of imitating the 
* behabviour of the "clear" commad in any Unix
* based operating system, clearing the 
* terminal.
*
* @params: void
* @return: int
*/ 
int clear(void) {
    printf("\e[1;1H\e[2J");

    return 1;
}
