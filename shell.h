#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: Directory in the path
 * @next: Pointer to the next node in the list
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_path;

char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);

/**
 * struct mybuild - Pointer to function with corresponding built-in command
 * @name: Name of the built-in command
 * @func: Function to execute the built-in command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **argv);
} mybuild;

void checkbuild(char **argv);
int _atoi(char *s);
void exitt(char **argv);
void env(char **argv);
void _setenv(char **argv);
void _unsetenv(char **argv);

void freearv(char **argv);
void free_list(list_path *head);

#endif

