#include "shell.h"
/**
<<<<<<< HEAD
 * path_execute - Executes a command located in the system's path.
 * OWNED BY YAHYA & JAMAL
 * @command: Executes a command with the specified full path
 * @vars: pointer to struct of the variables
=======
 * path_execute - executes a command in the path
 * @command: full path to the command
 * @vars: pointer to struct of variables
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
 *
 * Return: 0 on succcess, 1 on failure
 */
int path_execute(char *command, vars_t *vars)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			print_error(vars, NULL);
		if (child_pid == 0)
		{
			if (execve(command, vars->av, vars->env) == -1)
				print_error(vars, NULL);
		}
		else
		{
			wait(&vars->status);
			if (WIFEXITED(vars->status))
				vars->status = WEXITSTATUS(vars->status);
			else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
				vars->status = 130;
			return (0);
		}
		vars->status = 127;
		return (1);
	}
	else
	{
		print_error(vars, ": Permission denied\n");
		vars->status = 126;
	}
	return (0);
}
/**
<<<<<<< HEAD
 * find_path - notice PATH variables
 * OWNED BY YAHYA & JAMAL
 * @env: An array containing environment variables.
=======
 * find_path - finds the PATH variable
 * @env: array of environment variables
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
 *
 * Return: pointer to the node that contains the PATH, or NULL on failure
 */
char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);
}
/**
<<<<<<< HEAD
 * check_for_path - examine if the command is present
 * in the system's PATH
 * OWNED BY YAHYA & JAMAL
 * @vars: The variables
=======
 * check_for_path - checks if the command is in the PATH
 * @vars: variables
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
 *
 * Return: void
 */
void check_for_path(vars_t *vars)
{
	char *path, *path_dup = NULL, *check = NULL;
	unsigned int i = 0, r = 0;
	char **path_tokens;
	struct stat buf;

	if (check_for_dir(vars->av[0]))
		r = execute_cwd(vars);
	else
	{
		path = find_path(vars->env);
		if (path != NULL)
		{
			path_dup = _strdup(path + 5);
			path_tokens = tokenize(path_dup, ":");
			for (i = 0; path_tokens && path_tokens[i]; i++, free(check))
			{
				check = _strcat(path_tokens[i], vars->av[0]);
				if (stat(check, &buf) == 0)
				{
					r = path_execute(check, vars);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (path_tokens == NULL)
			{
				vars->status = 127;
				new_exit(vars);
			}
		}
		if (path == NULL || path_tokens[i] == NULL)
		{
			print_error(vars, ": not found\n");
			vars->status = 127;
		}
		free(path_tokens);
	}
	if (r == 1)
		new_exit(vars);
}
/**
<<<<<<< HEAD
 * execute_cwd - Run the command in the current working directory
 * OWNED BY YAHYA & JAMAL
 * @vars: Pointer to a structure containing variables
=======
 * execute_cwd - executes the command in the current working directory
 * @vars: pointer to struct of variables
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
 *
 * Return: 0 on success, 1 on failure
 */
int execute_cwd(vars_t *vars)
{
	pid_t child_pid;
	struct stat buf;

	if (stat(vars->av[0], &buf) == 0)
	{
		if (access(vars->av[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				print_error(vars, NULL);
			if (child_pid == 0)
			{
				if (execve(vars->av[0], vars->av, vars->env) == -1)
					print_error(vars, NULL);
			}
			else
			{
				wait(&vars->status);
				if (WIFEXITED(vars->status))
					vars->status = WEXITSTATUS(vars->status);
				else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
					vars->status = 130;
				return (0);
			}
			vars->status = 127;
			return (1);
		}
		else
		{
			print_error(vars, ": Permission denied\n");
			vars->status = 126;
		}
		return (0);
	}
	print_error(vars, ": not found\n");
	vars->status = 127;
	return (0);
}
/**
<<<<<<< HEAD
 * check_for_dir - examine if the command is a part of a specified path.
 * OWNED BY YAHYA & JAMAL
 * @str: The command
=======
 * check_for_dir - checks if the command is a part of a path
 * @str: command
>>>>>>> c8002a93e95c69b91b5df0d74ddc8cde1ad358f7
 *
 * Return: 1 on success, 0 on failure
 */
int check_for_dir(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}
