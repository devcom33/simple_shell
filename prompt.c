#include "main.h"
/**
 * prompt - create a custom shell
 * Return: 0
 */
int prompt(void)
{
	pid_t my_pid;
	char *input = NULL;
	size_t bsize = 100;
	char *arg[] = {input, NULL};
	int status;
	char *prompt = "#cisfun$ ";
	int len;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 9);

		if ((len = getline(&input, &bsize, stdin)) == -1)
			break;
		input[len - 1] = '\0';
		my_pid = fork();

		if (my_pid < 0)
		{
			perror("Process Error");
			exit(98);
		}
		else if (my_pid == 0)
		{
			if (execve(input, arg, NULL) == -1)
			{
				perror("./shell: No such file or directory");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
