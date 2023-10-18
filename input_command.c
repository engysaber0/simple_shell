#include "shell.h"
/**
 * input_command - this func to read commands
 * from the user
 * @input: a pointer to pointer to the buffer to store
 * input of use
 * @size: a pointer to the buffer size
 * Return: num of input chars if found else -1 if failure
*/
ssize_t input_command(char **input, size_t *size)
{
/*this is sum of characters of the user input*/
ssize_t sum_of_char;

/*
 * getline func takes 3 parameters which is input
 * and it refers to the buffer that stores input &
 * size & stdin to read from the standard input
*/
sum_of_char = getline(input, size, stdin);
/*
 * this checks if there is any error in reading or
 * the buffer is full
*/
if (sum_of_char == -1)
{
if (!isatty(STDIN_FILENO))
return (-1);

free(input);
perror("getline()");
exit(EXIT_FAILURE);
}
if ((*input)[sum_of_char - 1] == '\n')
((*input)[sum_of_char - 1] = '\0');

return (sum_of_char);
}
