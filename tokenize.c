#include "shell.h"


/**
 * tokenize - tokenizes a buffer with a delimiter
<<<<<<< HEAD
 * OWNED BY YAHYA & JAMAL
=======
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = new_strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = _realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
