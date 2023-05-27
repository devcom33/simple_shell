#include "main.h"
/**
 * _wifexited - ...
 * @status: status argument
 * Return: boolean
 */
bool _wifexited(int status)
{
	return ((status & 0x7F) == 0);
}
/**
 * _wexitstatus - a function that
 * @status: status argument
 * Return: integer
 */
int _wexitstatus(int status)
{
	return ((status >> 8) & 0xFF);

}
/**
 * runcmd - a function that run command
 * @rgv: rgv argument
 * @arv: arv argument
 * @envp: envp argument
 */
void runcmd(char **rgv, char **arv, char **envp)
{
	pid_t mychild, ter_child;
	int stat;
	/*denum *c = malloc(sizeof(struct denum));*/

	mychild = fork();

	if (mychild == -1)
	{
		perror("Process Error");
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
			exit(2);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
			ter_child = wait(&stat);
			if (ter_child == mychild)
			{
				if (_wifexited(stat))
				{
					exit(_wexitstatus(stat));
				}
				else
				{
					exit(2);
				}
			}
	}
}
