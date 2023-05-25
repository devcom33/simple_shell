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
	pid_t mychild;
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x, stat/*,path*/;
	denum *c = malloc(sizeof(struct denum));

	if (!c)
	{
		perror("allocation F");
		exit(EXIT_FAILURE);
	}
	c->cnt = 0;
	while (1)
	{
		c->cnt += 1;
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			write(STDOUT_FILENO, "\n", 1);
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
		/*handle_path(rgv, cmd);*/
		get_path(cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		/*runcmd(rgv, arv, cmd, c, envp); envir */
		mychild = fork();
		if (mychild == -1)
		{
			perror("Process Error");
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envp) == (-1))
			{
			/*write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
			write(STDOUT_FILENO, ": No such file or directory",
			_strlen(": No such file or directory"));
			write(STDOUT_FILENO, "\n", 1);*/
				geterror(c, arv, cmd);
			}
			exit(EXIT_FAILURE);

		/*if (cmd[0] == '/' || cmd[0] == '.')
			rgv[0] = rgv[0];
		else
			rgv[0] = get_path(cmd);
		*/
		}
		if (waitpid(mychild, &stat, 0) == -1)
		{
			perror("wait err");
			exit(EXIT_FAILURE);
		}

	}
	free(c);
	free(cmd);
}
