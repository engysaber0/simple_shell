#include "shell.h"

/**
 * er_num - number of string
 *
 * @v: parameter is integer
 *
 * Return: number to string
 */

char *er_num(int v)
{
char *sc;
int len = 0, calc =0;
unsigned int s, count;

s = v;
count = 1;

while (s > 9)
{
	s = s / 10;
	count = count * 10;
	len++;
}
	len++;
sc = malloc((len +1) *sizeof(char));
if (sc == NULL)
	return (NULL);
count = 1;
do
{
sc[calc++] = ((v / count) % 10) + '0';
count = count * 10;
}while (count <= s * 10);

sc[len] = '\0';
	return (sc);
}
