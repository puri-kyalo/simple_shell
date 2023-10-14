#include "shell.h"

/**
 **_strncpy - function that copies a string
 *@dest: is the dest string to be copied to
 *@src: source string.
 *@n: amount of chars to be copied.
 *Return: concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (j < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - function that concatenates two strings
 *@dest: first string.
 *@src: second string
 *@n: amount of bytes to be maximally used.
 *Return: concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a char in a string.
 *@s: is the string to be parsed.
 *@c: is the char to look for
 *Return: a pointer to the memory area s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
