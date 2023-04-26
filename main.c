#include "shell.h"
/**
 * main - The entry point of the program.
 * Return: Always 0
 */
int main(void)
{
char *input;
char **args;
int status;

while (1)
{
prompt();
input = read_input();
args = split_line(input);
if (strcmp(args[0], "exit") == 0)
break;
else if (strcmp(args[0], "env") == 0)
{
printf("Printing environment variables:\n");
print_environment();
}
else if (strcmp(args[0], "setenv") == 0)
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
}
else
{
int result = set_environment_variable(args[1], args[2]);
if (result != 0)
{
fprintf(stderr, "Failed to set environment variable\n");
}}}
else if (strcmp(args[0], "unsetenv") == 0)
{
if (args[1] == NULL)
{
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
}
else
{
int result = unset_environment_variable(args[1]);
if (result != 0)
{
fprintf(stderr, "Failed to unset environment variable\n");
}}}
else
{
status = execute_command(args);
}
free(input);
free(args);
if (status == -1)
{
break;
}}
return (0);
}
