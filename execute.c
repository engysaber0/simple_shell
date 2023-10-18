#include "shell.h"
/**
* execute_cmd - Execute a command with its arguments.
* @arg: Array of strings containing the command and its arguments.
* @input_buff: Pointer to the user input buffer.
* Return: EXIT_SUCCESS if the command is executed successfully,
*	  EXIT_FAILURE if there's an error.
*/
int execute_cmd(char **arg, char *input_buff)
{
	char *path, *dirc;
	char search[4096];
	char cmd_path[4096];

	if (arg[0][0] == '/' || arg[0][0] == '.')
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror(input_buff);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			write(2, "PATH variable not found.\n", 25);
			exit(EXIT_FAILURE);
		}

		sprintf(search, "%s:/usr/bin", path);

		dirc = strtok(search, ":");
		while (dirc)
		{
			snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dirc, arg[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				if (execve(cmd_path, arg, NULL) == -1)
				{
					perror(input_buff);
					return (EXIT_FAILURE);
				}
			}
			dirc = strtok(NULL, ":");
		}
	}
	return (EXIT_SUCCESS);
}
