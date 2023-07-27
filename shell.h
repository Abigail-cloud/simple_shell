#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

/* Definitions to write or read buffer MACROS */
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define READ_BUFFER_SIZE 1024
#define BUFSIZE 1024
#define SHDELIM " \t\r\n\a"
#define LOG(c) (write(STDOUT_FILENO, c, _strlen(c)))

/* Definitions for number conversion*/
#define CON_LOWERCASE	1
#define CON_UNSIGNED	2

/* Definition for cmd chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* 1 if using the OS  getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

#define INFO_PROMPT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 * struct builtins - contains a builtin string functions
 * @func: the functions used
 * @type: the builtin command flag
 *
 */
typedef struct builtins
{
	char *type;
	int (*func)(char **line, int rt);
} builtin_info;

/* shell arguments PRINTING  argsloop.c */
void log_number(unsigned int n);
void log_number_in(int n);
void log_error(char *line, int c, char **argv);
void sh_prerror(char **argv, int c, char **cmd);


/* parse cmd for execution and PATH */

int cmd_path(char **line);
char *my_getenv(char *name);
char **parse_command(char *cmd);
int handle_sh_builtin(char **cmd, int rt);
void read_my_file(char *filename, char **argv);
char *let_build(char *token, char *value);
int check_builtin(char **cmd);
void create_env(char **envin);
int check_my_cmd(char **tokens, char *line, int count, char **argv);
void sh_file(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);




/* file string01 string007.c*/
char *_strtok(char *str, const char *item);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _ascitoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_istoi(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);


/*  The memory mamgement in OS*/

void free_env(char **env);
void *put_array(void *a, int element, unsigned int len);
char *_mempy(char *dest, char *src, unsigned int n);
void *is_calloc(unsigned int size);
void *is_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/* The  INPUT Function ######*/

void prompt(void);
void signal_handel(int sig);
char *sh_getline(void);


/* Biltin  Functions */

void sh_hashtag(char *buffer);
int is_history(char *input);
int _shhistory(char **cmd, int rt);
int sh_env(char **cmd, int rt);
int my_cd(char **cmd, int rt);
int display_help(char **cmd, int rt);
int sh_echo(char **cmd, int rt);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);
#endif
