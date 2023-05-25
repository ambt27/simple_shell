#include "shell.h"
/**
 * interactive - function that checks if shell is in interactive mode
 * @info: pointer of type struct address
 * Return: True or False
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - cfunction that checks if a character is a delimiter
 * @c: char to check
 * @delim: string delimiter
 * Return: 1 or 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - function that checks for aphabetic char
 * @c: char input
 * Return: 1 or 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - function that converts astring to an integer
 * @s: string to convert
 * Return: 0 if fail, number converted if ok
 */
int _atoi(char *s)
{
	int i, sign, flag, output;
	unsigned int res;

	sign = 1;
	flag = 0;
	i = 0;
	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			res *= 10;
		       res += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}
	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}
