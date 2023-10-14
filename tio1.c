#include "shell.h"

/**
 * interactive - function that returns true
 * if shell is interactive mode
 * @info: is the struct address
 * Return: 1 if interactive mode, otherwise return 0.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function that checks if char is a delimeter.
 * @c: the char to check.
 * @delim: the delimeter string.
 * Return: 1 if true, else 0.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function that checks for alphabetic char.
 *@c: The char to input.
 *Return: 1 if c is alphabetic, else 0.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function that converts a string to an int.
 *@s: is the string to be converted.
 *Return: 0 if no numbers in string, otherwise converted number.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
