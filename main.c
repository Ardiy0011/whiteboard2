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
status = execute_command(args);
free(input);
free(args);
if (status == -1)
{
break;
}}
return (0);
}
