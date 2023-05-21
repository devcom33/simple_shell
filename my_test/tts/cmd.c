#include "main.h"
void prompt(int arc, char **envi)
{	
	pid_t = mychild;
	size_t n;
	ssize_t num_c;
	char *cmd = malloc(sizeof(char) * n);
	char *rgv[] = {NULL, NULL};
	int i = 0 , status;
	while (1)
	{	
		printf("$");
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{ 
			free(cmd);
			exit(EXIT_FAILURE);
		}
		while(cmd[i])
		{
			if (cmd[i] == '\n')
				cmd[i]= 0;
			i++;
		}
		rgv[0] = cmd;

		mychild = fork();
		if (mychild == -1)
		{
			free(cmd):
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envi) == -1)
			{
				/*perror("No such a file or directory")*/
				printf("%s No such a file or directory",arc[0]);
			}
		}
		else
			wait(&status);


	}
}

int main(int arc, char **arv, char **envi)
{
	size_t n;
        char *buf = malloc(sizeof(char) * n);
	pid_t pid;
	
	return (0);
}
