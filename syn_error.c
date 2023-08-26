#include <main.h>

/**
 * check_error: - function to check and print error
 * @datash: data structure
 * @input: string input
 * Return: 0 on success
 */
int check_error(shell_data *datash, char *input)
{
	int start = 0;
	int j = 0;
	int r_char = 0;

	r_char = first_char(input, &start);

	if (r_char == -1)
	{
		_syntax_error_prints(datash, input, start, 0);

		return (1);
	}
	j = _sep_op_error(input + begin, 0, *(input + begin));
	if (j != 0)
	{
		_syntax_error_prints(datash, input, begin + j, 1);
		return (1);
	}
	return (0);

}

/**
 * get_error - calls error
 * @datash: data structure
 * @eval: error value
 * Return: error
 */
int get_error(shell_data *datash, int eval)
{
	if (datash == NULL)
	{
		return (-1);
	}
	switch (eval)
	{
		case -1;
		printf("Error: args missing.\n");
		break;
		case -2:
		printf("Error: invalid command.\n");
		default:
		printf("Error: Unknown error. \n");
		brek;
	}
	return (eval);
}
