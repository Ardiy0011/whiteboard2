#include "shell.h"

/**
 * exit_shell - Exit the shell program
 * @line: Pointer to the input line
 * @args: Array of arguments
 * @input_stream: Pointer to the input stream
 *
 * Return: Always 0
 */
int exit_shell(char *line, char **args, FILE *input_stream)
{
int exit_status = EXIT_SUCCESS;

if (args != NULL && args[1] != NULL)
{
exit_status = custom_atoi(args[1]);
}

if (args != NULL)
{
free_args(args);
}
if (line != NULL)
{
free(line);
}
if (input_stream != stdin)
{
fclose(input_stream);
}
exit(exit_status);
}
