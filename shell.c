#include "shell.h"
/**
* main -  Entry point for the custom shell program.
*
* This function serves as the main loop of the custom shell. It displays a
* prompt to the user, reads their input, processes and executes commands,
* and continues in a loop until an error or termination signal is received.
* he shell supports built-in commands, external commands, and signal handling.
*
* Return: Always returns 0 on successful execution.
*/
int main(void)
{
	char *input_buff, **arg = NULL;
	size_t buff_size = 0, i;
	int exit_num = -1;

	while (666)
	{
		input_buff = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (input_command(&input_buff, &buff_size) == -1)
		{
			free(input_buff);
			break;
		}
		if (input_buff[0] == '\0')
		{
			free(input_buff);
			continue;
		}
		if (my_sp_tab(input_buff))
		{
			free(input_buff);
			continue;
		}
		arg = token_strtok(input_buff);
		if (!valid_cmd(arg, input_buff, exit_num))
		{
			free(input_buff);
			continue;
		}
		exit_num = execute_forked_cmd(arg, input_buff);
		if (arg != NULL)
		{
			for (i = 0; arg[i] != NULL; i++)
				free(arg[i]);
			free(arg);
		}
		free(input_buff);
	}
	return (0);
}
