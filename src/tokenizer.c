#include "../libs/miishell.h"
#include <stdio.h>
#include <stdlib.h>

#define TOKEN_SIZE 64
#define DELIMETERS " \t\n\r\a"

char** parse_line(char* line)
{
    int buffer_size = TOKEN_SIZE;
    int position = 0;

    char** tokens = malloc(sizeof(char) * buffer_size);
    char* token;

    if(!tokens)
    {
        fprintf(stderr, "miishell: error allocating memory on tokenizer");
        exit(EXIT_FAILURE);
    }

    /**
    * Get the token by the delimeters
    */ 
    token = strtok(line, DELIMETERS);

    while(token != NULL)
    {
        tokens[position] = token;
        position++;

        if(position >= buffer_size)
        {
            buffer_size += TOKEN_SIZE;
            tokens = realloc(tokens, sizeof(char) * buffer_size);

            if(!tokens)
            {
                fprintf(stderr, "miishell: error allocating memory on tokenizer");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIMETERS);
    }

    tokens[position] = NULL;

    return tokens;
}
