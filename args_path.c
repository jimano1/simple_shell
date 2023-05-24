#include "holberton.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];

	dest[i] = '\0';
	return (dest);
}

/**
 * args_path - Concatenates the arguments.
 * @parse: Array of strings to concatenate.
 * @new: Array of strings to append.
 *
 * Return: Pointer to the concatenated string or NULL.
 */
char *args_path(char **parse, char **new)
{
	char *total, **cat;
	int i, j, k;
	struct stat status;

	for (i = 0; new[i]; i++)
	{
		total = malloc(60);
		_strcat(total, new[i]);
		_strcat(total, "/");
		_strcat(total, parse[0]);

		if (stat(total, &status) == 0)
		{
			for (k = 0; parse[k] != NULL; k++)
			{
			}
			cat = malloc(sizeof(char *) * (k + 1));
			cat[k] = NULL;
			cat[0] = _strdup(total);

			for (j = 1; parse[j]; j++)
				cat[j] = _strdup(parse[j]);
			execute(cat);
			free(cat); /* Remember to free allocated memory */
			return (total);
		}
		free(total);
	}
	return (NULL);
}
