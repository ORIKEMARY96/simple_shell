#include "main.h"

/**
 * _isdigit - defines a string when passed as a number
 *
 * @s: input string
 * Return: i if string is a num or 0 otherwise
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
		
		if (s[i] < '0' || s[i] > '9')
		{
			return (0);
		}
		return (1);
}

/**
 * rev_string - reverses string
 * @s: input string
 * Return: nothig
 */
void rev_string(char *s)
{
	int i, j;
	char tmp;
	int len = 0;

	while (s[len] != '\0')
		len++;
	for (i = 0, j = len - 1; i < j, i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
