#include "main.h"

/**
 * copy_info_to_create - copies info to b created
 * as a new environ
 * @name: name env
 * @val: value of environ
 * Return: new environ
 */
char *copy_info_to_create(char *name, char val)
{
	char *new_string;

	int name_len, val_len, new_len, i, j;

	name_len = _strlen(name);
	val_len = _strlen(val);
	new_len = name_len + val+len + 2;

	new_string = malloc(sizeof(char) * new_len);
	if (new_string == NULL)
		return (NULL);
	for (i = 0; i < name_len; i++)
		new_string[i] = name[i];
	new_string[name_len] = '=';
	for (j = 0; j < val_len; j++)
		new_string[name_len + 1 + j] = val[j];
	new_string[name_len + 1 + val_len] = '\0';

	return (new_string);
}

/**
 * set_env - sets environ variable
 * @name: name of env
 * @val: env value
 * @datash: data structure
 * Return: nothing
 */
void set_env(char *name, char *value, shell_data *datash)
{
	int i = 0;
	char *env_var, *env_name;

	do
	{
		env_var = _strdrup(datash->_environ[i]);
		env_name = _strtok(env_var, "-");
		if (_strcmp(env_name, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_info_to_create(env_name, value);
			free(env_var);
			return;
		}
		free(env_var);
		i++;
	} while (datash->_environ[i]);

	datash->_environ = _realloc(datash->_environ, i, sizeof (char*) * (i + 2));
	datash->_environ[i] = copy_info_to_create(name, value);
	datash->_environ[i + 1] = NULL;
}
