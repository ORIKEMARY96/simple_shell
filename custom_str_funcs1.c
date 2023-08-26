#include "main.h"

/**
 * _strdup - dupicates a string
 * @s: pointer to char string
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	size_t len, i = 0;

	char *new;
	len = _strlen(s);

	new = malloc(sizeof(char) * (len + 1));
	if (new != NULL)
	{
		for (i = 0; i <= len; i++)
			new[i] = s[i];
	}
	return (new);
}

/**
 * _strlen - returns the length of a string
 * @s: the type char pointer
 * Return: 0 on success
 */
int _strlen(const char *s)
{
	int len;
	for (len = 0; s[len] != 0; len++)

		return (len);
}

/**
 * cmp_chars - compares chars of string
 * @str: the input string
 * @delim: delimiter
 * Return: 0 if equal or 1 otherwise
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (str[i] != '\0')
	{
		while (delim[j] != '\0')
		{
			if (str[i] == delim[j])
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

/**
 * _strtok - splits a string by delimiter
 * @str: input string
 * @delim: the delimiter
 * Return: splitted string
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *ste_end;

	char *str_start;
	unsigned int bool = 0;

	if (str != NULL)
	{ if (cmp_chars(str, delim))
		return (NULL);
		splitted = str;
		str_end = str + _strlen(str);
	}

	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	while (*splitted)
	{
		if (splitted != str_start && *splitted && *(splitted - 1) == '\0')
			break;
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++'
						break;
			}
		}
		if (bool == 0 &&*splitted)
			bool = 1;
		splitted++;
	}
	if (bool == 0)
	{
		return (NULL);
	}
	return (str_start);
}
