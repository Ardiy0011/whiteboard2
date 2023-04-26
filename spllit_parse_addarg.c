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
char *token, *saveptr;
if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok_r(line, TOKEN_DELIMITERS, &saveptr);
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
}}
token = strtok_r(NULL, TOKEN_DELIMITERS, &saveptr);
}
tokens[position] = NULL;
return (tokens);
}


char *strtok_r(char *str, const char *delim, char **saveptr)
{
char *token;

if (str != NULL)
{
*saveptr = str;
}

token = *saveptr;
if (token == NULL)
{
return (NULL);
}
token += strspn(token, delim);

if (*token == '\0')
{
*saveptr = NULL;
return (NULL);
}

*saveptr = token + strcspn(token, delim);
if (**saveptr != '\0')
{
**saveptr = '\0';
(*saveptr)++;
}

return (token);
}
