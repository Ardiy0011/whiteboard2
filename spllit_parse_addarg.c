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
char *token;
char **tokens = malloc(sizeof(char*) * MAX_ARGS);

if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}

int i = 0;
Tokenizer state = {NULL, NULL};
while ((token = strtok2(line, TOKEN_DELIMITERS, &state)) != NULL)
{
tokens[i] = token;
i++;

if (i >= MAX_ARGS)
{
fprintf(stderr, "Too many arguments\n");
exit(EXIT_FAILURE);
}
}
tokens[i] = NULL;
return tokens;
}
char *strtok2(char *str, const char *delim, Tokenizer *state)
{
if (str != NULL)
{
state->last_str = str;
} else if (state->last_token != NULL)
{
state->last_str = state->last_token + strlen(state->last_token) + 1;
}
else
{
return (NULL);
}
state->last_token = strchr(state->last_str, *delim);
if (state->last_token != NULL)
{
*state->last_token = '\0';
state->last_token++;
}
return (state->last_str);
}
