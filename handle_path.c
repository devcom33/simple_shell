#include "main.h"
/**
 * handle_path - handle the path function
 * @rgv: rgv argument
 * @cmd: command set by the user
 */
char *handle_path(char **rgv, char *cmd)
{
	char *path;

	path = malloc(6);
	if (!path)
	{
		return (NULL);
	}
	_strcpy(path, "/bin/");

	if (cmd[0] != '/')
	{
		rgv[0] = _strcat(path, cmd);
		return (rgv[0]);
	}
	free(path);
	return (cmd);
}
