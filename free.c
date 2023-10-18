#include "shell.h"
/**
* my_free - Free memory allocated consist of array of strings
* @arg: array of string to be free
* Return: nothing
*/
void my_free(char **arg)
{
int index = 0;
/* while loop to check if element is null or not*/
while (arg[index])
{
free(arg[index]);
index++;
}
free(arg);
}
