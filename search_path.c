#include "shell.h"
/**
* search_path - Check if a command exists in the system's PATH.
* @arg: Array of strings containing the command and its arguments.
* Return: 1 if the command exists, 0 if it does not.
*/
int search_path(char **arg)
{
	char *path, *dirc;
	char search[4096];
	char cmd_path[4096];

	if (arg[0][0] == '/' || arg[0][0] == '.')
	{
		return (access(arg[0], X_OK) == 0);
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
				return (1);
			}
			dirc = strtok(NULL, ":");
		}
	}
	return (0);
}
