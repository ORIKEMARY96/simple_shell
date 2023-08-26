#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * bring_line - assigns line to be read
 * @lineptr: double pointer to store input
 * @buffer: array of chars
 * @n: pointer to size  of the line
 * @i: size of line
 * Return: nothing
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t i)
{
	if (lineptr == NULL || n == NULL || buffer == NULL)
		return;
	if (*lineptr != NULL)
	{
		free(*lineptr);

		*lineptr = NULL;
	}

	if (i > BUFSIZ || i < BUFSIZ)
	{
		*n = i;
	}

	*lineptr = buffer;
}


/**
 * process_line - reads lines from stream and process them
 * @lineptr: double pointer to store input
 * @buffer: pointer to arrays of chars
 * @n: pointer to store input
 * Return: nothing
 */
void process_line(char **lineptr,size_t *n, char *buffer)
{
	static ssize_t input;
	int i;

	char ch;

	char *new_buffer;

	while (ch != '\n')
	{
		i = read(STDIN_FILENO, &ch, 1);

		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return;
		}
		if (i == 0 && input != 0)
		{
			break;
			input++;
		}
		if (input >= BUFSIZ - 1)
		{
			new_buffer = realloc(buffer, *n + BUFSIZ);
			if (new_buffer == NULL)
			{
				free(buffer);
				return;
			}
			buffer = new_buffer;
			*n += BUFSIZ;
		}
		buffer[input] = ch;
		input++;
	}
	buffer[input] = '\0';
	strcpy(*lineptr, buffer);
	input += i;
}

/**
 * get_line - reads input from stream
 * @lineptr: double that stores the input
 * @n: size of lineptr
 * @stream: stream to read
 * Return: number of bytes read
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;

	char *buffer;

	do {
		fflush(stream);
	} while (input == 0);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZ);
	if (buffer == NULL)
	{
		return (-1);
	}
	bring_line(lineptr, n, buffer, BUFSIZ);
	process_line(lineptr, n, buffer);
	free(buffer);
	return (*n);
}
