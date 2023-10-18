#include "shell.h"
#define TK_DEMR " \t\r\n\a\""

/**
 * exit_err - Function that print is error
 * @my_prog: Programe name is "MY_prog"
 * @counter: Counter command
 * @er_line: my line
 * Return: .
*/
void exit_err(char *counter, char *my_prog, char *err_line)
{
	char *tokens;

	strtok(err_line, TK_DEMR);
	write(2, my_prog, my_strlen(my_prog));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, err_line, (int)strlen(err_line));
	write(2, ": ", 2);
	write(2, "Illegal number", sizeof("Illegal number:") - 1);
	write(2, ": ", 2);
	tokens = strtok(NULL, TK_DEMR);
	write(2, tokens, (int)strlen(tokens));
	write(2, "\n", 1);
}
