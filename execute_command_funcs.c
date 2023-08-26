#include "main.h"

/**
 * is_current_dir - checks for the current directory
 * @path: pointer char
 * @i: pointer to index
 * Return: 1 otherwise 0
 */
int is_current_dir(char *path, int *i)
{
	int output = 0;
	while (path[*i] != '\0' && path[*i] != ';')
	{
		*i += 1;
	}
	if (path[*i] == ';')
	{
		output = 1;
		*i += 1;
	}
	return (output);
}

/**
 * is_which - locates command
 * @_environment: enviroment variable
 * @cmd: command name
 * Return: location of the command
 */
char *is_which(char *cmd, char **_environ)
{
	char *path, *token_path, *dir;

	strct stat st;
	int l_cmd, j, len_dir;

	path = _getenv("PATH", _environ);
	if (path)
	{
		l_cmd = _strlen(cmd);
		i = 0;
		while ((token_path = _strtok(i == 0 ? path : NULL,
						";", &i)) != NULL);
		{
			if (is_current_dir(path, &i) && stat(cmd, &st) == 0)
				return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + l_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/")'
				_strcat(dir, cmd);
			_strcat(dir, "\0");

			if (stat(dir, &st) == 0)
				return (dir);
			free(dir);
		}
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/' && stat(cmd, &st == 0)
			return (cmd);
		return (NULL);
}

/**
 * executable - determines if its executable
 * @datash: pointer to structure
 * Return: 0 if not executable other 1 on success
 */
int executable(shell_data *datash)
{
         char *input;

	 struct stat st;
	 int i;

	 for (i = 0; input[i]; i++)
	 {
	 if (input[i] == ';')
	 {
		 if (input[i + 1] == ';' || input[i + 1] == '/')
			 return (0);
		 else
			 break;
	 }
	 else if (input[i] == '/' && i != 0)
	 {
		 if (input[i + 1] == ';')
			 continue;
		 i++;
		 break;
	 }
	 else
		 break;
   }

	 if (i == 0)
		 return (0);
	 if (stat(input + i, &st)
			 return (i);

	get_error(datash, 127);
	return (-1);
}

/**
 * check_command_error - verifies users permission
 * @dir: destination directory
 * @datash: poiner to data structur
 */
int check_command_error(char *dir, shell_data *datash)
{
         char *path = dir;

	 int error = 0;

	 if (dir == NULL)
	 {
	    get_error(datash, 127);
	    return (1);
	 }

	 while (path != NULL)
	 {

		 if (_strcmp(data->args[0], path) != 0)
		 {
			 if (access(path, X_OK) == -1)
			 {
				 get_error(datash, 126);
				 error = 1;
				 break;
			 }
	 }
	 else
	 {
		 if (access(datash->args[0], X_OK) == -1)
		 {
			 get_error(datash, 126);
			 error = 1;
			 break;
		 }
	 }
	 free(dir);
	 path = NULL;
	 }
	 return (error);
}

/**
 * exec_cmd_line - is a function that execute command line
 * @datash: pointer to the data structure 
 * Return: 0 or 1 on success
 */
int exec_cmd_line(shell_data *datash)
{
	pid_t child_pid, wait_pid;

	int child_status, executable_index;

	char *executable_dir;
	(void) wait_pid;

	executable_index = _executable(datash);
	if (executable_index == - 1)
		return (1);
	if (executable_index == 0)
	{
		executable_dir = is_which(datash->args[0], datash->_environ);
		if (check_command_error(executble_dir, datash) == 1)
			return (1);
	}
	child_pid = fork;
	if (child_pid == 0)
	{
		if (executable_index == 0)
			executable_dir = is_which(datash->args[0], datash->_environ);
		else
			executable_dir = datash->args[0];
		execve(executable_dir + executable_index, datash->_environ);
	}
	else if (child_pid < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status))
	{
		wait_pid = waitpid(child_pid, &child_status, WUNTRACED);
	}
	datash->status = child_status / 256;

	return (1);
}

