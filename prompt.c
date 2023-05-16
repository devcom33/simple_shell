#include "main.h"

int prompt(void)
{
	pid_t my_pid;
	char input[100];
	char *arg[] = {"/bin/ls", NULL};
	int status;

	printf("#cisfun$ ");
	while (fgets(input, 100, stdin) != NULL)
	{
		input[strcspn(input, "\n")] = '\0';
		my_pid = fork();
		if (my_pid < 0)
		{
			perror("Error");
			return (1);
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
		printf("#cisfun$ ");
	}
	return (0);
}
