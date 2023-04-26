#include "shell.h"


/**
 * find_executable - searches for the full path to an executable file in the
 * directories listed in the PATH environment variable.
 * @command: the name of the command to search for
 * @path: the value of the PATH environment variable
 * Return: a pointer to a string containing the full path to the executable if
 * it is found, otherwise NULL.
 */
char *find_executable(const char *command, const char *path)
{
char *p, *token, *exe_path;
char *path_copy = strdup(path);
char *saveptr;
if (!path_copy)
{
fprintf(stderr, "Error: strdup failed\n");
exit(EXIT_FAILURE);
}

exe_path = malloc(MAX_PATH_LENGTH * sizeof(char));
if (!exe_path)
{
fprintf(stderr, "Error: malloc failed\n");
free(path_copy);
exit(EXIT_FAILURE);
}
token = strtok_r(path_copy, ":", &saveptr);
while (token)
{
snprintf(exe_path, MAX_PATH_LENGTH, "%s/%s", token, command);
if (access(exe_path, X_OK) == 0)
{
free(path_copy);
return (exe_path);
}
token = strtok_r(NULL, ":", &saveptr);
}
free(exe_path);
free(path_copy);
return (NULL);
}
