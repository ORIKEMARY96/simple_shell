#include "main.h"

/**
 * repeated_char - counts the number of chars inputed
 * @input: chars inputed
 * @i: the index
 * return: number of repeated chars
 */
int repeated_char(char *input, int i)
{
	if (input == NULL)
		return (0);
	if (*(input - 1) == *input)
		return (repeated_char(input -1, i +1));
	return (i);
}


/**
 * _syntax_error_prints - is a function that prints syntax error whwn found
 * @i: index
 * @datash: pointer to relevant data structure parameters
 * @input: input string
 * @bool: boolean control msg error
 * Return: nothing
 */
void _syntax_error_prints(shell_data *datash, char *input, int bool, int i)
{
	char *error, *msg, *msg2, *msg3, *counter;

	int len;

	if (input[i] == ';')
	{
		if (bool == 0)
		{
			msg = (input[i+ 1] == ';' ? ";" : ";");
		}
		else
		{
			msg = (input[i - 1] == ';' ? ";" : ";");
		}
	}
	if (input[i] == '|' || input[i] == '&)
	{
		msg = (input[i +1] == '|' ? "||" : "|");
		msg = (input[i + 1] == '&' ? "&&" : "&");
	}
	msg2 = ":syntax error" \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(counter);
	len += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, msg);
	_strcat(error, msg2);
	_strcat(error, msg3);
	_strcat(error, ";");
	_strcat(error, "\0");

	write(STDEER_FILENO, error, len);
	free(error);
	free(counter);
}

/**
 * _sep_op_error - find error syntax
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index error other 0
 */
int _sep_op_error(char *input, int i, char last)
{
	int count = 0;

	while(*input != '\0')
	{
		if (*input == ' ' || *input == '\t')
		{
			input++;
			i++;
			continue;
		}
	
	if (*input == ';')
	{
		if (last == '|' || last == '&' || last == ';')
			return (i);
	}
	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return i;
		if (last == '|' && (count == 0 || count > 1))
			return (i);
		count = repeated_char(input, 0);
		if (count == 0 || count > 1)
			return (i);
	}
	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);
		count = repeated_char(input, 0);
		if (count == 0 || count > 1)
			return (i);
	}
	input++;
	i++;
	last = *(input -1);
	}
}


/**
 * first_char - finds index of first character
 * @input: input string
 * @i: index
 * Return: -1 if error occurs or 0 otherwise
 */
int first_char(char *input, int *i)
{
	*i = 0;

	while (input[*i] != '\0')
	{
		if (input[*i] == ' ' || input[*i] == '\t')
		{
			(*i)++;
			continue;
		}
		if (input[*i] == ';' || input[*i] == '&')
			return (-1);
		break;
	}
	return (0);
}
