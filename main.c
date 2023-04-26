#include "shell.h"
/**
 * main - The entry point of the program.
 * @argc: the number of arguments passed to the program from the command line,
 * including the name of the program itself.
 * @argv: an array of strings containing the arguments passed to the program
 * from the command line.
 */
int main(int argc, char **argv)
{
char *input;
char **args;
int status;
FILE *input_stream = stdin;
if (argc > 1) {
input_stream = fopen(argv[1], "r");
if (!input_stream) {
perror("Failed to open input file");
exit(EXIT_FAILURE);
}
}
while (1)
{
if (input_stream == stdin)
{
prompt();
input = read_input();
}
else
{
input = read_input_from_stream(input_stream);
if (input == NULL)
{
break;
}
printf("%s", input);
}
args = split_line(input);
status = execute_command(args);
free(input);
free_args(args);
if (status == -1)
{
break;
}
}
if (input_stream != stdin)
{
fclose(input_stream);
}
return (0);
}
