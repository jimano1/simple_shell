#include "shell.h"

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
 * _EOF - handles the End of File
 * @len: return value of getline function
 * @buff: buffer
 */
void _EOF(int len, char *buff)
{
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * main - Shell
 * Return: 0 on success
 */
int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, **arv;
	size_t size = 0;
	list_path *head = NULL;
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != -1)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitstring(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			char *value = _getenv("PATH");
				head = linkpath(value);
			char *pathname = _which(arv[0], head);
				f = checkbuild(arv);
			if (f)
			{
				f(arv);
				free(buff);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
		freearv(arv);
	}
	free_list(head);
	free(buff);
	return (0);
}
