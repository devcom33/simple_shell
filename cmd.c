#include "main.h"
/**
 * prompt - a shell using c
 * @arv: argument by user
 * @envp: envirement variable argument
 */
void prompt(char **arv, char **envp)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x/*, stat,path*/;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1] = '\0';
		cmd = trim(cmd);
		if (_strlen(cmd) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		handle_exit(cmd);
		handle_path(rgv, cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		runcmd(rgv, arv, envp); /* envp */
		/*c->cnt += 1;*/
	}
	free(cmd);
}
