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


#include "shell.h"
/**
 * custom_atoi - Converts a string to an integer.
 * @string: The string to be converted.
 * Return: The converted integer.
 */
int custom_atoi(const char *string)
{
int sign = 1;
int num = 0;

while (*string == ' ' || (*string >= '\t' && *string <= '\r'))
string++;

switch (*string)
{
case '-':
sign = -1;
string++;
break;

case '+':
string++;
break;
default:
break;
}

while (*string >= '0' && *string <= '9')
{
num = num * 10 + (*string - '0');
string++;
}

return (sign *num);
}
