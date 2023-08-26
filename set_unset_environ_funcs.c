#include "main.h"

/**
 * _setenv - compares env variables withe the passed name
 * @datash: pointer to data structure
 * Return: 1 0n success
 */
int _setenv(shell_data *datash)
{
	if (datash->arg[1] == NULL || datash->args[2] == NULL)
	{
		get_error(data, -1);
		return (1);
	}
	set_env(datash->args[1], datash->arg[2], datash);
	return (1);
}


/**
 * _unsetenv - delects environment
 * @datash: pointer to data structure
 * Return: 1 on sucess
 */
int _unsetenv(shell_data *datash)
{
	int i , j, k;
	char **realloc_environ;

	char *var_env, *name_env;

	if (data->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i =0; datash->_environ[i]; i++)
	{
		var_env = _strdup(data->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1] == 0))
		{
			k = i;
			break;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * i);
	for (j = 0, i = 0; datash->_environ[i]; i++)
	{
		if (i != k)
			realloc_environ[j] = datash->_environ[i];
		j++;
	}
	else
	{
		free(datash->_environ[i]);
	}
	realloc_environ[j] = NULL;
	free(datash->_environ);
	datash->_environ = realloc_environ;

	return (1);
}
