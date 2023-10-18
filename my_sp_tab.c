#include "shell.h"
/**
* my_sp_tab - to check if  string contains of spaces or tab
* @str: pointer to user input
* Return: 0 if success or 1
*/
int my_sp_tab(char *str)
{
/* while loop to check if there are spaces or tabs in all input*/
while (*str)
{
/* if condition to check input*/
if (*str != ' ' && *str != '\t')
{
return (0);
}
/* to loop every word in string*/
str++;
}
return (1);
}
