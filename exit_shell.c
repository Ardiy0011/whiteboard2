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
if (line != NULL)
{
free(line);
free_args(args);
if (input_stream != stdin)
fclose(input_stream);
exit(EXIT_SUCCESS);
}
return (0);
}
