#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_C 10
/**
 * struct data_enum - structure that contains vars
 * @cnt: lines cnt
 */
typedef struct denum
{
	int cnt;
} denum;
void prompt(char **arv, char **envp);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void handle_path(char **rgv, char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void handle_exit(char *cmd);
void runcmd(char **rgv, char **arv, char *cmd, char **envp);
void geterror(int cnt, char **arv, char *cmd);
/*void search_path(char **rgv, char *cmd, char **envp);*/
#endif
