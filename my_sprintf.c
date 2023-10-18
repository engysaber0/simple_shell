#include "shell.h"
/**
* my_sprintf - Combines three strings
* @s1: first string
* @s2: second string
* @s3: third string
* Return: a pointer to combined string.
*/
char *my_sprintf(char *s1, char *s2, char *s3)
{
int l_s1;
int l_s2;
int l_s3;
char *combined;

l_s1 = strlen(s1);
l_s2 = strlen(s2);
l_s3 = strlen(s3);

combined = malloc((l_s1 + l_s2 + l_s3 + 1) * sizeof(char));
if (!combined)
{
perror("Error: malloc failed in _sprintf");
exit(EXIT_FAILURE);
}

strcpy(combined, s1);
strcat(combined, s2);
strcat(combined, s3);

return (combined);
}
