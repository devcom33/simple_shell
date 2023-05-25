#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_pipe(char* cmd) {
    char* token;
    char** commands;
    int num_commands = 0;
    int** pipes;
    int i, pid;
    size_t len;
    char* trimmed_command;
    /* Tokenize the command based on the pipe delimiter |*/
    commands = malloc(sizeof(char*));
    token = strtok(cmd, "|");
    while (token != NULL) {
        commands = realloc(commands, (num_commands + 1) * sizeof(char*));
        commands[num_commands] = strdup(token);
        num_commands++;
        token = strtok(NULL, "|");
    }

    
    for (i = 0; i < num_commands; i++) {
        trimmed_command = commands[i];
        while (*trimmed_command == ' ') {
            trimmed_command++;
        }
        len = strlen(trimmed_command);
        while (len > 0 && trimmed_command[len - 1] == ' ') {
            trimmed_command[--len] = '\0';
        }
        commands[i] = trimmed_command;
    }

    
    pipes = malloc((num_commands - 1) * sizeof(int*));
    for (i = 0; i < num_commands - 1; i++) {
        pipes[i] = malloc(2 * sizeof(int));
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_commands; i++) {
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process*/
            if (i > 0) {
                /*Redirect input from the previous pipe*/
                close(pipes[i - 1][1]);
                dup2(pipes[i - 1][0], STDIN_FILENO);
                close(pipes[i - 1][0]);
            }
            if (i < num_commands - 1) {
                /*Redirect output to the next pipe*/
                close(pipes[i][0]);
                dup2(pipes[i][1], STDOUT_FILENO);
                close(pipes[i][1]);
            }
            system(commands[i]); /* Execute the command*/
            exit(EXIT_SUCCESS);
        }
    }

    /* Close all pipe ends in the parent process*/
    for (i = 0; i < num_commands - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    /*Wait for all child processes to finish*/
    for (i = 0; i < num_commands; i++) {
        wait(NULL);
    }

    /* Free allocated memory*/
    for (i = 0; i < num_commands - 1; i++) {
        free(pipes[i]);
    }
    free(pipes);
    for (i = 0; i < num_commands; i++) {
        free(commands[i]);
    }
    free(commands);
}

