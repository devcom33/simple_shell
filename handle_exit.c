#include "main.h"
/**
 * handle_exit - function that terminate the prog when
 * user types "exit".
 * @cmd: the string to be read.
 * Return: nothing.
 *
 */
void handle_exit(char *cmd, int cm)
{
	if (_strcmp("exit", cmd) == 0)
	{
		free(cmd);
		if (cm == 1)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(2);
		}
	}
}
