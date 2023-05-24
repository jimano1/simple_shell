#include "holberton.h"

/**
 * execute - execute the commands
 * @parse: char array of pointers
 *
 * Return: Always 0.
 */
int execute(char **parse)
{
	pid_t pid;
	int status;

	if (strcmp(parse[0], "exit") == 0) /* Check if the command is "exit" */
	{
		exit(0); /* Terminate the shell program */
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(parse[0], parse, NULL) == -1)
		{
			perror(parse[0]);
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
		perror("Error:");

	return (0);
}
