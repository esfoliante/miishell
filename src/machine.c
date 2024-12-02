#include "../libs/miishell.h"

/**
 * This function takes care of getting the machines data
 * and put it in a struct Machine.
 *
 * @params: void
 * @return: struct Machine
 */ 
struct Machine get_machine_data(void)
{
    struct Machine machine;

    /**
      * Structs to get all the necessary data
      * related to our user (just so the 
      * shell is pretty enough to show :) )
      */ 
    struct passwd *pw;
    uid_t uid;

    char* hostname;

    uid = geteuid();
    pw = getpwuid(uid);

    if(!pw)
    {
        printf("ERROR: There was an error getting user's info");
        exit(EXIT_FAILURE);
    }

    machine.user = pw->pw_name;
    machine.hostname = pw->pw_shell;

    return machine;
}
