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
int i = 0;
char *token;
char **tokens = malloc(sizeof(char *) * MAX_ARGS);
Tokenizer state = {NULL, NULL};

if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}

while ((token = strtok2(line, TOKEN_DELIMITERS, &state)) != NULL)
{
tokens[i] = token;
i++;
}
tokens[i] = NULL;
return (tokens);
}


/**
* strtok2 - Splits a string into an array of arguments.
* @str: Pointer to a null-terminated string that contains the command line.
* @delim: Pointer to a null-terminated string that contains the delimiters
* used to split the string.
* @state: Pointer to a Tokenizer struct that encapsulates the state of the
* tokenizer.
* Return: A pointer to the next token in the string, or NULL if there are
* no more tokens.
*/
char *strtok2(char *str, const char *delim, Tokenizer *state)
{
if (str != NULL)
{
state->last_str = str;
}
else if (state->last_token != NULL)
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
