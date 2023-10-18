#include "shell.h"
/**
 * my_strcpy - Copy a string from source to dest
*@des: a pointer to the dest
*@sr: a pointer to the source string
*Return: copied string
*/
char *my_strcpy(char *des, char *sr)
{
int index = 0;

while (*(sr + index) != '\0')
{
*(des + index) = *(sr + index);
index++;
}
*(des + index) = '\0';
return (des);
}

/**
* my_strlen - num of chars in a string
* @str:  a pointer to string
* Return: num of chars
*/
int my_strlen(char *str)
{
int num_char = 0;
int index = 0;

while (*(str + index))
{
num_char++;
index++;
}
return (num_char);
}

/**
* my_strcat - to combine 2 strings
* @des: string
* @sr: string
* Return: a pointer to combined string
*/
char *my_strcat(char *des, char *sr)
{
int l = 0;
int index = 0;

while (des[l] != '\0')
{
l++;
}

while (sr[index])
{
des[l] = sr[index];
l++;
index++;
}
des[l] = '\0';
return (des);
}

/**
* my_strcmp - to compare two strings
* @str1: first string
* @str2: second string
* Return: the difference between the differing characters ASCII values
*/
int my_strcmp(char *str1, char *str2)
{
int index;

for (index = 0; str1[index] == str2[index]; index++)
{
if (!str1[index])
{
return (0);
}
}
return (str1[index] - str2[index]);
}
