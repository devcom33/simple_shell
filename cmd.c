#include "main.h"
/**
 * sig_handler - handler cntrl c
 * @num: num argument
 */
void sig_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
}
/**
 * prompt - a shell using c
 * @arv: argument by user
 * @envp: envirement variable argument
 * @flg: flag argument for mode
 */
void prompt(char **arv, char **envp, bool flg)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x/*, stat,path*/;
	char *pipe_cmd, *trim_cmd;

	while (1)
	{
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1] = '\0';
		pipe_cmd = strtok(cmd, "|");
		while (pipe_cmd != NULL)
		{
			trim_cmd = trim(cmd);
			if (_strlen(trim_cmd) != 0)
			{
				x = 0;
				rgv[x] = strtok(trim_cmd, " \n");
				handle_exit(rgv[x]);
				handle_path(rgv, rgv[x]);
				while (rgv[x])
				{
					x++;
					rgv[x] = strtok(NULL, " \n");
				}
				runcmd(rgv, arv, envp); /* envir */
			}
			pipe_cmd = strtok(NULL, "|");
		}
	}
	free(pipe_cmd);
	free(cmd);
}
