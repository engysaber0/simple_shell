#include "shell.h"
/**
 * my_getline - a function to read a line from a fd
 * @buffer: a pointer to a pointer to store line
 * @buff_size: a pointer to the size of the buffer
 * @fd: the file descriptor that be read
 * Return: sum of read characters
*/
ssize_t my_getline(char **buffer, size_t *buff_size, int fd)
{
ssize_t sum_of_char = 0;
/*check if there is input or size*/
if (!buffer || !buff_size)
return (-1);

if (!(*buffer))
{
/* malloc as we don't know the size*/
*buffer = malloc(sizeof(char) * SIZE_IN);
/*check again that the allocation is successful or no*/
if (!(*buffer))
{
return (-1);
}
*buff_size = SIZE_IN;
}
sum_of_char = read(fd, *buffer, *buff_size);
if (sum_of_char == -1)
{
free(*buffer);
return (-1);
}
return (sum_of_char);
}
