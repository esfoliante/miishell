struct CommandFunction
{
    char* command;
    int (*builtin_func[])(char **);
};
