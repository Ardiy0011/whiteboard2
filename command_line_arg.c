#include "shell.h"
/**
 * execute_command_args - Executes a command with arguments in a new process.
 * @command: Pointer to a null-terminated string that contains the command.
 * @args: Array of null-terminated strings that contains the command arguments.
 * Return: Integer.
 */
int execute_command_args(char *command, char **args)
{
int i;
int num_args = 0;
char **argv;
char *path;
pid_t pid = fork();
if (pid == -1)
{
perror("fork failed");
return (-1);
}
else if (pid == 0)
{
while (args[num_args] != NULL)
{
num_args++;
}
argv = (char **) malloc((num_args + 2) * sizeof(char *));
argv[0] = command;
for (i = 0; i < num_args; i++)
{
argv[i + 1] = args[i];
}
argv[num_args + 1] = NULL;
path = get_command_path(command);
if (path == NULL)
{
fprintf(stderr, "Command '%s' not found\n", command);
exit(EXIT_FAILURE);
}
execv(path, argv);
perror("exec failed");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
else if (WIFSIGNALED(status))
{
fprintf(stderr, "Command '%s' terminated %d\n", command, WTERMSIG(status));
return (-1);
}
else
{
fprintf(stderr, "Command '%s' terminated unsually\n", command);
return (-1);
}}}


/**
 * get_command_path - Searches for the full path of a command.
 * @command: Pointer to a null-terminated string that contains the command.
 * Return: Pointer to a null-terminated string that contains the full path
 * of the command, or NULL if the command is not found.
 * This function searches for the full path of the command by executing the
 * 'which' command and capturing its output.
 */
char *get_command_path(char *command)
{

char *path = NULL;
char *dir;
char *full_path;

char *path_env = getenv("PATH");
if (path_env == NULL)
{
fprintf(stderr, "PATH environment variable not set\n");
return (NULL);
}

dir = strtok(path_env, ":");
while (dir != NULL)
{
full_path = malloc(strlen(dir) + strlen(command) + 2);
if (full_path == NULL)
{
perror("malloc failed");
return (NULL);
}
sprintf(full_path, "%s/%s", dir, command);

if (access(full_path, X_OK) == 0)
{
path = full_path;
break;
}
free(full_path);
dir = strtok(NULL, ":");
}
return (path);
}
