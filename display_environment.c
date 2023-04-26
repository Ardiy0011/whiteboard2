#include "shell.h"
/**
 * print_environment - Prints all the environment variables present
 * in the system.This function includes the standard C library header
 * file "shell.h".It uses an external variable "environ" that is declared
 * in the "stdlib.h" header file.
 * This variable is a pointer to an array of strings, where each string
 * represents an environment variable
 * Return: None.
*/
void print_environment(void)
{
int i = 0;
while (environ[i])
{
printf("%s\n", environ[i]);
i++;
}}



/**
 * set_environment_variable - Sets a new value for an existing environment 
 * variable, or creates a new environment variable if it does not exist.
 * @args: Array of arguments
 * Return: Always 0
 */
int set_environment_variable(char **args)
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "setenv: Too few arguments\n");
return (1);
}
if (args[3] != NULL)
{
fprintf(stderr, "setenv: Too many arguments\n");
return (1);
}

if (setenv(args[1], args[2], 1) != 0)
{
perror("setenv");
return (1);
}
return (0);
}



/**
 * unset_environment_variable - Removes an environment variable with the given name.
 * @param name The name of the environment variable to remove.
 * @args: Array of arguments
 * Return: Always 0
 */
int unset_environment_variable(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "unsetenv: Too few arguments\n");
return (1);
}
if (args[2] != NULL)
{
fprintf(stderr, "unsetenv: Too many arguments\n");
return (1);
}

if (unsetenv(args[1]) != 0)
{
perror("unsetenv");
return (1);
}

return (0);
}
