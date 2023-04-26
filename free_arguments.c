#include "shell.h"

/**
* free_args - Frees an array of null-terminated strings.
* @args: Array of null-terminated strings.
* This function frees each string in the array and then frees the array itself.
*/
void free_args(char **args)
{
int i;
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}}
