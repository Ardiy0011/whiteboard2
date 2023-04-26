#include "shell.h"
/**
 * custom_atoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The converted integer.
 */
int custom_atoi(const char *string)
{
int sign = 1;
int num = 0;

while (*string == ' ' || (*string >= '\t' && *string <= '\r'))
string++;

switch (*string)
{
case '-':
sign = -1;
string++;
break;

case '+':
string++;
break;
default:
break;
}

while (*string >= '0' && *string <= '9')
{
num = num * 10 + (*string - '0');
string++;
}

return (sign * num);
}
