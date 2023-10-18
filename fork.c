#include "shell.h"
/**
* execute_forked_cmd - Execute a command in a forked child process.
* @arg: Array of strings containing the command and its arguments.
* @input_buff: Pointer to the user input buffer.
* Return: Exit status of the executed command or -1 on failure.
*/
int execute_forked_cmd(char **arg, char *input_buff)
{
	pid_t prosid;
	int status, i;

	prosid = fork();
	if (prosid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (prosid == 0)
	{
		if (execute_cmd(arg, input_buff) == -1)
		{
			perror(input_buff);
			for (i = 0; arg[i] != NULL; i++)
			{
				free(arg[i]);
			}
			free(arg);
			free(input_buff);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
		perror("wait");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}
