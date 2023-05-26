#include "shell.h"

/**
<<<<<<< HEAD
 * _realloc - reselect a pointer to duplicate the space
 * OWNED BY YAHYA & JAMAL
 * @ptr: pointer to the earliest arrangement
 * @size: pointer to number of elements in the earliest arrangement
=======
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
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
