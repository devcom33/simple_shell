#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_C 10
/**
 * struct list_path - linked list that store paths
 * @direc: path of the directory
 * @next: point to the next node
 * Description: Singly Linked List that store paths
 */
typedef struct list_path
{
	char *direc;
	struct list_path *next;
} list_path;
void prompt(char **arv, char **envp);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void handle_path(char **rgv, char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void handle_exit(char *cmd);
void runcmd(char **rgv, char **arv, char **envp);
/*void search_path(char **rgv, char *cmd, char **envp);*/
#endif
