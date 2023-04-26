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
}
}
