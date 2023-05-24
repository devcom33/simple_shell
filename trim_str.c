#include "main.h"
/**
 */
char *trim(char *cmd)
{
	char *cpcmd;
	int i = 0, len;

	while (cmd[i] == ' ')
		i++;
	len = _strlen(cmd) - i + 1;
	cpcmd = malloc(len);
	if (!cpcmd)
	{
		perror("Allocation Failed\n");
		exit(EXIT_FAILURE);
	}
	_strncpy(cpcmd, cmd + i, len);

	return (cpcmd);
}
