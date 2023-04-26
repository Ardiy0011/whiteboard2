#include "shell.h"
/**
*read_input - Reads a line of input from standard input.
*Return: Pointer to a null-terminated string.
*This function reads a line of input from standard input using the fgets()
*function and stores it in a dynamically allocated buffer. The buffer is
*automatically resized if necessary to accommodate longer input lines. The
*newline character at the end of the input line is removed, if present.
*If there is no more input or an error occurs while reading from standard
*input, this function returns NULL.
*/
char *read_input()
{
char *input = malloc(MAX_INPUT_LENGTH);
int c, position = 0;
if (!input)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();

if (c == EOF || c == '\n')
{
input[position] = '\0';
return (input);
}
else
{
input[position] = c;
}
position++;
if (position >= MAX_INPUT_LENGTH)
{
fprintf(stderr, "input too long\n");
exit(EXIT_FAILURE);
}}}
