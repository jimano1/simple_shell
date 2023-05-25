#include "shell.h"

/**
 * _puts - Writes a string a standard output
 * OWNED BY: YAHYA & JAMAL
 * @str: The string to be written
 *
 * Return: The number of characters printed, or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strdup - Restore  a pointer to a recently allocated,
 * space in the memory contain a copy of a string
 * @strtodup: a string to be duplicated
 *
 * Return: A pointer to the newly duplicated string,
 * or NULL if memory allocation fails
 */
char *_strdup(char *strtodup)
{
	char *copy;

	int len, i;

	if (strtodup == 0)
		return (NULL);

	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = strtodup[i];

	return (copy);
}

/**
 * _strcmp - Compares two strings
 * @strcmp1: The first string to be compared
 * @strcmp2: The second string to be compared
 *
 * Return: 0 if the strings are equal,
 * a value less than 0 if strcmp1 is less than strcmp2,
 *         a value greater than 0 if strcmp1 is greater than strcmp2
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _strcat - Concatenates two strings
 * @strc1: The first string
 * @strc2: The second string
 *
 * Return: A pointer to the concatenated string
 */
char *_strcat(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstring[i] = strc1[i];
	newstring[i] = '/';
	for (j = 0; j < len2; j++)
		newstring[i + 1 + j] = strc2[j];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}
/**
 * _strlen - Returns the length of a string
 * @str: The string to be measured
 *
 * Return: The length of the string
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
