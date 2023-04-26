#include "shell.h"

/**
 * split_line - Splits a string into an array of arguments.
 * @line: Pointer to a null-terminated string that contains the command line.
 * Return: Array of null-terminated strings containing the command arguments.
 * This function splits the command line into an array of arguments.
 * It returns an array of null-terminated strings containing the cmd arguments.
*/
char **split_line(char *line)
{
int bufsize = TOKEN_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, TOKEN_DELIMITERS);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += TOKEN_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOKEN_DELIMITERS);
}
tokens[position] = NULL;
return (tokens);
}
