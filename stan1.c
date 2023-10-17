#include "shell.h"

/**
 * _strlen - a function that returns the len of a string.
 * @s: the string whose len to check.
 * Return: int len of string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - a function that performs lexicogarphic comparison of two strings.
 * @s1: the first string.
 * @s2: second string.
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - a function that checks if needle starts with haystack
 * @haystack: a string to search.
 * @needle: The substring to find.
 * Return: the addr of next character of haystack or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat -  function that concatenates two strings
 * @dest: Is the dest buffer.
 * @src: Is the src buffer.
 * Return: a ptr to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
