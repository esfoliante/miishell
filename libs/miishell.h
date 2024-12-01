#ifndef MIISHELL_H
#define MIISHELL_H

#include <stdio.h>
#include <string.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>

#include "../src/structs/s_machine.c"

struct Machine get_machine_data(void);
void miishell(void);

#endif
