#include "shell.h"
/**
* execute_command - Executes a command in a new process.
* @args: An array of strings containing the command and its arguments.
* Return: Integer.
*/
int execute_command(char **args)
{
int status;
pid_t pid;

if (args[0] == NULL)
{
return (1);
}
if (strcmp(args[0], "cd") == 0)
{
if (args[1] == NULL)
{
fprintf(stderr, "expected argument to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("cd failed");
}}
return (1);
}
if (strcmp(args[0], "exit") == 0)
{
exit_shell(NULL, args, stdin);
}
switch (pid = fork())
{
case -1:
perror("fork failed");
return (-1);
case 0:
if (execvp(args[0], args) == -1)
{
perror("exec failed");
exit(EXIT_FAILURE);
}
break;
default:
while (wait(&status) != pid)
;
break;
}
return (1);
}
