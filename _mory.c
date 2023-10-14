#include "shell.h"

/**
 * bfree - write a function that frees a pointer
 * and NULLs the address
 * @ptr: is the address of the pointer to free.
 * Return: 1 if freed, otherwise return 0.
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
