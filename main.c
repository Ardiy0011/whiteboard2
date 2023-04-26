#include "shell.h"
/**
 * main - The entry point of the program.
 * @argc: the number of arguments passed to the program from the command line,
 * including the name of the program itself.
 * @argv: an array of strings containing the arguments passed to the program
 * from the command line.
 * @env: a pointer to an array of strings representing the environment variables.
 * Return: Integer.
 * Description: This function is the main entry point for the simple shell program.
 */
int main(int argc, char **argv, char **env)
{
info_t info = {0};

info.argv = argv;
info.env = NULL;
populate_env_list(&info);
FILE *input_stream = NULL;
if (isatty(STDIN_FILENO))
{
input_stream = stdin;
}
else
{
input_stream = fopen(argv[1], "r");
if (input_stream == NULL)
{
perror("failed to open file");
exit(EXIT_FAILURE);
}}
while (1)
{
printf("$ ");
char *line = NULL;
size_t len = 0;
ssize_t read = getline(&line, &len, input_stream);
if (read == -1)
{
free(line);
break;
}
tokenize(&info, line);
if (info.argv[0])
{
if (strcmp(info.argv[0], "exit") == 0)
break;
else if (strcmp(info.argv[0], "env") == 0)
print_environment();
else if (strcmp(info.argv[0], "setenv") == 0)
_mysetenv(&info);
else if (strcmp(info.argv[0], "unsetenv") == 0)
_myunsetenv(&info);
else
execute(&info);
}
free(info.argv);
free(line);
}
free_list(&info.env);
if (!isatty(STDIN_FILENO))
{
fclose(input_stream);
}
return (0);
}
