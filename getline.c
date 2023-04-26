#include "shell.h"
/**
* custom_getline - reads input from a file descriptor and stores it in a buffer.

* Return: NULL.
*/

char *custom_getline(void)
{
static char buf[BUFSIZE];
static char *bufp = buf;
int n = 0;
int i = 0;
char c, *line;

line = malloc(BUFSIZE);
if (!line)
{
return (NULL);
}
while (1)
{
if (n == 0)
{
n = read(STDIN_FILENO, buf, BUFSIZE);
if (n < 0)
{
free(line);
return (NULL);
}
else if (n == 0)
{
free(line);
return (NULL);
}
bufp = buf;
}
c = *bufp++;
n--;
if (c == '\n' || c == '\0')
{
line[i] = '\0';
return (line);
}
else
{
line[i++] = c;
}
if (i == BUFSIZE)
{
char *new_line = realloc(line, BUFSIZE + i);
if (!new_line)
{
free(line);
return (NULL);
}
line = new_line;
}}}
