#include "main.h"
/**
 * trim - remove space
 * @cmd: comand
 * Return: cmmand
 */
char *trim(char *cmd)
{
	char *cpcmd;
	int i = 0, len;

	while (cmd[i] == ' ')
		i++;
	len = _strlen(cmd) - i + 1;
	cpcmd = malloc(len + 1);
	if (!cpcmd)
	{
		perror("Allocation Failed\n");
		free(cpcmd);
		exit(EXIT_FAILURE);
	}
	_strncpy(cpcmd, cmd + i, len);
	free(cmd);

	return (cpcmd);
}
