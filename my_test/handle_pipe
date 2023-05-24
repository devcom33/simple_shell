#include "main.h"

void handle_pipe(char* cmd) {
    char* token;
    char* trimmed_command;
    /*char* commands[MAX_C];*/
    char** commands = malloc(20 * sizeof(char*));
    size_t len; /* Assuming maximum two commands in the pipeline*/
    int i, pid, fd[2];
    /* Tokenize the command based on the pipe delimiter*/ 
    token = strtok(cmd, "|");
    commands[0] = token;
    token = strtok(NULL, "|");
    commands[1] = token;

    /* Trim leading and trailing whitespaces from the commands*/
    for (i = 0; i < 2; i++)
    {
        if (commands[i] != NULL)
	{
	    trimmed_command = commands[i];
            while (*trimmed_command == ' ')
	    {
                trimmed_command++;
            }
	    len = strlen(trimmed_command);
            while (len > 0 && trimmed_command[len - 1] == ' ')
	    {
                trimmed_command[--len] = '\0';
            }
            commands[i] = trimmed_command;
        }
    }

   
    if (pipe(fd) == -1)
    {
       	free(cmd);
	perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        free(cmd);
	perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0)
    {
        /* Child process: execute the first command and write to pipe*/
        close(fd[0]);  /*Close the read end of the pipe*/
        dup2(fd[1], STDOUT_FILENO);  /*Redirect stdout to the pipe*/
        close(fd[1]);  /*Close the write end of the pipe*/
        system(commands[0]);  /* Execute the first command*/
	free(cmd);
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        /* Parent process: execute the second command and read from pipe*/
        close(fd[1]);  /* Close the write end of the pipe*/
        dup2(fd[0], STDIN_FILENO);  /*Redirect stdin to the pipe*/
        close(fd[0]);  /* Close the read end of the pipe*/
        system(commands[1]);  /* Execute the second command*/
    }
    free(cmd), exit(EXIT_SUCCESS);
}
