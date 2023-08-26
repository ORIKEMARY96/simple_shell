#include "main.h"

/**
 * read_line - is a function tha reads user input
 * @i_eof: pointer to the return value of getline function
 * Return: numbers of chars read
 */
char *read_line(int *i_eof)
{
	char *input;

	size_t bufsize = 0;

	input = malloc(sizeof(char) * bufsize);

	if (input == NULL)
	{
		*i_eof = get_line(&input, &bufsize, stdin);
	}

	return (input);
}
