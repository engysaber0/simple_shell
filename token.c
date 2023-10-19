#include "shell.h"
/**
 * token_strtok - tokenize a string based on delimiters
 * @pointer: string to be tokenized
 * Return: individual tokens as an array of strings
 */
char **token_strtok(char *pointer)
{
char **result = NULL;
char *sep = " \n\t", *tmp;
int is_space = 0;

tmp = strtok(pointer, sep);

while (tmp)
{
result = realloc(result, (is_space + 2) * sizeof(char *));
result[is_space] = malloc(strlen(tmp) + 1);
strcpy(result[is_space++], tmp);
tmp = strtok(NULL, sep);
}

result[is_space] = NULL;
free(tmp);
return (result);
}
