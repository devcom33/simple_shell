#include "main.h"
/**
 *
 */
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
