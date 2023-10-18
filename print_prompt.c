#include "shell.h"
/**
 * print_prompt - a func to print prompt in terminal
 * this func to write $ when it is called
 * to the standard output to indicate shell is ready
 * for input command
 * @prompt: the $ sign
 * Return: nothing
*/
void print_prompt(int prompt)
{
/*this is to avoid not using it*/
(void)prompt;
/*4 is to "\n" & "$" & " " & null*/
write(STDOUT_FILENO, "\n$ ", 4);
/*this is to force $ to be printed immediately*/
fflush(stdout);
}
