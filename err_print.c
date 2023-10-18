#include "shell.h"

/**
 * err_prints- Function that print error
 * @my_prog: Programe_name
 * @counting: Counting thits commands
 * @stats: Stat of process
 * @err_line: The line
 * Return: .
*/
void err_prints(char *my_prog, int counting, int stats, char *err_line)
{
	char *counter;

	counter = er_num(counting);
	if (stats == 126)
		err_path(my_prog, counter, err_line);
	if (stats == 127)
		err_command(my_prog, counter, err_line);
	if (stats == 2 && (strncmp(err_line, "exit", 4) == 0))
		exit_err(my_prog, counter, err_line);
	free(counter);
}
