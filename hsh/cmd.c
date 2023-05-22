#include "main.h"
/**
 */
void prompt(char **arv, char **envi)
{
	pid_t mychild;
	size_t n;
	ssize_t num_c;
	char *cmd;
	char *rgv[MAX_C];
	int x, stat/*,path*/;

	cmd = malloc(sizeof(char) * MAX_C);
	if (!cmd)
		return;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO,"$ ", 2);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1]= '\0';
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		handle_exit(cmd);
		handle_path(rgv, cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		mychild = fork();
		if (mychild == -1)
		{
			perror("Process Error");
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envi) == -1)
			{
				write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
				write(STDOUT_FILENO, " :No such a file or directory", _strlen(" :No such a file or directory"));
				write(STDOUT_FILENO, "\n", 1);
			}
			exit(EXIT_FAILURE);
		}
		else
			wait(&stat);
	}
}
