#include "shell.h"
/**
* builtin_func - Handle shell built-in commands (func)
* @arg: Array of strings containing the command and its arguments.
* @input_buff: Pointer to the user input buffer.
* @exit_num: Exit status for the "exit" command if provided.
* Return: 1 else 0
*/
int builtin_func(char **arg, char *input_buff, int exit_num)
{
char **env;
int exit_sta = EXIT_SUCCESS;
int index;

if (strcmp(arg[0], "exit") == 0)
{
if (arg[1])
exit_sta = atoi(arg[1]);
else if (exit_num != -1)
exit_sta = exit_num;
for (index = 0; arg[index]; index++)
{
free(arg[index]);
arg[index] = NULL;
}
free(arg);
free(input_buff);
exit(exit_sta);
}
else if (strcmp(arg[0], "env") == 0)
{
for (env = environ; *env; ++env)
printf("%s\n", *env);
my_free(arg);
return (1);
}
return (0);
}
