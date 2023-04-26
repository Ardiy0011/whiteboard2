# Simple UNIX Command Line Interpreter

This is a simple UNIX command line interpreter written in C. It provides a prompt where users can enter one-word commands, and executes those commands using the execlp function.

# Usage
To use the interpreter, compile the source files using the command make. Then, run the simple_shell program from the command line: 

## to run in interactive mode type command
**./hsh**

## to run in no interactive mode type command
**echo non_interactive_mode | ./hsh**


## Terminating the shell

**CTRL-D / CTRL-D**
In this make shift Unix-like systems, the interpreter will display a prompt, where you can enter one-word commands. Press Enter to execute the command. now to teminiate or exit the shell the **Ctrl-D** key combination that signals the end of input is used . When the user types Ctrl-D in the terminal, the shell interprets it as end-of-file and terminates the input.

In the context of the provided code, if the user enters a blank line or types Ctrl-D, the program will terminate the loop and exit the shell.

The prompt() function is called to display a prompt message for the user, indicating that the shell is ready to accept input. The prompt message typically includes the current working directory, the username, and other information that may be useful to the user.


## Implementation
The interpreter is implemented using a read_input function to read user input from the command line, and an execute_command function to execute commands using the execlp function. The execute_command function uses the fork function to create a child process, and the wait function to wait for the child process to finish executing.

**The execute_command()** function is a simplified version of execute_command_args() that does not accept any arguments. It simply calls execute_command_args() with a NULL argument for the array of arguments. This function is used for commands that do not require arguments, such as "cd" or "exit".


## task 1(split_parse_addarg)
- **The split_line()** function takes a command line as a parameter and uses the strtok() function to split it into individual tokens (arguments) based on whitespace characters. It then stores each token in an array of strings, which is dynamically resized if necessary. The function returns a pointer to this array of tokens.

This works along side the execute command function;

- **The execute_command_args()** function takes a command and an array of arguments as parameters and uses the fork() system call to create a new child process. The child process then uses the execvp() system call to execute the command with the given arguments. If the execution fails, an error message is printed to standard error. The parent process waits for the child process to terminate and returns the exit status of the command.

Nb:for non argumented shell commands refer to the **execute_command()** function above.

* task 2

an example of the usage of execute_command_args() function with the=
char *command = "ls";
char *args[] = { "-l", NULL };
execute_command_args(command, args);

* task 3


* task 4

the **int exit_shell(void)** function exits the program if the user enters the "exit" command.

## Overview 

This is a C program that implements a simple command-line shell. The program takes no command-line arguments, and the main function takes three unused parameters argc, argv, and envp.

The program enters a loop that repeatedly prompts the user for input, reads a line of input using the getline() function, and splits the input into an array of arguments using the split_line() function. The first argument is assumed to be the name of the command to execute, and the remaining arguments are passed as arguments to the command.

If the first argument is "exit", the program terminates by calling exit_shell() function that frees allocated memory before calling exit() function.

Otherwise, the execute_command_args() function is called to execute the command, passing the command name and the array of arguments as arguments. The status of the command is stored in the status variable.

After executing the command, the memory allocated for the arguments is freed using the free_args() function, and the loop continues.

Once the loop is exited, any remaining memory is freed, and the program terminates by returning 0.

