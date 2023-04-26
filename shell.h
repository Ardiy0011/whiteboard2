#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>




#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"
#define BUFSIZE 1024
#define MAX_LINE_LENGTH 1024
#define MAX_INPUT_LENGTH 1024
extern char **environ;
#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 512



void prompt(void);
char *read_input();
int execute_command(char **args);
void handle_error(char *message);
int execute_command_args(char *command, char **args);
char **split_line(char *line);
void free_args(char **args);
int exit_shell(char *line, char **args, FILE *input_stream);
char *get_command_path(char *command);
void print_environment(void);

int unset_environment_variable(char **args);
int set_environment_variable(char **args);
char *strtok_r(char *str, const char *delim, char **saveptr);
void execute_commd(const char *command, char *const *args, const char *path);

#endif /* SHELL_H */
