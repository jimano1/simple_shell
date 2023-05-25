#include "shell.h"

/**
 * make_env - Create the shell env from the env passed to the main
 * OWNED BY YAHYA & JAMAL
 * @env: passed to main
 *
 * Return: pointer to the new environment
 */
char **make_env(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}

/**
 * free_env - Free to the shell's env
 * OWNED BY YAHYA & JAMAL
 * @env: shell's the env
 *
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
