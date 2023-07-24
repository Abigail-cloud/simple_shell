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

/* file string01 string007.c*/
void _puts(char *);
int _putchar(char);
char *my_strcpy(char *, char *);
char *my_strdup(const char *);

int my_strlen(char *);
int my_strcmp(char *, char *);
char *my_starts_with(const char *, const char *);
char *my_strcat(char *, char *);

/* errors to print to stderr, file descriptor buffer */
int _fputchar(char c);
void _efputs(char *);
int my_buffd(char c, int fd);
int my_puts(char *str, int fd);

int _erratoi(char *);
void print_error(item_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* The asciitoi.c */
int terminal(item_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


/* ohexits.c */
char *exits_strncpy(char *, char *, int);
char *exit_strncat(char *, char *, int);
char *exit_strchr(char *, char);

/* ontoken.c */
char **strtow(char *, char *);
char **on_strtow(char *, char);

/* myrealloc.c  osmemory.c  allocation*/
char *my_memset(char *, char, unsigned int);
void my_ffree(char **);
void *my_realloc(void *, unsigned int, unsigned int);

int osfree(void **);

/* file getuserinfo.c */
void clear_params(item_t *);
void set_params(item_t *, char **);
void free_params(item_t *, int);


/* mybuiltin.c */
int my_exit(item_t *);
int my_cd(item_t *);
int my_help(item_t *);

/* fillbuiltin01.c */
int my_history(item_t *);
int my_alias(item_t *);

/*getonline.c */
ssize_t get_sh_input(item_t *);
int get_sh_line(item_t *, char **, size_t *);
void get_intHandler(int);


/* The shell linked lists functions list01.c*/
list_t *add_new_node(list_t **, const char *, int);
list_t *add_last_node(list_t **, const char *, int);
size_t log_list_str(const list_t *);
int delete_node_position(list_t **, unsigned int);
void free_dlist(list_t **);

/* Data structure linked list contds list02.c */
size_t list_length(const list_t *);
char **list_str(list_t *);
size_t log_all_list(const list_t *);
list_t *list_starts_with(list_t *, char *, char);
ssize_t print_node_pos(list_t *, list_t *);

/* variables vars vary.c */
int get_chain(item_t *, char *, size_t *);
void prompt_chain(item_t *, char *, size_t *, size_t, size_t);
int swap_alias(item_t *);
int swap_vars(item_t *);
int swap_string(char **, char *);


/* shell  environment.c */
char *get_env(item_t *, const char *);
int sh_env(item_t *);
int sh_setenv(item_t *);
int sh_unsetenv(item_t *);
int popsh_env_list(item_t *);

/* shell environment   fetchenv.c */
char **fetch_environ(item_t *);
int my_unsetenv(item_t *, char *);
int sh_my_setenv(item_t *, char *, char *);

/* shell shhistory.c */
char *get_hist_file(item_t *params);
int copy_hist(item_t *params);
int read_hist(item_t *params);
int create_hist_list(item_t *params, char *buffer, int line_count);
int shuffle_hist(item_t *params);
#endif
