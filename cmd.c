#include "main.h"
/**
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
 */
void prompt(char **arv, char **envp)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x/*, stat,path*/;
	pid_t mychild;
	int stat;
	denum *c = malloc(sizeof(struct denum));

	while (1)
	{
		if (isatty(STDIN_FILENO))
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
		/*runcmd(rgv, arv, envp);*/ /* envp */
		c->cnt += 1;

		mychild = fork();
		if (mychild == -1)
		{
			perror("Process Error");
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envp) == -1)
			{
				/*write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
				write(STDOUT_FILENO, ": No such file or directory",
				_strlen(": No such file or directory"));
				write(STDOUT_FILENO, "\n", 1);*/
				geterror(c, arv, cmd);
			}
			exit(EXIT_SUCCESS);
		}
		else
			wait(&stat);

		}
		free(cmd);
}
