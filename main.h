#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#define MAX_C 20
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
/**
 * struct denum - structure that contains vars
 * @cnt: lines cnt
 */
typedef struct denum
{
	int cnt;
} denum;
void prompt(char **arv, char **envp, bool flg);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *handle_path(char **rgv, char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void handle_exit(char *cmd);
void runcmd(char **rgv, char **arv, char **envp);
char *trim(char *cmd);
char *_strncpy(char *dest, char *src, int n);
/*void geterror(int cnt, char **arv, char *cmd);*/
void geterror(denum *n, char **arv, char *cmd);
/*void search_path(char **rgv, char *cmd, char **envp);*/
char *get_path(char *cmd);
char *_getenv(char *name);
char **tokenize_env(char *path);
extern char **environ;
int _strncmp(char *str1, char *str2, int n);

/**
*
 *  * struct list_s - A new struct type defining a linked list.
 *   * @dir: A directory path.
 *    * @next: A pointer to another struct list_s.
 /
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;
char **_getenv(const char *var);
char *get_location(char *cmd);
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);
list_t *add_node_end(list_t **head, char *dir);
char *_strncat(char *dest, const char *src, size_t n);
**/
#endif
