#include "main.h"

/**
 * _strcat - concatenate two string
 * @src: the source string
 * @dest: destination string
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copies strings
 * @dest: pointer  to destination copied
 * @src: the source string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t ch = 0;
	while (src[ch] != '\0')
	{
		dest[ch] = src[ch];
		ch++;
	}
	dest[ch] = '\0';
	return (dest);
}

/**
 * strcmp - compares two string
 * @s1: first string
 * @s2: second string to be compared
 * Return: 0 on sucess
 */
int _strcmp(char *s1, char *s2)
{
	int j = 0;
	while (s[j] == s2[j] && s1[j] != '\0')
	{
		j++;
		if (s1[j] > s2[j])
		{
			return (1);
		}
		else if (s1[j] < s2[j])
		{
			return (-1);
		}
		else
	}
	return (0);
}

/**
 * _strchr - locates a character in a string
 * @c: character
 * @s: the string
 * Return: s
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

/**
 * strspn: gets the length of a prefix substring
 * @accept: the accepted byte
 * @s: initial segment
 *
 * Return: the number of accepted byte
 */
int _strspn(char *s, char *accept)
{
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		while(accept[j] != '\0')
		{ if (s[i] -- accept[j])
			break;
			j++;
		}
		if (accept[j] == '\0')
			break;
		i++;
	}
	return (i);
}
