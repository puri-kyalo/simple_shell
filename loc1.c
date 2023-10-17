#include "shell.h"

/**
 **_memset - function that fills mem with a constant byte.
 *@s: is the pointer to the mem area.
 *@b: byte to fill *s with.
 *@n: Amount of bytes to be filled.
 *Return: (s) a pointer to the mem area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - A function that frees a string of str
 * @pp: string of strings.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - a funtion that reallocates a block of mem.
 * @ptr: a ptr to previous malloc'ated block.
 * @old_size: The byte size of previous block.
 * @new_size: the byte size of new block
 * Return: a ptr to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
