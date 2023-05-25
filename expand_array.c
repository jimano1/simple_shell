#include "shell.h"

/**
 * _realloc - reselect a pointer to duplicate the space
 * OWNED BY YAHYA & JAMAL
 * @ptr: pointer to the earliest arrangement
 * @size: pointer to number of elements in the earliest arrangement
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new);
}
