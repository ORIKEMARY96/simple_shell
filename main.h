#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * struct data - is a structure that contains relevant
 * data for building a simple shell
 * @input: string representing the command name
 * @args: array of string representing a command argument
 * @counter: number of arguments
 * @_environ: environment variable
 * @status: last status of the shell
 * @av: the argument vector
 * @pid: process ID of the shell
 */
typedef struct data
{
	char *input;
	char **av;
	char **args;
	int counter;
	char **_environ;
	char *pid;
	int status;
} shell_data;

ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t i);
int exec_line(shell_data *datash);
int is_current_dir(char *path, int *j);
char *is_which(char *cmd, char **_environ);
int executable(shell_data *datash);
int check_command_error(char *dir, shell_data *datash);
int cmd_exec_line(shell_data *datash);
char *_get_env(const char *name, char **environ);
int _env(shell_datash);
int first_char(char *input, int *i);
void _syntax_error_prints(shell_data *datash,
char *input, int bool, int i);
int _sep_op_error(char *input, int i, char last);
char *_copy_info_to_create(char *name, char *val);
int _setenv(shell_data *datash);
int _unsetenv(shell_data *datash);
void set_env(char *name, char *val, shell_data *datash);

void cd_dir(shell_data *datash);
void cd_to(shell_data *datash);
void cd_to_previous(shell_data *datash);
void cd_is_home(shell_data *datash);
int cd_shell(shell_data *datash);

void *_realloc(void *ptr, unsigned int old_size,
unsigned int new_size);
void _my_shell(shell_data *datash);
char *read_line(int *i_eof);
extern char **environ;
int _islower(int ch);
char *_strtok(char str[], const char *delim);
int cmp_char(char str[], const char *delim);
int _strlen(const char *s);
char *_strdup(const char *s);
void rev_string(char *s);
int *_strcmp(char *s1, char *s2);
int *_strspn(char *s, char *accept);
char *_strcat(char *dest, const char *src);
char *_strcpy(char dest, char *src);
char *remove_comment(char *rc);
int check_error(shell_data *datash, char *input);
int _isdigit(const char *s);

/**
 * struct sep_list_s - separator for a single linked list
 * @char type: the separator type ; | &
 * @next: pointer to the next node
 */
typedef struct sep_list_s
{
	char type;
	struct sep_list_s *next;
} sep_list;

sep_list *add_node_to_end(sep_list **head, char type);
void free_sep_list(sep_list **head);
void *add_nodes(sep_list **head_s, line_list_s **head_s, char *input);
void goto_next(sep_list **list, line_list **list_l, shell_data *datash);


/**
 * struct line_list_s - a single linked list for line
 * @line: the command line
 * @next: pointer to the next node
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

line_list *add_line_to_end(line_list **head, char *line);
void free_line_list(line_list **head);

/**
 * struct var_list_s - single linked list to store important variables
 * @len_val: length of the value
 * @val: value of the variable
 * @len_var: length of the variable
 * @next: pointer to the next node
 */
typedef struct var_list_s
{
	int len_val;
	char val;
	int len_var;
	struct var_list_s *node;
} var_list;

var_list *add_var_list_node(var_list **head, int len_val, char val, int len_var);
void free_var_list(var_list **head);
void check_env(var_list **head, char *in, shell_data *datash);
char *replaced_input(var_list **head, char *input, char *new_input , int nlen);
int check_vars(var_list **head, char *in, char *ij, shell_dat *datash);
char *rep_vars(char *input, shell_data *datash);

/**
 * struct builtin_s - structure for builtin commands arguments
 * @name: builtin comand names
 * @f: pointer to the data type
 */
typedef struct builtin_s
{
	char *name;
	int(*f)(shell_data *datash);
} builtin_t;
int (*get_builtin(char *cmd))(shell_data *datash);
#endif
