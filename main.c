#include "shell.h"
/**
 * main - The entry point of the program.
 * @argc: the number of arguments passed to the program from the command line,
 * including the name of the program itself.
 * @argv: an array of strings containing the arguments passed to the program
 * from the command line.
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
