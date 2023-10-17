#include "shell.h"

/**
 * bfree - a function that frees a ptr and NULLs the addr.
 * @ptr: addr of the ptr to free.
 * Return: 1 if freed, else return 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
