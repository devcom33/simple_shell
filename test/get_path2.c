#include "main.h"
char *get_path(char *cmd);
char *_getenv(char *name);
char **tokenize_env(char *path);

/**
  * tokenize_env - Tokenize the PATH to return a list of folders
  * @path: The path string to cnvert to an array
  * Return: An array of the directories
  */

char **tokenize_env(char *path)
{
	char *path_copy = path;
	int i = 0;
	char *token;
	static char *arr[20] = {NULL};

	if (path == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, ":");
	}
	return (arr);
}

/**
 * _getenv - finds the environment variable requested by user
 * @name: environment variable requested by user
 * Return: value of the environment variable
 */

char *_getenv(char *name)
{
	int i, len;

	len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0)
			return (environ[i] + len + 1);
	}
	return (NULL);
}
/**
  * get_path - a func that gives the full path of the command given
  * @command: command to be finding its full path.
  * Return: The full path if not NULL..
  */

char *get_path(char *cmd)
{
	struct stat st;
	int i;
	char *path = _getenv("PATH");
	char **dirs = tokenize_env(path);
	/*char *cmd_ = cmd;*/
	char *fullpath = malloc(sizeof(char) * 1024);

	if (fullpath == NULL)
		return (NULL);

	for (i = 0; dirs[i]; i++)
	{
		fullpath[0] = 0;
		_strcat(fullpath, dirs[i]);
		_strcat(fullpath, "/");
		_strcat(fullpath, cmd);
		if (stat(fullpath, &st) == 0)
			return (fullpath);

	}
	free(fullpath);
	return (NULL);
}
