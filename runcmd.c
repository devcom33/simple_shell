#include "main.h"
/**
 * runcmd - a function that run command
 * @rgv: rgv argument
 * @arv: arv argument
 * @envp: envp argument
 */
void runcmd(char **rgv, char **arv, char **envp)
{
	pid_t mychild;
	int stat;

	mychild = fork();
		/*runcmd(rgv,arv,envp);*/
		if (mychild == -1)
		{
			perror("Process Error");
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envp) == -1)
			{
				write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
				write(STDOUT_FILENO, " :No such a file or directory",
				_strlen(" :No such a file or directory"));
				write(STDOUT_FILENO, "\n", 1);
			}
			exit(EXIT_FAILURE);
		}
		else
			wait(&stat);
}
