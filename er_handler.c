#include "shell.h"

/**
*handle_error - Prints an error message along with the error description
*@message: Pointer to a string that describes the error.
*Return: void.
*This function prints an error message to standard error along with the
*error description obtained from the "errno" global variable.
*/
void handle_error(char *message)
{
fprintf(stderr, "%s: %s\n", message, strerror(errno));
}
