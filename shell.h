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

/* Definitions to write or read buffer */
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define READ_BUFFER_SIZE 1024

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

extern char **environment;

/**
 * struct listarr - singly linked list
 * @str: needed string
 * @num: the needed mnumber input
 * @next: points to the next node
 */
typedef struct listarr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct iteminfo - parameters are placeholder-arguements
 * pass into a function,allowing uniform prototype for
 * function pointer struct
 * @argv: an array of strings generated from arg
 * @arg: a string generated from getline with params
 * @path: a string path for the current command
 * @line_count: the error count
 * @argc: the argument count
 * @err_num: the error code for exit()s
 * @filename: the file name
 * @count_flag: if on count this line of input
 * @env: linked list local copy of environment
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_cd: environment changed
 * @status: the return status of the last excuted cmd
 * @cmd_buffer: address of pointer to cmd buffer if chained
 * @cmd_buffer_type: cmd type
 * @readdir: read line input
 * @hiscount: read the history line number count
 */
typedef struct iteminfo
{
	char *arg;
	int argc;
	char **argv;
	list_t *alias;
	char *path;
	unsigned int line_count;
	int err_num;
	int count_flag;
	char filename;
	list_t *env;
	list_t *history;
	char **environ;
	int env_cd;
	int status;

	int readdir;
	char **cmd_buffer;
	int cmd_buffer_type;
	int cmd_buffer_type;
	int hiscount;
} item_t;

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
	int (*func)(item_t *);
} builtin_info;

/* shell arguments loopin argsloop.c */
int hsh_loop(item_t *, char **);
int find_builtins(item_t *);
void find_prompt(item_t *);
void fork_prompt(item_t *);

/* parse cmd for execution and PATH */
int cmd_exe(item_t *, char *);
char *double_chars(char *, int, int);
char *cmd_path(item_t *, char *, char *);

/* file string01 */
void _puts(char *);
int _putchar(char);

/* errors to print to stderr */
int _fputchar(char c);
void _efputs(char *);
/* The asciitoi.c */
int terminal(item_t *);

/* file getuserinfo.c */
void clear_params(item_t *);
#endif
