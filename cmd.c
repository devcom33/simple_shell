#include "main.h"
/**
 * prompt - a shell using c
 * @arv: argument by user
 * @envp: envirement variable argument
 */
void prompt(char **arv, char **envp)
{
	size_t n;
	ssize_t num_c;
	char *cmd, *rgv[MAX_C];
	int x/*, stat,path*/;
	/*denum *c = malloc(sizeof(struct denum));*/

	/*cmd = malloc(sizeof(char) * MAX_C);*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_FAILURE);
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
	exit(EXIT_SUCCESS);
}
