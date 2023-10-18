#include "shell.h"
/**
* valid_cmd - check if command is valid to be executed
* @arg: array of strings of whole command
* @input_buff: a pointer to user input
* @exit_num: exit status for the "exit" command if provided.
* Return: 1 if valid else 0
*/
int valid_cmd(char **arg, char *input_buff, int exit_num)
{
if (builtin_func(arg, input_buff, exit_num))
{
return (0);
}
if (!search_path(arg))
{
fprintf(stderr, "Command not found: %s\n", arg[0]);
my_free(arg);
return (0);
}
return (1);
}
