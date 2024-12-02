#include "../libs/miishell.h"
#include <stdlib.h>

#define LINE_BUFFER 1024

/**
* This function takes care of reading a line
* introduced by the user in our shell
*
* @params: void
* @return: char*
*/ 
char* get_line(void)
{
    int buffer_size = LINE_BUFFER;
    int position = 0;
    int character;

    char* buffer = malloc(sizeof(char) * buffer_size);

    if(!buffer)
    {
        fprintf(stderr, "miishell: error allocating memory on reader");
        exit(EXIT_FAILURE);
    }

    /**
    * Read the characters one by one
    */ 
    while(1)
    {
        character = getchar();        

        if(character == EOF)
        {
            exit(EXIT_SUCCESS);
        }

        if(character == '\n')
        {
            buffer[position] = '\0';

            return buffer;
        }

        buffer[position] = character;
        position++;

        /**
        * In case we run out of space on our
        * buffer, we need to reallocate
        * memory, RRAAAAAHHH
        */ 
        if(position >= buffer_size)
        {
            buffer_size += LINE_BUFFER;
            buffer = realloc(buffer, buffer_size);

            if(!buffer)
            {
                fprintf(stderr, "miishell: allocation error on reader");
                exit(EXIT_FAILURE);
            }
        }
    }
}
