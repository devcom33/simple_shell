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
	/*denum *c = malloc(sizeof(struct denum));*/

	mychild = fork();

	if (mychild == -1)
	{
		perror("Process Error");
		/*exit(EXIT_FAILURE);*/
		exit(2);
	}
	if (mychild == 0)
	{

		if (execve(rgv[0], rgv, envp) == (-1))
		{
			write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
			write(STDOUT_FILENO, ": No such file or directory",
			_strlen(": No such file or directory"));
			write(STDOUT_FILENO, "\n", 1);
			/*geterror(c -> cnt, arv, cmd);*/
		}
		/*exit(EXIT_FAILURE);*/
		 exit(2);
	}
	else
	{
		wait(&stat);
	}
}
