#include "main.h"
/**
 * _strlen - length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
/**
 *  * _strcpy - copy a string
 *   * @dest: dest string arg
 *    * @src: source arg
 *     * Return: string value
 *      */
char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
	{
			len++;					        
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - unction that compares two strings
 * @s1: first function
 * @s2: second function
 * Return: val
 */
int _strcmp(char *s1, char *s2)
{
        int cmp = 0;

        while (*s1 == *s2 && *s1 != '\0')
        {
                s1++;
                s2++;
        }
	if (s1 != s2)
		cmp = *s1 - *s2;

        return (cmp);
}
/**
 * _strcat - This function appends the src string to the dest string
 * @dest: string agument
 * @src: string argument
 * Return: String
 */
char *_strcat(char *dest, char *src)
{
        int len = 0, lend = 0, j;

        while (src[len] != '\0')
        {
                len++;
        }
        while (dest[lend] != '\0')
        {
                lend++;
        }
        for (j = 0; j < len; j++)
        {
                dest[lend + j] = src[j];
        }
        dest[lend + len] = '\0';
        return (dest);
}
void handle_path(char **rgv, char *cmd)
{
	char *path;
	path = malloc(6);

	_strcpy(path, "/bin/");

	if (cmd[0] != '/')
	{
               rgv[0] = _strcat(path, cmd);
	}
}
void prompt(char **arv, char **envi)
{	
	pid_t mychild;
	size_t n;
	ssize_t num_c;
	/*char *cmd = malloc(sizeof(char) * n);*/
	char *cmd = NULL;
	char *rgv[MAX_C];
	int i = 0, x, stat/*,path*/;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO,"$ ", 2);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{ 
			free(cmd);
			exit(EXIT_FAILURE);
		}
		while(cmd[i])
		{
			if (cmd[i] == '\n')
				cmd[i]= '\0';
			i++;
		}
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		handle_path(rgv, cmd);
		while (rgv[x])
		{	
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		mychild = fork();
		if (mychild == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envi) == -1)
			{
				write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
				write(STDOUT_FILENO, " :No such a file or directory", _strlen(":No such a file or directory"));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
			wait(&stat);
	}
	free(cmd), exit(EXIT_SUCCESS);
}

int main(int arc, char **arv, char **envi)
{
	if (arc == 1)
	{
		prompt(arv, envi);
	}	
	return (0);
}
