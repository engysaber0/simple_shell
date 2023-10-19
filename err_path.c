#include "shell.h"

/**
 * err_path - Function that print error
 * @my_prog: Programe_name
 * @counter: Count commands
 * @err_line: The line
 * Return: .
*/
void err_path(char *counter, char *my_prog, char *err_line)
{
	write(2, my_prog, my_strlen(my_prog));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, err_line, (int)strlen(err_line));
	write(2, ": ", 2);
	write(2, "Permission denied", sizeof("Permission denied") - 1);
	write(2, "\n", 1);
}
