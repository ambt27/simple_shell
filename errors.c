#include "shell.h"
/**
 * _eputs - function that prints an input string
 * @str: stringto be printed
 * Return: void
 */
void _eputs(char *str)
{
	int flag = 0;

	if (!str)
		return;
	while (str[flag] != '\0')
	{
		_eputchar(str[flag]);
		flag++;
	}
}
/**
 * _eputchar - function that writes the char c to stderr
 * @c: The char to print
 * Return: 1 if ok, -1 if nok
 */
int _eputchar(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}
/**
 * _putsfd - function that prints an input string
 * @str: string to be printed
 * @fd: filedescriptor to write
 * Return: number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
