#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_C 10
/*int prompt(void);*/
void prompt(char **arv, char **envi);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void handle_path(char **rgv, char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void handle_exit(char *cmd);
int s_cmp(char *s1, char *s2);
#endif
