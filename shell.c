#include "main.h"

/**
 * remove_comment - simply removes comments from user input
 * @rc: pointer to string
 * Return: input
 */
char *remove_comment(char *rc)
{
	int j = 0, in_to = 0;

	while (rc[j] != '\0')
	{
		if (rc[j] == '#')
		{
			return (NULL);
		}
		j++;
	}
	if (rc[j -1] == ' ' || rc[j -1] == 't' || rc[j -1] == ';')
	{
		in_to = j;
	}
	if (in_to != 0)
	{
		rc = _realloc(rc, j, in_to + 1);
		rc[in_to] = '\0';
	}
	return (rc);
}
void _my_shell(shell_data *datash)
{

	char *input = NULL;

	int i_eof;

	int loop = 1;

	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = remove_comment(input);
			if (input == NULL)
				continue;
			if (check_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
	return;
}
